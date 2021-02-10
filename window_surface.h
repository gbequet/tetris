#ifndef _WINDOW_SURFACE_
#define _WINDOW_SURFACE_


#include <SDL.h>
#include <string>
#include "surface.h"

class Sprite;

class WindowSurface : public Surface
{
public:
    WindowSurface();
    WindowSurface(const std::string &title);

public:
    SDL_Window *window;
    SDL_Surface *window_surface;
};

#endif