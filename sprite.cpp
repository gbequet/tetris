#include "sprite.h"
#include <SDL.h>
#include <string>
#include <iostream>

Sprite::Sprite() :
    surf(nullptr);
    geom(nullptr);
{
}

Sprite::Sprite(Surface *s, int x, int y, int w, int h) :
{
    surf(s);
    geom(x,y,w,h);
}

SDL_Rect Sprite::getGeom()
{
    return geom;
}

Surface* Sprite::getSurf()
{
    return surf;
}

void Sprite::width()
{
    return geom.w;
}

void Sprite::height()
{
    return geom.h;
}
