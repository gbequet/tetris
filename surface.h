#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL.h>
#include <string>

class Sprite;

class Surface
{
    public:
        Surface();
        SDL_Surface* GetWindowSrf(SDL_Window* bon);
        SDL_Surface* BMPLoad();
        SDL_Surface* win_surf;
        SDL_Surface* plancheSprites;
};

#endif