#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL.h>
#include <string>

class Sprite;

class Surface
{

public: 
    Surface();
    Surface(const char* path);

    SDL_Surface *surface_sdl;
    SDL_Surface *win_surf;

    // creation d'une "surface" à patir d'une image
    void draw(const Sprite &s, int x, int y);
};

#endif