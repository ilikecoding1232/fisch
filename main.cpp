#include <iostream>
#include <SDL2/SDL.h>
#include "include/definitions.hpp"

void initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0);
	{
		std::cout << "Error initializing SDL! : " << SDL_GetError() << std::endl;
	}
}

bool CreateWinRen(SDL_Window*& window, SDL_Renderer*& renderer) 
{
	window = SDL_CreateWindow(
			"fisch",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WINHIGHT,
			WINWIDTH,
			0
	);
	
	if (!window)
	{
		std::cerr << "Error window failed te be created : " << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
	{
		std::cerr << "Error renderer failed te be created : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

bool update(SDL_Rect &player)
{
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					return false;
					break;
				case SDLK_w:
					player.y -= 10;	
					break;
				case SDLK_s:
					player.y += 10;
					break;
				case SDLK_a:
					player.x -= 10;
					break;
				case SDLK_d:
					player.x += 10;
					break;
			}
		}
	}
	return true;
}

void drawSky(SDL_Renderer* renderer, int r, int g, int b, int x, int y)
{
	SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
	SDL_RenderClear(renderer);
}

void drawRect(SDL_Renderer* renderer, int r, int g, int b, SDL_Rect player)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &player);
	SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	initSDL();
	CreateWinRen(window, renderer);
	
	// player vars - what did u think it fucking says it basically
	SDL_Rect player;
	player.x = 200;
	player.y = 200;
	player.w = 50;
	player.h = 50;

	while (true)
	{
		if (update(player) == false)
		{
			return false;
		}
	
		drawSky(renderer, 110, 40, 240, 299, 222);
		drawRect(renderer, 255, 0, 0, player); // make sure this is at the end (renderpresent)

	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
