#include "window_surface.h"
#include <SDL.h>


WindowSurface::WindowSurface() 
: Surface(), 
window(nullptr),
window_surface(nullptr)
{
    window = SDL_CreateWindow("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    window_surface = SDL_GetWindowSurface(window);
}

WindowSurface::WindowSurface(const std::string &title) 
: Surface(), 
window(nullptr),
window_surface(nullptr)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    window_surface = SDL_GetWindowSurface(window);
}

