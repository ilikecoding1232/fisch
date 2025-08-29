#include "minigame.h"
#include "player.h"
#include "drawRect.h"
#include <SDL.h>

void startfishing(Player player, SDL_Renderer* renderer, int o2)
{
	int p1 = player.x/2;
	int p2 = player.y/2;

	Player game = createPlayer(p1, p2, 50, 200);

	drawRect(renderer, 0, 0, 0, game);
}
