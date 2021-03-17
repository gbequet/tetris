#include <SDL.h>
#include "window.h"
#include "surface.h"
using namespace std;


// Constructeurs
Window::Window() : 
    pWindow_(nullptr), win_surf_(nullptr),
    width_(200), height_(200), title_("Fenetre sans nom")
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
    pWindow_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN);

    SDL_Surface *surface = SDL_GetWindowSurface(pWindow_);
    surface_ = new Surface(surface);
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