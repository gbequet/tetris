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


// Classe qui contient les différentes fonctions pour que le
// jeu soit fonctionnel
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
        void drawSingleGame(double dt);
        void drawMenu(double dt);
        void drawGameOver(double dt);
        void keyboard(const std::uint8_t *keys);

        bool check_collision(int situation);
        void clear_line(int i);
        void make_bloc_fall(int a);
        void update_presenceGrille();
        bool GameOver();

    private:
        int largeur_carre_; // La largeur du carré pour le bloc
        int frameID_; // Compteur de temps
        int lastMove_; // Instant du dernier deplacement à gauche ou droite
        int lastGravity_; // Instant de la derniere gravité affectée
        int lastDown_;    // Instant de la derniere gravité affectée
        int lastRotate_; // Instant de la dernier rotation
        bool need_new_bloc_; // Vrai si on a besoin d'un nouveau bloc, faux sinon
        int indice_color_; // Indice de la couleur (le meme que dans sprites_)

        int compteurPoints; // Compteur qui compte les points
        int niveau; // Affiche le niveau du jeu (incrémente chaque 10 points)
        int vitesseGravite; // Change à partir d'un certain niveau pour augmenter la difficulté
        bool quit; // Pour quitter le jeu -> vrai
        bool gameOver; // Booléen pour le Game Over -> faux
        int compteurSprite; // Compteur pour afficher les points
        int compteurSpriteNiveau; // Compteur pour afficher les niveaux

        int XCoordButtonPlaySingle; // Coordonnée de la position X du bouton play
        int YCoordButtonPlaySingle; // Coordonnée de la position Y du bouton play
        int sizeButtonPlaySingle; // La taille du bouton
        int XToCenter; // Coordonnée de X 
        int YToCenter; // Coordonnée de Y

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
        int presenceGrille_[NB_COL][NB_ROWS]; // Stocke si il y a un cube et l'indice couleur du bloc ( 0 = carreau de la grille )
        GraphicsObject *current_bloc_; // Shape courant
        std::tuple<int,int> pos_cur_bloc; // Position du bloc courant dans la grille
};

#endif
