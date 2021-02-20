#include <iostream>
#include <SDL.h>
#include "window_surface.h"
using namespace std;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
        cout << "SDL Error" << endl;
		return 1;
	}

	Window win;
	win.CreateWin();
	win.WinSize();
	win.WinSurface();


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
			case SDL_KEYDOWN:
				printf("key %d\n", event.key.keysym.scancode);
				break;
			default: break;
			}
		}
    }

    SDL_Quit();


    return 0;
}
