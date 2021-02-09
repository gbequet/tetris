#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL.h>
#include "surface.h"


class WindSurface;

class Sprite
{

public:
    Sprite();

private:
SDL_Rect srcBg;
SDL_Rect srcBall;

};
#endif