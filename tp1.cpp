
#include <SDL.h>
#include <string>
#include <iostream>

#include "window_surface.h"
#include "sprite.h"
#include "ball.h"


class Game
{
	WindowSurface* win;
	Surface* planche;
	Ball* ball;


	// + ?

public:
	inline Game():
	win(nullptr),planche(nullptr)
	{}

	void init();

	void draw(double dt);

	void keyboard(const Uint8* keys);

	void loop();
};




void Game::init()
{
	win = new WindowSurface();
	planche = new Surface();
	ball = new Ball();

	planche->setPlancheSprites("sprites.bmp");
	// definit la couleur transparente
	SDL_SetColorKey(planche->plancheSprites, true, 0);

	// place la balle au milieu
	int w, h;
	SDL_GetWindowSize(win, &w, &h);
	ball->moveX(w/2);
	ball->moveY(h/2);
}

void Game::keyboard(const Uint8* keys)
{
	/*if (keys[SDL_SCANCODE_SPACE])
	{
		int w, h;
		SDL_GetWindowSize(win, &w, &h);
		ball->moveX(w/2);
		ball->moveY(h/2);
	}

	if (keys[SDL_SCANCODE_LEFT])
		ball->changeSpeedX(-0.2);

	if (keys[SDL_SCANCODE_RIGHT])
		ball->changeSpeedX(0.2);

	if (keys[SDL_SCANCODE_UP])
		ball->changeSpeedY(-0.2);

	if (keys[SDL_SCANCODE_DOWN])
		ball->changeSpeedY(0.2);*/
}

void Game::draw(double dt)
{

}

void Game::loop()
{

}


int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 1;
	}

	Game g;

	g.init();
	//g.loop();

}

