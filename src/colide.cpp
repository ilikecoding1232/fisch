#include "colide.h"
#include <SDL.h>
#include "player.h"

bool colide_check(Player r1, Player r2)
{
	SDL_Rect a = {r1.x, r1.y, r1.width, r1.height};
	SDL_Rect b = {r2.x, r2.y, r2.width, r2.height};
	SDL_Rect intersect;

	if (SDL_IntersectRect(&a, &b, &intersect) == true)
	{
		return true;	
	}
	return false;
}
