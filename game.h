#ifndef _GAME_H_
#define _GAME_H_

#include <cstdint>
#include <vector>
#include <list>
#include "ball.h"

class Window;
class Surface;
class Sprite;

class Game
{
public:
    Game();
    virtual ~Game();

    void initialize();
    void finalize();

    void loop();

protected:
    Window *window_;

    void draw(double dt);

    void keyboard(const std::uint8_t *keys);

private:
    Surface *planche_;
    std::vector<Sprite *> sprites_;
    std::vector<Ball> balls_;
    std::list<std::vector<int>> presenceGrille_; // stock le nombre de cube sur chaque case de la grille
};

#endif
