#ifndef _WINDOW_SURFACE_
#define _WINDOW_SURFACE_


#include <SDL.h>
#include "surface.h"

class Sprite;

class WindowSurface : public Surface
{
    public:
    SDL_Window* CreateWin(SDL_Window* bon);
    SDL_Window* pWindow;

};

#endif