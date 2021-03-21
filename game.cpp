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

using namespace Graphics;

//////////////////////////////////////////////////////////////////////////////////////////
// shape T
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeT : public GraphicsObject
{
public:
    static ShapeT *create();
    static ShapeT *create(int x, int y);
    virtual ~ShapeT();

protected:
    ShapeT();
    ShapeT(int x, int y);

private:
    int current_tile_;
};

ShapeT *ShapeT::create()
{
    return new ShapeT();
}

ShapeT *ShapeT::create(int x, int y)
{
    return new ShapeT(x, y);
}

ShapeT::ShapeT()
    : GraphicsObject()
{
    tiles_.resize(4 /*nb rotations*/);
    // shape : T
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1)};
    tiles_[1] = {std::make_pair(-1, 1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2), std::make_pair(1, 1)};
}

ShapeT::ShapeT(int x, int y)
    : GraphicsObject(x,y)
{
    tiles_.resize(4 /*nb rotations*/);
    // shape : I
    tiles_[0] = {std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1)};
    tiles_[1] = {std::make_pair(-1, 1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)};
    tiles_[2] = {std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1)};
    tiles_[3] = {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2), std::make_pair(1, 1)};
}
ShapeT::~ShapeT()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
// Game
//////////////////////////////////////////////////////////////////////////////////////////

Game::Game()
    : window_(nullptr), planche_(nullptr), sprites_(), balls_()
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
    // const std::string image = "./sprites.bmp";
    const std::string image = "./sprites.bmp";
    planche_->load(image.c_str());

    // Initialize sprites
    // carreaux de la grille
    sprites_.emplace_back(new Sprite(planche_, 0, 0, 21, 21));
    // bloc rouge
    sprites_.emplace_back(new Sprite(planche_, 20, 0, 21, 21));
    // bloc bleu
    sprites_.emplace_back(new Sprite(planche_, 39, 41, 38, 38));

    // // - background tile
    // sprites_.emplace_back(new Sprite(planche_, 0, 128, 96, 128));
    // // - ball
    // sprites_.emplace_back(new Sprite(planche_, 0, 63, 24, 24));
    // // - bar
    // sprites_.emplace_back(new Sprite(planche_, 128, 0, 128, 32));

    // Initialize balls
    // - allocate
    balls_.resize(500);
    // - randomize
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis_x(40, window_->width() - 40);
    std::uniform_real_distribution<double> dis_y(40, window_->height() - 40);
    std::uniform_real_distribution<double> dis_v_dir(0, 2 * M_PI);
    std::uniform_real_distribution<double> dis_v_l(50, 250);
    for (auto &b : balls_)
    {
        b.set_pos(dis_x(gen), dis_y(gen));
        double r = dis_v_l(gen);
        double a = dis_v_dir(gen);
        b.set_speed(r * cos(a), r * sin(a));
    }
}

void Game::finalize()
{
    // TODO
}

void Game::keyboard(const std::uint8_t *keys)
{
    //	if (keys[SDL_SCANCODE_SPACE])
    //	if (keys[SDL_SCANCODE_UP])
}

void Game::draw(double dt)
{
    // Render background
    // - retrieve background sprite (seamless tile)

    // Sprite *sfond = sprites_[0];
    // // - tile the 2D plan
    // for (int j = 0, h = window_->height(); j <= h; j += sfond->height())
    // {
    //     for (int i = 0, w = window_->width(); i <= w; i += sfond->width())
    //     {
    //         window_->draw(*sfond, i, j);
    //     }
    // }

    Sprite *sCarreau = sprites_[0];

    for (int j = 0, h = 0; h <= 20; j += sCarreau->height(), h++)
    {
        for (int i = 0, w = 0; w <= 10; i += sCarreau->width(), w++)
        {
            window_->draw(*sCarreau, i, j);
        }
    }

    Sprite *sBlocRouge = sprites_[1];

    {
        static ShapeT *shape_test;
        static bool is_shape_initialized = false;
        if (!is_shape_initialized)
        {
            shape_test = ShapeT::create(42, 0);

            is_shape_initialized = true;
        }
        static int frameID = 0;
        int rotationID = (frameID / 200 /*slow*/) % 4 /*nb rotations*/;
        const GraphicsObject::TShape &shapeTiles = shape_test->tiles_[rotationID] /*current rotation ID*/;
        for (const auto &p : shapeTiles)
        {
            const int x = shape_test->getPositionX();
            const int y = shape_test->getPositionY();

            //const int colorID = shape_test->getColorID();
            // const int colorID = 0;
            // Sprite *sball = sprites_[colorID]; // boule verte

            /*int rotation_;
			int nextRotation() { rotation_ = rotation_ % 4 }*/

            const int tileSize = sBlocRouge->height();
            window_->draw(*sBlocRouge, x + p.first * tileSize, y + p.second * tileSize);
        }
        frameID++;
        if ((frameID % 50 == 0))
        {
            shape_test->setPositionY(shape_test->getPositionY() + sBlocRouge->height());
        }
    }
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
