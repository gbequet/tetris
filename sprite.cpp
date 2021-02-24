#include "sprite.h"
#include <SDL.h>
#include "surface.h"

// Constructeur
Sprite::Sprite(const Surface *const s, int x, int y, int w, int h)
    : surface_(s), geometry_(nullptr)
{
    geometry_ = new SDL_Rect();
    geometry_->x = x;
    geometry_->y = y;
    geometry_->w = w;
    geometry_->h = h;
}

// Destructeur
Sprite::~Sprite()
{
    delete geometry_;
    geometry_ = nullptr;
}

int Sprite::width() const
{
    return geometry_->w;
}

int Sprite::height() const
{
    return geometry_->h;
}
