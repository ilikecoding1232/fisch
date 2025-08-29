// player.cpp
#include "player.h"

Player createPlayer(int x, int y, int w, int h)
{
    Player player;
    player.x = x;
    player.y = y;
    player.width = w;
    player.height = h;
    player.speed = 5;
    player.health = 100;
    return player;
}
