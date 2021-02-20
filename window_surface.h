#ifndef _WINDOW_
#define _WINDOW_

#include <SDL.h>


// Classe pour afficher la fênetre du jeu Tetris
class Window
{
    public:
        Window();
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