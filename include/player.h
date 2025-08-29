// player.h
#ifndef PLAYER_H
#define PLAYER_H

/**
 * creates a rect with passed in x, y etc
 * @param x the horizontal location on the window
 * @param y the vertical location on the window
 * @param width the width of the rect
 * @param height the height of the rect
 * @param speed how fast the rect moves (if it does)
 * @param health how much health the player has
 */
struct Player
{
    int x, y;
    int width;
    int height;
    int speed;
    int health;
};

Player createPlayer(int x, int y, int w, int h);

#endif
