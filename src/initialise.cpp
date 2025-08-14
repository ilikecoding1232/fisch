#include "initialise.h"
#include <SDL2/SDL.h>
#include "definitions.h"

void initSDL()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initialising SDL : %s", SDL_GetError());
    }
}

bool CreateWinRen(SDL_Window *&window, SDL_Renderer *&renderer)
{
    window = SDL_CreateWindow(
        "fisch",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINHIGHT,
        WINWIDTH,
        0);

    if (!window)
    {
        printf("error creating window : %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer)
    {
        printf("error creating renderer : %s", SDL_GetError());
        return false;
    }

    return true;
}