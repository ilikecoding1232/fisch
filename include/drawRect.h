#ifndef DRAWRECT_H
#define DRAWRECT_H

#include <SDL2/SDL.h>
#include "player.h"

/**
 * draws a passed in rect with specified colour
 * @param renderer: the renderer that its drawn on
 * @param r: the amount of red (0-255)
 * @param g: the amount of green (0-255)
 * @param b: the amount of blue (0-255)
 * @param player: the rect passed in as a **reference** (&rect)
 */
void drawRect(SDL_Renderer *renderer, int r, int g, int b, Player &player);

#endif