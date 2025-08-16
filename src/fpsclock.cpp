#include <SDL.h>
#include "fpsclock.h"
#include <iostream>

void fpsclock()
{
	static int frameCount = 0;
	static Uint32 fpsTimer = SDL_GetTicks();

	// FPS counter 
	frameCount++;
	if (SDL_GetTicks() - fpsTimer >= 1000)
	{
		std::cout << "FPS: " << frameCount << std::endl;
		frameCount = 0;
		fpsTimer = SDL_GetTicks();
	}
}
