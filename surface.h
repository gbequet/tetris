#ifndef _SURFACE_H_
#define _SURFACE_H_

#include <string>

struct SDL_Surface;

class Sprite;
class Window;

class Surface
{
    friend class Window;

    public:
        Surface();
        Surface(const std::string &template_file);

        virtual ~Surface();

        void initialize();
        void finalize();

        void load(const std::string &template_file);

        void draw(const Sprite &sprite, int x, int y);

    protected:
        SDL_Surface *surface_;

        Surface(SDL_Surface *surface);
        
        /**
	    * Flag to tell whether or not to handle memory management of the underlying graphics library's surface
	    */
        bool manageSurface_;

    private:
        bool surface_matrix_[10][20]; // grille
};

#endif
