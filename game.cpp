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
    const std::string image = "./sprites.bmp";
    planche_->load(image.c_str());

    // Initialize sprites
    // - background tile
    sprites_.emplace_back(new Sprite(planche_, 0, 128, 96, 128));
    // - ball
    sprites_.emplace_back(new Sprite(planche_, 0, 96, 24, 24));
    // - bar
    sprites_.emplace_back(new Sprite(planche_, 128, 0, 128, 32));

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
    Sprite *sfond = sprites_[0];
    // - tile the 2D plan
    for (int j = 0, h = window_->height(); j <= h; j += sfond->height())
    {
        for (int i = 0, w = window_->width(); i <= w; i += sfond->width())
        {
            window_->draw(*sfond, i, j);
        }
    }

    // Render balls
    // - retrieve ball sprite
    Sprite *sball = sprites_[1];
    // - iterate through balls
    for (auto &b : balls_)
    {
        // Render ball
        window_->draw(*sball, b.X(), b.Y());

        // Move ball
        b.move([&](double &x, double &y, double &vx, double &vy) {
            // Collision management (on world border)
            if ((x < 0) || (x > window_->width() - sball->width()))
                vx *= -1;
            if ((y < 0) || (y > window_->height() - sball->height()))
                vy *= -1;

            // Update position
            x += vx * dt;
            y += vy * dt;

            // Add force(s)
            // - simulate gravity
            vy += 100 * dt;
        });
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
