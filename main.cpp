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

    // Audio
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
