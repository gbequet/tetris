#include <SDL.h>
#include "window.h"
#include "surface.h"

using namespace std;


// Constructeur
Window::Window() : 
    pWindow_(nullptr), win_surf_(nullptr),
    width_(800), height_(600), title_("TETRIS")
{
}


// Constructeur avec paramètres
Window::Window(const std::string &name, const int w, const int h) : 
    pWindow_(nullptr), win_surf_(nullptr),
    width_(w), height_(h), title_(name)
{
}


// Getters width
int Window::width() const
{
    return width_;
}


// Getters height
int Window::height() const
{
    return height_;
}


// Initialisation de la fenêtre SDL
void Window::initialize()
{
    pWindow_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_SHOWN);
    SDL_Surface *surface = SDL_GetWindowSurface(pWindow_);
    surface_ = new Surface(surface);
}


// Destruction de la fenetre SDL
void Window::finalize()
{
    SDL_DestroyWindow(pWindow_);
}


// Affichage d'un sprite dans la surface
void Window::draw(const Sprite &sprite, int x, int y)
{
    surface_->draw(sprite, x, y);
}


// Affichage des points et niveaux dans la surface
void Window::drawLevel(const Sprite &sprite, int x, int y)
{
    surface_->drawLevel(sprite, x, y);
}


// Efface fenêtre SDL
void Window::clear()
{
    SDL_Surface *surface = SDL_GetWindowSurface(pWindow_);
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(pWindow_);
}


// Copier la surface de la fenêtre à l'écran
void Window::update() const
{
    SDL_UpdateWindowSurface(pWindow_);
}


// Taille de la fenêtre
void Window::WinSize()
{
    SDL_GetWindowSize(pWindow_, &width_, &height_);
}
