#ifndef _GAME_H_
#define _GAME_H_

#include <cstdint>
#include <vector>
#include <list>
#include <tuple>
#include "ball.h"
#include "Shapes.h"

class Window;
class Surface;
class Sprite;

using namespace Shapes;

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
    bool maj_presenceGrille(int situation);

private:
    int frameID_; // compteur de temps
    int lastMove_; // instant du dernier deplacement a gauche ou droite
    int lastRotate_; // instant du dernier rotate
    Surface *planche_;
    std::vector<Sprite *> sprites_;
    std::vector<std::vector<int>> presenceGrille_; // stock le nombre de cube sur chaque case de la grille
    GraphicsObject *current_bloc_; // Shape courant
    std::tuple<int,int> pos_cur_bloc; // position du bloc courant dans la grille
};

#endif
