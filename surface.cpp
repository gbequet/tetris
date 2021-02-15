#include "surface.h"
#include "sprite.h"
#include <SDL.h>
#include <string>
#include <iostream>

Surface::Surface() : surface_sdl(nullptr)
{

}

Surface::Surface(const char* path) 
{
    surface_sdl = SDL_LoadBMP(path);
    SDL_SetColorKey(surface_sdl, true, 0);
}

void Surface::draw(const Sprite& s, int x, int y)
{
    SDL_Rect d{ x, y, 0, 0};
    SDL_Rect sgeom = s.getGeom();
    Surface* ssurf = s.getSurf();
    SDL_BlitSurface(ssurf->surface_sdl, &sgeom, surface_sdl, &d);
}

