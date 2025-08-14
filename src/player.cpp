// player.cpp
#include "player.h"

Player createPlayer(int x, int y)
{
    Player player;
    player.x = x;
    player.y = y;
    player.width = 20;
    player.height = 20;
    player.speed = 50;
    player.health = 100;
    return player;
}