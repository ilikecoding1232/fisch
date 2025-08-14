#include "drawsky.h"

/**
 * draws the backround of the window
 *  @param renderer: the object that renders it (look idk)
 *  @param r the amount of red (0-255)
 *  @param g the amount of green (0-255)
 *  @param b the amount of blue (0-255)
 */
void drawSky(SDL_Renderer *renderer, int r, int g, int b)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}