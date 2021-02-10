#include "surface.h"
#include <SDL.h>

Surface::Surface() 
{}


SDL_Surface* Surface::GetWindowSrf(SDL_Window* bon)
{
    return SDL_GetWindowSurface(bon);
}

SDL_Surface* Surface::BMPLoad()
{
    return SDL_LoadBMP("./sprites.bmp");
}