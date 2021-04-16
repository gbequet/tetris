#include "surface.h"
#include <SDL.h>
#include "sprite.h"


// Constructeur
Surface::Surface()
    : surface_(nullptr), manageSurface_(true)
{
}


// Constructeur avec paramètres
Surface::Surface(const std::string &template_file) : 
    surface_(nullptr), manageSurface_(true)
{
    surface_ = SDL_LoadBMP("./sprites.bmp");
    SDL_SetColorKey(surface_, true, 0);
}


Surface::Surface(SDL_Surface *surface) : 
    surface_(surface), manageSurface_(false)
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


// Getters Surface
SDL_Surface *Surface::getSurface()
{
    return surface_;
}


// Charger les images de BMP
void Surface::load(const std::string &template_file)
{
    surface_ = SDL_LoadBMP(template_file.c_str());
    SDL_SetColorKey(surface_, true, 0); // 0: 00/00/00 noir -> transparent
}


// Fonction qui dessine les blocs pour le jeu
void Surface::draw(const Sprite &sprite, int x, int y)
{
    SDL_Rect dst{x, y, 0, 0};
    SDL_BlitSurface(sprite.surface_->surface_, sprite.geometry_, surface_, &dst);
}


// Fonction qui affiche les chiffres pour les points et niveaux 
void Surface::drawLevel(const Sprite &sprite, int x, int y)
{
    SDL_Rect dst{x, y, 0, 0};
    SDL_BlitSurface(sprite.surface_->surface_, sprite.geometry_, surface_, &dst);
}