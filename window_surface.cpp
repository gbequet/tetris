#include "window_surface.h"
#include <SDL.h>

using namespace std;

SDL_Window* WindowSurface::CreateWin(SDL_Window* bon)
{
    return SDL_CreateWindow("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
}
