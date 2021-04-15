#include <SDL.h>
#include "window.h"
#include "surface.h"
using namespace std;


// Constructeurs
Window::Window() : 
    pWindow_(nullptr), win_surf_(nullptr),
    width_(800), height_(600), title_("TETRIS")
{
}

Window::Window(const std::string &name, const int w, const int h) : 
    pWindow_(nullptr), win_surf_(nullptr),
    width_(w), height_(h), title_(name)
{
}

// Getters
int Window::width() const
{
    return width_;
}

int Window::height() const
{
    return height_;
}

// Initialisation
void Window::initialize()
{
    pWindow_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_SHOWN);

    SDL_Surface *surface = SDL_GetWindowSurface(pWindow_);

    // e1d2b8
    // 0xFFF5EE, F4E5D4
    //SDL_Flip(surface); 
    surface_ = new Surface(surface);
    //planche1_ = new Surface(surface);
}

// Destruction de la fenetre pour SDL
void Window::finalize()
{
    SDL_DestroyWindow(pWindow_);
}

// Affichage d'un sprite sur la surface
void Window::draw(const Sprite &sprite, int x, int y)
{
    surface_->draw(sprite, x, y);
}

void Window::drawLevel(const Sprite &sprite, int x, int y)
{
    surface_->drawLevel(sprite, x, y);
}


void Window::update() const
{
    // Copy the window surface to the screen
    SDL_UpdateWindowSurface(pWindow_);
}

// Prendre la taille de la fenêtre 
// Utile ? On verra par la suite
void Window::WinSize()
{
    SDL_GetWindowSize(pWindow_, &width_, &height_);
}
