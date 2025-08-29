// global includes
#include <iostream>
#include <SDL.h>
#include <iterator>

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
#include "colide.h"
#include "minigame.h"

// main function
int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	bool wetMovement = false;
	int o2 = 190;

	initSDL();
	CreateWinRen(window, renderer);
	
	// x, y, w, h
	// see player.h/player.cpp
	Player player = createPlayer(200, 200, 20, 20);
	Player lake  = createPlayer(300, 300, 400, 200);

	while (true)
	{
		Uint32 startTime = SDL_GetTicks();

		if (!update(player, renderer, wetMovement))
		{
			break;
 		}	
	
		BoundryCheck(player);
 
		drawSky(renderer, 110, 40, 240);

		drawRect(renderer, 40, 110, 240, lake);
		drawRect(renderer, 255, 0, 0, player);	

		if (colide_check(player, lake) == true)
		{
			if (o2 > 0)
			{
				o2--;
			}
			std::cout << "colision of a & b" << std::endl;
			wetMovement = true;
			startfishing(player, renderer, o2);
		} 
		else 
		{
			wetMovement = false;
			if (o2 < 190)
			{
				o2++;
			}
		}

		SDL_RenderPresent(renderer);

		fpsCap(60, startTime);
		fpsclock();
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
 
	return 0;
}
