#ifndef _SPRITE_H_
#define _SPRITE_H_

struct SDL_Rect;
class Surface;

class Sprite
{
    friend class Surface;

    public:
        Sprite(const Surface *const s, int x, int y, int w, int h);
        virtual ~Sprite();

        int width() const;
        int height() const;

    protected:
        SDL_Rect *geometry_;
        const Surface *const surface_;

    private:
};

#endif
