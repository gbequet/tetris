
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
	Surface* surface1;

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
	win->pWindow = NULL;
	SDL_Window* winWindow;

	surface1 = new Surface();
	surface1->win_surf = NULL;
	SDL_Surface* winSurface;
	
	planche = new Surface();
	planche->plancheSprites = NULL;
	SDL_Surface* plancheSurface;

	winWindow = win->CreateWin(win->pWindow);
	winSurface = surface1->GetWindowSrf(win->pWindow);
	// creation d'une "surface" à patir d'une image
	plancheSurface = planche->BMPLoad();

	// definit la souleur transparente
	//SDL_SetColorKey(win->plancheSprites, true, 0);  // 0: 00/00/00 noir -> transparent

	// place la balle u milieu
	//int w, h;
	//SDL_GetWindowSize(win->pWindow, &w, &h);
	
}

void Game::keyboard(const Uint8* keys)
{
	if (keys[SDL_SCANCODE_SPACE])
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
		ball->changeSpeedY(0.2);
}

void Game::draw(double dt)
{
	// remplit le fond
	SDL_Rect dest = {0, 0, 0, 0};
	for (int j = 0; j < win_surf->h; j += 128)
		for (int i = 0; i < win_surf->w; i += 96)
		{
			dest.x = i;
			dest.y = j;
			// copie depuis la planche de sprite vers la fenetre
			SDL_BlitSurface(plancheSprites, &srcBg, win_surf, &dest);
		}

	// affiche balle
	SDL_Rect dstBall = {int(ball.x), int(ball.y), 0, 0};
	SDL_BlitSurface(plancheSprites, &srcBall, win_surf, &dstBall);

	// deplacement (*dt pour vitesse constante)
	ball.x += ball.vx * dt;
	ball.y += ball.vy * dt;

	// collision bord
	int w, h;
	SDL_GetWindowSize(pWindow, &w, &h);
	if ((ball.x < 1) || (ball.x > (w - 25)))
		ball.vx *= -1;
	if ((ball.y < 1) || (ball.y > (h - 25)))
		ball.vy *= -1;
}

void Game::loop()
{
	Uint64 prev, now = SDL_GetPerformanceCounter(); // timers
	double delta_t;  // durée frame en ms

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		while (!quit && SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				printf("mouse click %d\n", event.button.button);
				break;
			default: break;
			}
		}
	}
}


int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 1;
	}

	Game g;

	g.init();
	g.loop();

	SDL_Quit();
	return 0;
}
