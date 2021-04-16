#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <string>

struct SDL_Surface;

class Sprite;
class Window;


// Classe pour la surface de la fenêtre
class Surface
{
    friend class Window;

    public:
        Surface();
        Surface(const std::string &template_file);
        virtual ~Surface();

        void load(const std::string &template_file);

        void draw(const Sprite &sprite, int x, int y);
        void drawLevel(const Sprite &sprite, int x, int y);

        SDL_Surface *getSurface();


    protected:
        SDL_Surface *surface_;
        Surface(SDL_Surface *surface);
        
        /**
	    * Flag to tell whether or not to handle memory 
        * management of the underlying graphics library's surface
	    */
        bool manageSurface_;

    private:
        // Grille du jeu (10 lignes et 20 colonnes)
        bool surface_matrix_[10][20]; 
};

#endif
