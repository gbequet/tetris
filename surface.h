#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL.h>
#include <string>

class Sprite;

class Surface
{

public: 
    Surface();

    SDL_Surface *win_surf;
    SDL_Surface *plancheSprites;

    // creation d'une "surface" à patir d'une image
    void setPlancheSprites(const char* path);
};

#endif