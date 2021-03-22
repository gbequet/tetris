#include "game.h"
#include <SDL.h>
#include <string>
#include <memory>
#include <iostream>
#include <random>
#include <cmath>

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
    : frameID_(0), lastMove_(0), lastRotate_(0), pos_cur_bloc(4,0),
    window_(nullptr), planche_(nullptr), sprites_()
{
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
    sprites_.emplace_back(new Sprite(planche_, 0, 0, 21, 21));
    // bloc rouge
    sprites_.emplace_back(new Sprite(planche_, 20, 0, 21, 21));
    // bloc bleu
    sprites_.emplace_back(new Sprite(planche_, 40, 0, 21, 21));
}

void Game::finalize()
{
    // TODO
}

void Game::keyboard(const std::uint8_t *keys)
{
    if (frameID_ - lastMove_ > 100) // ca evite d'aller trop vite ( enleve la condition tu verras haha ;) )
    {
        if (keys[SDL_SCANCODE_LEFT]){
            int x = current_bloc_->getPositionX();
            current_bloc_->setPositionX(x - 21);
            lastMove_ = frameID_;
        }

        if (keys[SDL_SCANCODE_RIGHT]){
            int x = current_bloc_->getPositionX();
            current_bloc_->setPositionX(x + 21);
            lastMove_ = frameID_;
        }
    }

    if (keys[SDL_SCANCODE_R])
    {
        if (frameID_ - lastRotate_ > 100)
        {
            int r = current_bloc_->getCurTile();
            current_bloc_->setCurTile((r + 1) % 4);
            lastRotate_ = frameID_;
        }
    }
}

void Game::draw(double dt)
{
    Sprite *sCarreau = sprites_[0];

    for (int j = 0, h = 0; h <= 20; j += sCarreau->height(), h++)
    {
        for (int i = 0, w = 0; w <= 10; i += sCarreau->width(), w++)
        {
            window_->draw(*sCarreau, i, j);
        }
    }

    Sprite *sBloc = sprites_[1];

    {
        static bool is_shape_initialized = false;
        if (!is_shape_initialized)
        {
            current_bloc_ = new ShapeT(5*21, 0);

            is_shape_initialized = true;
        }
        int rotation = current_bloc_->getCurTile();
        const GraphicsObject::TShape &shapeTiles = current_bloc_->tiles_[rotation] /*current rotation ID*/;
        for (const auto &p : shapeTiles)
        {
            const int x = current_bloc_->getPositionX();
            const int y = current_bloc_->getPositionY();

            const int tileSize = sBloc->height();
            window_->draw(*sBloc, x + p.first * tileSize, y + p.second * tileSize);
        }
        frameID_++;
        if ((frameID_ % 150 == 0))
        {
            if (maj_presenceGrille(0) == true)
                current_bloc_->setPositionY(current_bloc_->getPositionY() + sBloc->height());
        }
    }
}

/*
    - Checker si le deplacement est possible
    - Mettre a jour pos_cur_bloc
    - Mettre a jour presenceGrille_
    C'est juste une idée je ne sais pas si elle est bonne hl ;)

    situation = pourquoi on met a jour la grille? ( quel deplacement? )
    0 -> gravité
    1 -> deplacement gauche
    2 -> deplacement droite
    3 -> rotation

    Renvoie true si le deplacement à pu se faire false sinon
*/
bool Game::maj_presenceGrille(int situation)
{
    bool res = true;

    switch (situation)
    {
        // gravité
        case 0:
            break;

        // gauche
        case 1:
            break;

        // droite
        case 2:
            break;

        // rotation
        // plus compliqué pcq ca depend de la shape
        // TODO
        case 3:
            break;
        
        default:
            break;
    }

    return res;
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
