#ifndef _WINDOW_SURFACE_
#define _WINDOW_SURFACE_

#include <SDL.h>


// Classe pour afficher la fênetre du jeu Tetris
class WindowSurface
{
    public:
        WindowSurface();
        void CreateWin();
        void WinSize();
        void WinSurface();

    private:
        int width;
	    int height;
        SDL_Window *pWindow;
        SDL_Surface *win_surf;
};

#endif