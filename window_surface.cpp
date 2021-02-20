#include <SDL.h>
#include "window_surface.h"
using namespace std;


// Constructeur
Window::Window() : pWindow(nullptr), win_surf(nullptr)
{
}


// Creation de la fenêtre du jeu
void Window::CreateWin()
{
    pWindow = SDL_CreateWindow("Projet Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
}


// Prendre la taille de la fenêtre 
// Utile ? On verra par la suite
void Window::WinSize()
{
    SDL_GetWindowSize(pWindow, &width, &height);
}


// Taille de la surface du jeu
void Window::WinSurface()
{
    win_surf = SDL_GetWindowSurface(pWindow);
}
