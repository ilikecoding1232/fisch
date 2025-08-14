#include "update.h"
#include "player.h"
#include <SDL2/SDL.h>

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
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                return false;
                break;
            case SDLK_w:
                player.y -= player.speed;
                break;
            case SDLK_s:
                player.y += player.speed;
                break;
            case SDLK_a:
                player.x -= player.speed;
                break;
            case SDLK_d:
                player.x += player.speed;
                break;
            }
        }
    }
    return true;
}