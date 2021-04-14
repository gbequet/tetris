#include <SDL.h>
#include "game.h"
#include "time.h"

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 1;
	}	

	Game *game = new Game();
	clock_t start = clock();

	game->initialize();

    // audio
    if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		return 1;
	}	
	
    // load WAV file
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    
    SDL_LoadWAV("POL-hitch-a-ride-long.wav", &wavSpec, &wavBuffer, &wavLength);
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

    // play audio
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);

	game->loop();	
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Temps écoulé: %f\n", time_spent);
	game->finalize();

	delete game;
	game = nullptr;

    SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
	SDL_Quit();
 

	return 0;
}


/* 
	Ton code FLO :)
*/

// #include <iostream>
// #include <SDL.h>
// #include "window_surface.h"
// using namespace std;

// int main()
// {
// 	if (SDL_Init(SDL_INIT_VIDEO) != 0)
// 	{
// 		cout << "SDL Error" << endl;
// 		return 1;
// 	}

// 	Window win;
// 	win.CreateWin();
// 	win.WinSize();
// 	win.WinSurface();

// 	bool quit = false;
// 	while (!quit)
// 	{
// 		SDL_Event event;
// 		while (!quit && SDL_PollEvent(&event))
// 		{
// 			switch (event.type)
// 			{
// 			case SDL_QUIT:
// 				quit = true;
// 				break;
// 			case SDL_MOUSEBUTTONDOWN:
// 				printf("mouse click %d\n", event.button.button);
// 				break;
// 			case SDL_KEYDOWN:
// 				printf("key %d\n", event.key.keysym.scancode);
// 				break;
// 			default:
// 				break;
// 			}
// 		}
// 	}

// 	SDL_Quit();

// 	return 0;
// }
