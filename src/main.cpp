// global includes
#include <cstdint>
#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <sstream>
#include <string>

// local includes
#include "definitions.h"
#include "boundrycheck.h"
#include "player.h"
#include "drawRect.h"

float fps = 0.0f;
int frameCount = 0;

Uint32 framestart;
int frametime;

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
				player.y -= 2;
				break;
			case SDLK_s:
				player.y += 2;
				break;
			case SDLK_a:
				player.x -= 2;
				break;
			case SDLK_d:
				player.x += 2;
				break;
			}
		}
	}
	return true;
}

void drawSky(SDL_Renderer *renderer, int r, int g, int b, int x, int y)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

int main(int argc, char *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	initSDL();
	CreateWinRen(window, renderer);

	Player player = createPlayer(200, 200);

	while (true)
	{

		if (!update(player))
		{
			break;
		}

		BoundryCheck(player);

		drawSky(renderer, 110, 40, 240, 299, 222);
		drawRect(renderer, 255, 0, 0, player); // make sure this is at the end (renderpresent)
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}