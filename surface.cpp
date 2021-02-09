#include "surface.h"
#include <SDL.h>
#include <string>
#include <iostream>

using namespace std;


Surface::Surface() 
{

}

void Surface::setPlancheSprites(const char* path) 
{
    // erreur : ne reconnait pas SDL_LoadBMP meme quand on include <SDL.h>
    
    plancheSprites = SDL_LoadBMP(path);
}


