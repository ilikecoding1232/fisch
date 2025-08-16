#ifndef INTIALISE_H
#define INTIALISE_H

#include <SDL.h>

/**
 * initialises SDL
 * @note this function should be called before any other SDL functions
 * @return void
 */
void initSDL();

/**
 * creates a window and renderer
 * @param window: a reference to the SDL_Window pointer
 * @param renderer: a reference to the SDL_Renderer pointer
 * @return true if successful, false otherwise
 */
bool CreateWinRen(SDL_Window *&window, SDL_Renderer *&renderer);

#endif
