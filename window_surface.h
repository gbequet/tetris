#ifndef _WINDOW_SURFACE_
#define _WINDOW_SURFACE_


#include <SDL.h>
#include "surface.h"

class Sprite;

class WindowSurface : public Surface
{

public:
    WindowSurface();

private:
SDL_Window *pWindow;

};

#endif