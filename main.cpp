#include <cstdint>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "include/definitions.hpp"

const int FPS = 60;
const int frameDelay = 1000 / FPS; // 1000 / 60 (fps)

Uint32 framestart;
int frametime;

struct Player
{
	int x, y;
	int width;
	int height;

	int speed;
	int health;
};

Player createPlayer(int x, int y)
{
	Player player;
	player.x = x;
	player.y = y;
	player.width = 20;
	player.height = 20;
	player.speed = 5;
	player.health = 100;
	return player;
}

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

void drawRect(SDL_Renderer *renderer, int r, int g, int b, Player &player)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_Rect rect = {player.x, player.y, player.width, player.height};
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}

void BoundryCheck(Player &player)
{
	if (player.x + player.width < 0)
	{
		player.x = 0;
	}
	if (player.x + player.width > 800)
	{
		player.x = (800 - player.width);
	}
	if (player.y + player.height < 0)
	{
		player.y = 0;
	}
	if (player.y + player.height > 600)
	{
		player.y = (600 - player.height);
	}
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