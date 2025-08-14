#ifndef DRAWRECT_H
#define DRAWRECT_H

#include <SDL2/SDL.h>
#include "player.h"

void drawRect(SDL_Renderer *renderer, int r, int g, int b, Player &player);

#endif