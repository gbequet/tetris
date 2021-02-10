#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <SDL.h>
#include <string>

class Sprite;

class Surface
{
public:
    Surface();
    Surface(const std::string &path);
    SDL_Surface *GetWindowSrf(SDL_Window *bon);

    void draw(const Sprite &spr, int x, int y);

private:
    SDL_Surface* surface_SDL;
};

#endif