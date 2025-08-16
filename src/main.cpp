// global includes
#include <cstdint>
#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <sstream>
#include <string>

// local includes
#include "definitions.h"
#include "boundrycheck.h"
#include "player.h"
#include "drawRect.h"
#include "drawsky.h"
#include "update.h"
#include "initialise.h"
#include "fpscap.h"
#include "fpsclock.h"

// main function
int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	initSDL();
	CreateWinRen(window, renderer);

	Player player = createPlayer(200, 200);

	while (true)
	{
		Uint32 startTime = SDL_GetTicks();

		if (!update(player))
		{
			break;
		}

		BoundryCheck(player);

		drawSky(renderer, 110, 40, 240);
		drawRect(renderer, 255, 0, 0, player); 
		SDL_RenderPresent(renderer);

		fpsCap(120, startTime); // Limit to 60 FPS
		fpsclock();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
