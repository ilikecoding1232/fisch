#include "update.h"
#include "SDL_keyboard.h"
#include "SDL_scancode.h"
#include "SDL_stdinc.h"
#include "player.h"
#include <SDL.h>
#include <cstdint>

const Uint8 *keystate;

bool update(Player &player)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            return false;
        }

        if (event.type == SDL_KEYDOWN)
        {
                        keystate = SDL_GetKeyboardState(NULL);
			if (keystate[SDL_SCANCODE_ESCAPE])
			{
				return false;	
			}
			
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

        }
    }
    return true;
}
