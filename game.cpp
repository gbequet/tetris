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
    : frameID_(0), 
    lastMove_(0), 
    lastGravity_(0), 
    lastDown_(0), 
    lastRotate_(0), 
    pos_cur_bloc(NB_COL / 2, 0), 
    need_new_bloc_(true), 
    indice_color_(0), 
    largeur_carre_(21),
    window_(nullptr), 
    planche_(nullptr), 
    compteurPoints(0),
    sprites_()
{
    // initialisation presenceGrille_
    for (size_t i = 0; i < NB_COL; i++)
    {
        for (size_t j = 0; j < NB_ROWS; j++)
        {
            presenceGrille_[i][j] = 0;
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
    window_ = new Window("TETRIS", 800, 600);
    window_->initialize();

    planche_ = new Surface();
    const std::string image = "./spritescopie.bmp";
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
    // bloc bleu clair
    // sprites_.emplace_back(new Sprite(planche_, 140, 0, largeur_carre_, largeur_carre_));
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

    if (keys[SDL_SCANCODE_DOWN])
    {
        if (frameID_ - lastDown_ > 35)
        {
            if (!check_collision(0))
            {
                current_bloc_->setPositionY(current_bloc_->getPositionY() + largeur_carre_);
                lastDown_ = frameID_;
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
    for (int i = 0, h = 0; i < NB_COL; h += largeur_carre_, i++)
    {
        for (int j = 0, w = 0; j < NB_ROWS; w += largeur_carre_, j++)
        {
            int color = presenceGrille_[i][j];
            window_->draw(*sprites_[color], h, w);
        }
    }

    // Si besoin d'un nouveau bloc
    if (need_new_bloc_)
    {
        // on tire une couleur au hasard ( entre 1 et 6 )
        srand(time(0));
        indice_color_ = (std::rand()%6) + 1;

        // on initialise un nouveau bloc ( 5*largeur_carre_ pour qu'il soit au milieu )
        int indice_shape = (std::rand()%7); // ( 0=T ; 1=Z ; 2=I ; 3=O ; 4=L ; 5=J: 6=S)

        switch (indice_shape)
        {
        case 0:
            current_bloc_ = new ShapeT(5 * largeur_carre_, 0);
            break;

        case 1:
            current_bloc_ = new ShapeZ(5 * largeur_carre_, 0);
            break;

        case 2:
            current_bloc_ = new ShapeI(5 * largeur_carre_, 0);
            break;

        case 3:
            current_bloc_ = new ShapeO(5 * largeur_carre_, 0);
            break;

        case 4:
            current_bloc_ = new ShapeL(5 * largeur_carre_, 0);
            break;
        
        case 5:
            current_bloc_ = new ShapeJ(5 * largeur_carre_, 0);
            break;

        case 6:
            current_bloc_ = new ShapeS(5 * largeur_carre_, 0);
            break;
        
        default:
            break;
        }

        // on (re)initialise sa position
        std::get<0>(pos_cur_bloc) = NB_COL/2;
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

                presenceGrille_[i][j] = indice_color_;
            }

            update_presenceGrille();

            if(GameOver()){
                printf("Fini!\n");
                exit(2);
            } 

            need_new_bloc_ = true; // on demande un nouveau bloc
        }

        lastGravity_ = frameID_;
    }
}

void Game::update_presenceGrille()
{
    bool rempli;
    for (int i = 0; i < NB_ROWS; i++)
    {
        rempli = true;

        for (int j = 0; j < NB_COL; j++)
        {
            if (presenceGrille_[j][i] == 0)
                rempli = false;
        }

        if (rempli)
        {
            clear_line(i);
            compteurPoints++;
            printf("Points: %d\n", compteurPoints);
            make_bloc_fall(i);
        }

        rempli = true;
    }
}

void Game::clear_line(int i)
{
    for (int j = 0; j < NB_COL; j++)
    {
        presenceGrille_[j][i] = 0;
    }
}

void Game::make_bloc_fall(int a)
{
    for (int i = a; i > 0; --i)
    {
        for (int j = 0; j < NB_COL; ++j)
        {
            presenceGrille_[j][i] = presenceGrille_[j][i-1];
            // if (!check_collision(0)) // on le fait descendre
            // {
            //     current_bloc_->setPositionY(current_bloc_->getPositionY() + largeur_carre_);
            // }
        }
    }
}

bool Game::GameOver(){
    for(int i = 4; i <= 7; i++ ){
        if(presenceGrille_[i][0] == 1) {
            return true;
        }
    }
    return false;
}

/*
    TODO verifier si collision avec bloc deja present
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
    const GraphicsObject::TShape &tmpTiles = current_bloc_->tiles_[(rotation + 1) % 4]; // Shape si rotation

    int futur_posX;
    int futur_posY;

    switch (situation)
    {
    // gravité
    case 0:
        for (const auto &p : shapeTiles)
        {
            futur_posX = p.first + std::get<0>(pos_cur_bloc);
            futur_posY = p.second + std::get<1>(pos_cur_bloc) + 1;
            if (futur_posY >= NB_ROWS)
                return true;
            if (presenceGrille_[futur_posX][futur_posY] != 0)
                return true;
        }
        std::get<1>(pos_cur_bloc) += 1;
        break;

    // gauche
    case 1:
        for (const auto &p : shapeTiles)
        {
            futur_posX = p.first + std::get<0>(pos_cur_bloc) - 1;
            futur_posY = p.second + std::get<1>(pos_cur_bloc);
            if (futur_posX < 0)
                return true;
            if (presenceGrille_[futur_posX][futur_posY] != 0)
                return true;
        }
        std::get<0>(pos_cur_bloc) -= 1;
        break;

    // droite
    case 2:
        for (const auto &p : shapeTiles)
        {
            futur_posX = p.first + std::get<0>(pos_cur_bloc) + 1;
            futur_posY = p.second + std::get<1>(pos_cur_bloc);
            if (futur_posX >= NB_COL)
                return true;
            if (presenceGrille_[futur_posX][futur_posY] != 0)
                return true;
        }
        std::get<0>(pos_cur_bloc) += 1;
        break;

    // rotation
    case 3:
        for (const auto &p : tmpTiles)
        {
            if ((p.first + std::get<0>(pos_cur_bloc) >= NB_COL) || (p.first + std::get<0>(pos_cur_bloc) < 0) || (p.second + std::get<1>(pos_cur_bloc) >= NB_ROWS))
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
