#ifndef _GAME_H_
#define _GAME_H_

#include <cstdint>
#include <vector>
#include <list>
#include <tuple>
#include "Shapes.h"

#define NB_COL 10
#define NB_ROWS 20

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
    void clear_line(int i);
    void make_bloc_fall(int a);
    void update_presenceGrille();
    bool GameOver();

private:
    int largeur_carre_;
    int frameID_; // compteur de temps
    int lastMove_; // instant du dernier deplacement a gauche ou droite
    int lastGravity_; // instant de la derniere gravité affectée
    int lastDown_;    // instant de la derniere gravité affectée
    int lastRotate_; // instant du dernier rotate
    bool need_new_bloc_; // vrai si on a besoin d'un nouveau bloc, faux sinon
    int indice_color_; // indice de la couleur ( le meme que dans sprites_ )
    int compteurPoints; // compteur qui compte les points
    int niveau; // affiche le niveau du jeu (incrémente chaque 10 points)
    int vitesseGravite; // change à partir d'un certain niveau pour augmenter la difficulté
    bool quit; // pour quitter le jeu
    int compteurSprite; // compteur pour afficher les points
    int compteurSpriteNiveau; // compteur pour afficher les niveaux
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
    int presenceGrille_[NB_COL][NB_ROWS]; // stocke si il y a un cube et l'indice couleur du bloc ( 0 = carreau de la grille )
    GraphicsObject *current_bloc_; // Shape courant
    std::tuple<int,int> pos_cur_bloc; // position du bloc courant dans la grille
};

#endif
