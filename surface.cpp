#include "surface.h"
#include <SDL.h>

Surface::Surface()
: surface_SDL(nullptr) 
{
    surface_SDL = SDL_LoadBMP("./sprites.bmp");
}

Surface::Surface(const std::string &path)
: surface_SDL(nullptr) 
{
    surface_SDL = SDL_LoadBMP(path);
}

SDL_Surface* Surface::GetWindowSrf(SDL_Window* bon)
{
    return SDL_GetWindowSurface(bon);
}

void *Surface::draw(const Sprite &spr, int x, int y)
{
    SDL_Rect src {x, y, 0, 0};
    SDL_Rect dist {x, y, 0, 0};
    SDL_Surface* win_surf;
    SDL_BlitSurface( surface_sdl, &src, win_surf, &dist);
}
