#ifndef DRAWSKY_H
#define DRAWSKY_H

#include <SDL.h>

/**
 * draws the background of the window
 * @param renderer: the object that renders it (look idk)
 * @param r: the amount of red (0-255)
 */
void drawSky(SDL_Renderer *renderer, int r, int g, int b);

#endif
