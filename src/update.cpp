#include "update.h"
#include "SDL_keyboard.h"
#include "SDL_scancode.h"
#include "SDL_stdinc.h"
#include "player.h"
#include <SDL.h>
#include "drawrect.h"
#include <iostream>
#include "minigame.h"

const Uint8 *keystate;

bool update(Player &player, SDL_Renderer* renderer, bool wet)
{
	SDL_Event event;

	int p1 = player.x/2;
	int p2 = player.y/2;

	int barY = 40;

	Player bar = createPlayer(p1+5, p2+5, 50, barY);

	while (SDL_PollEvent(&event))
	{
		keystate = SDL_GetKeyboardState(NULL);

		drawRect(renderer,0,255,0, bar);

		if (event.type == SDL_QUIT)
		{
			return false;
		}

		if (event.type == SDL_KEYDOWN)
		{
			if (keystate[SDL_SCANCODE_ESCAPE])
			{
				return false;	
			}

			if (wet == false)
			{
				if (keystate[SDL_SCANCODE_W])
				{
					player.y -= player.speed;
				}
				if (keystate[SDL_SCANCODE_S])
				{
					player.y += player.speed;
				}
				if (keystate[SDL_SCANCODE_A])
				{
					player.x -= player.speed;
				}
				if (keystate[SDL_SCANCODE_D])
				{
					player.x += player.speed;
				}
			} else if (wet == true) {
				if (keystate[SDL_SCANCODE_W])
				{
					player.y -= (player.speed / 2);
				}
				if (keystate[SDL_SCANCODE_S])
				{
					player.y += (player.speed / 2);
				}
				if (keystate[SDL_SCANCODE_A])
				{
					player.x -= (player.speed / 2);
				}
				if (keystate[SDL_SCANCODE_D])
				{
					player.x += (player.speed / 2);
				}
				if (keystate[SDL_SCANCODE_E])
				{
					barY--;		
				}
			}
		}
	}
	return true;
}
