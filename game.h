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

    bool check_collision(int situation);

private:
    int largeur_carre_;
    int frameID_; // compteur de temps
    int lastMove_; // instant du dernier deplacement a gauche ou droite
    int lastGravity_; // instant de la derniere gravité affectée
    int lastRotate_; // instant du dernier rotate
    bool need_new_bloc_; // vrai si on a besoin d'un nouveau bloc, faux sinon
    int indice_color_; // indice de la couleur ( le meme que dans sprites_ )
    /* 
        (0) carreaux de la grille 
        (1) rouge 
        (2) orange 
        (3) jaune 
        (4) vert 
        (5) bleu 
        (6) mauve 
    */

    Surface *planche_;
    std::vector<Sprite *> sprites_;
    std::tuple<bool,int> presenceGrille_[20][10]; // stocke si il y a un cube et l'indice couleur du bloc ( 0 = carreau de la grille )
    GraphicsObject *current_bloc_; // Shape courant
    std::tuple<int,int> pos_cur_bloc; // position du bloc courant dans la grille
};

#endif
