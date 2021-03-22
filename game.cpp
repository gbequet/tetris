#include "game.h"
#include <SDL.h>
#include <string>
#include <memory>
#include <iostream>
#include <random>
#include <cmath>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "window.h"
#include "surface.h"
#include "sprite.h"
#include "GraphicsObject.h"
#include "Shapes.h"

using namespace Shapes;

//////////
// Game //
//////////

Game::Game()
    : frameID_(0), lastMove_(0), lastGravity_(0), lastRotate_(0), pos_cur_bloc(6, 0), need_new_bloc_(true), indice_color_(0), largeur_carre_(21),
      window_(nullptr), planche_(nullptr), sprites_()
{
    // initialisation presenceGrille_
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            std::get<0>(presenceGrille_[i][j]) = false;
            std::get<1>(presenceGrille_[i][j]) = 0;
        }
    }
}

Game::~Game()
{
    for (auto sprite : sprites_)
    {
        delete sprite;
        sprite = nullptr;
    }
    sprites_.clear();

    delete planche_;
    planche_ = nullptr;

    delete window_;
    window_ = nullptr;
}

void Game::initialize()
{
    window_ = new Window("GAME", 800, 800);
    window_->initialize();

    planche_ = new Surface();
    const std::string image = "./sprites.bmp";
    planche_->load(image.c_str());

    // Initialize sprites
    // carreaux de la grille
    sprites_.emplace_back(new Sprite(planche_, 0, 0, largeur_carre_, largeur_carre_));
    // bloc rouge
    sprites_.emplace_back(new Sprite(planche_, 20, 0, largeur_carre_, largeur_carre_));
    // bloc orange
    sprites_.emplace_back(new Sprite(planche_, 40, 0, largeur_carre_, largeur_carre_));
    // bloc jaune
    sprites_.emplace_back(new Sprite(planche_, 60, 0, largeur_carre_, largeur_carre_));
    // bloc vert
    sprites_.emplace_back(new Sprite(planche_, 80, 0, largeur_carre_, largeur_carre_));
    // bloc bleu
    sprites_.emplace_back(new Sprite(planche_, 100, 0, largeur_carre_, largeur_carre_));
    // bloc mauve
    sprites_.emplace_back(new Sprite(planche_, 120, 0, largeur_carre_, largeur_carre_));
}

void Game::finalize()
{
    // TODO
}

void Game::keyboard(const std::uint8_t *keys)
{
    if (frameID_ - lastMove_ > 50) // ca evite d'aller trop vite ( enleve la condition tu verras haha ;) )
    {
        if (keys[SDL_SCANCODE_LEFT]){
            if (!check_collision(1))
            {
                int x = current_bloc_->getPositionX();
                current_bloc_->setPositionX(x - largeur_carre_);
                lastMove_ = frameID_;
            }
        }

        if (keys[SDL_SCANCODE_RIGHT])
        {
            if (!check_collision(2))
            {
                int x = current_bloc_->getPositionX();
                current_bloc_->setPositionX(x + largeur_carre_);
                lastMove_ = frameID_;
            }
        }
    }

    if (keys[SDL_SCANCODE_R])
    {
        if (frameID_ - lastRotate_ > 50)
        {
            if (!check_collision(3))
            {
                int r = current_bloc_->getCurTile();
                current_bloc_->setCurTile((r + 1) % 4);
                lastRotate_ = frameID_;
            }
        }
    }
}

void Game::draw(double dt)
{
    // affichage grille + blocs deja fini
    for (int i = 0, h = 0; i < 20; h += largeur_carre_, i++)
    {
        for (int j = 0, w = 0; j < 10; w += largeur_carre_, j++)
        {
            // !!!! Le probleme vient de la je pense
            int color = std::get<1>(presenceGrille_[i][j]);
            window_->draw(*sprites_[color], w, h);
        }
    }

    // Si besoin d'un nouveau bloc
    if (need_new_bloc_)
    {
        // on tire une couleur au hasard ( entre 1 et 6 )
        srand(time(0));
        indice_color_ = (std::rand()%6) + 1;

        // on initialise un nouveau bloc ( 5*largeur_carre_ pour qu'il soit au milieu )
        // TODO faire que ce soit une forme au hasard
        current_bloc_ = new ShapeT(5 * largeur_carre_, 0);

        // on (re)initialise sa position
        std::get<0>(pos_cur_bloc) = 6;
        std::get<1>(pos_cur_bloc) = 0;

        need_new_bloc_ = false;
    }

    // affichage du bloc courant
    int rotation = current_bloc_->getCurTile();
    const GraphicsObject::TShape &shapeTiles = current_bloc_->tiles_[rotation];

    for (const auto &p : shapeTiles)
    {
        const int x = current_bloc_->getPositionX();
        const int y = current_bloc_->getPositionY();

        const int tileSize = sprites_[indice_color_]->height();
        window_->draw(*sprites_[indice_color_], x + p.first * tileSize, y + p.second * tileSize);
    }

    frameID_++;


    // gravité
    if (frameID_ - lastGravity_ > 100)
    {
        if (!check_collision(0)) // on le fait descendre
        {
            current_bloc_->setPositionY(current_bloc_->getPositionY() + largeur_carre_);
        }
        else // il a atteint le fond ou a atteri sur un ancien bloc => on en envoi un nouveau
        {
            // on met a jour presenceGrille_
            for (const auto &p : shapeTiles)
            {
                int i = p.first + std::get<0>(pos_cur_bloc);
                int j = p.second + std::get<1>(pos_cur_bloc);

                // !!!! l'erreur peut aussi venir de là
                std::get<0>(presenceGrille_[i][j]) = true;
                std::get<1>(presenceGrille_[i][j]) = indice_color_;
            }

            need_new_bloc_ = true; // on demande un nouveau bloc
        }

        lastGravity_ = frameID_;
    }
}

/*
    - Checker si le deplacement est possible
    - Mettre a jour pos_cur_bloc

    situation = pourquoi on met a jour la grille? ( quel deplacement? )
    0 -> gravité
    1 -> deplacement gauche
    2 -> deplacement droite
    3 -> rotation

    Effet de bord : met a jour pos_cur_bloc
    Renvoie true si il y'aurait une collision, false sinon
*/
bool Game::check_collision(int situation)
{
    int rotation = current_bloc_->getCurTile();
    const GraphicsObject::TShape &shapeTiles = current_bloc_->tiles_[rotation];
    const GraphicsObject::TShape &tmpTiles = current_bloc_->tiles_[(rotation + 1) % 4]; // Shapes si rotation

    switch (situation)
    {
    // gravité
    case 0:
        for (const auto &p : shapeTiles)
        {
            if (p.second + std::get<1>(pos_cur_bloc) + 1 >= 20)
                return true;
        }
        std::get<1>(pos_cur_bloc) += 1;
        break;

    // gauche
    case 1:
        for (const auto &p : shapeTiles)
        {
            if (p.first + std::get<0>(pos_cur_bloc) - 1 <= 0)
                return true;
        }
        std::get<0>(pos_cur_bloc) -= 1;
        break;

    // droite
    case 2:
        for (const auto &p : shapeTiles)
        {
            if (p.first + std::get<0>(pos_cur_bloc) + 1 > 10)
                return true;
        }
        std::get<0>(pos_cur_bloc) += 1;
        break;

    // rotation
    case 3:
        for (const auto &p : tmpTiles)
        {
            if ((p.first + std::get<0>(pos_cur_bloc) > 10) || (p.first + std::get<0>(pos_cur_bloc) <= 0) || (p.second + std::get<1>(pos_cur_bloc) >= 20))
                return true;
        }
        break;

    default:
        break;
    }

    return false;
}

void Game::loop()
{
    Uint64 now = SDL_GetPerformanceCounter(); // timers
    Uint64 prev = now;

    bool quit = false;
    while (!quit)
    {
        // Event management
        SDL_Event event;
        while (!quit && SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }

        // Keyboard management
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        keyboard(state);
        quit |= state[SDL_SCANCODE_ESCAPE];

        // Rendering stage
        prev = now;
        now = SDL_GetPerformanceCounter();
        double delta_t = (double)((now - prev) / (double)SDL_GetPerformanceFrequency());
        draw(delta_t);

        // Update window (refresh)
        window_->update();
    }
}
