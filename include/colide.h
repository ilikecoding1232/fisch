#ifndef COLIDE_H
#define COLIDE_H 

#include "player.h"

/*
 * takes in 2 Player structs and returns either true or false
 * a function for checking colision between to rects
 * @param a takes in a "player" struct  
 * @param b takes in a "player struct
*/
bool colide_check(Player a, Player b);

#endif
