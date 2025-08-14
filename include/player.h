// player.h
#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
    int x, y;
    int width;
    int height;
    int speed;
    int health;
};

Player createPlayer(int x, int y);

#endif