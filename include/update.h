#ifndef UPDATE_H
#define UPDATE_H

#include "player.h"
#include <SDL.h>

/**
 * update - called every frame;
 * update is used for input from the user such as keyboard event & window events e.g. clicking the X button
 * @param player see "player.h/player.cpp"
 */
bool update(Player &player, SDL_Renderer* renderer, bool wet);

#endif
