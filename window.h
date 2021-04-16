#ifndef _WINDOW_
#define _WINDOW_

#include <SDL.h>
#include <string>

class Surface;
class Sprite;


// Classe pour afficher la fênetre du jeu Tetris
class Window
{
    public:
        Window();
        Window(const std::string &name, const int width, const int height);

        // Getters
        int width() const;
        int height() const;

        void initialize();
        void finalize();

        void draw(const Sprite &sprite, int x, int y);
        void drawLevel(const Sprite &sprite, int x, int y);

        void update() const;
        
        void WinSize();
        void WinSurface();

        void clear();

    private:
        int width_;
	    int height_;

        SDL_Window *pWindow_;
        SDL_Surface *win_surf_;
        Surface *surface_;
        std::string title_;
};

#endif