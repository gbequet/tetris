#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL.h>
#include "surface.h"


class WindSurface;

class Sprite
{
    friend class WindSurface;
    friend class Surface;

private:
    SDL_Rect geom;
    Surface* surf;

public:
    Sprite();
    Sprite(Surface *s, int x, int y, int w, int h);

    SDL_Rect getGeom();
    Surface* getSurf();
    int width();
    int height();
};
#endif