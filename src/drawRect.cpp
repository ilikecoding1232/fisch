#include "drawRect.h"
#include <SDL.h>

void drawRect(SDL_Renderer *renderer, int r, int g, int b, Player &player)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_Rect rect = {player.x, player.y, player.width, player.height};
    SDL_RenderFillRect(renderer, &rect);
}
