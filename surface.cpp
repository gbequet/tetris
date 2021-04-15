#include "surface.h"
#include <SDL.h>
#include "sprite.h"


// Constructeurs
Surface::Surface()
    : surface_(nullptr), manageSurface_(true)
{
}

Surface::Surface(const std::string &template_file)
    : surface_(nullptr), manageSurface_(true)
{
    surface_ = SDL_LoadBMP("./sprites.bmp");
    SDL_SetColorKey(surface_, true, 0);
}

Surface::Surface(SDL_Surface *surface)
    : surface_(surface), manageSurface_(false)
{
}

// Destructeur
Surface::~Surface()
{
    if (manageSurface_)
    {
        SDL_FreeSurface(surface_);
    }
}

void Surface::initialize()
{
}

void Surface::finalize()
{
    // TODO
}

SDL_Surface *Surface::getSurface()
{
    return surface_;
}


void Surface::load(const std::string &template_file)
{
    surface_ = SDL_LoadBMP(template_file.c_str());
    SDL_SetColorKey(surface_, true, 0); // 0: 00/00/00 noir -> transparent
}


void Surface::draw(const Sprite &sprite, int x, int y)
{
    SDL_Rect dst{x, y, 0, 0};
    SDL_BlitSurface(sprite.surface_->surface_, sprite.geometry_, surface_, &dst);
}

void Surface::drawLevel(const Sprite &sprite, int x, int y)
{
    SDL_Rect dst{x, y, 0, 0};
    SDL_BlitSurface(sprite.surface_->surface_, sprite.geometry_, surface_, &dst);
}