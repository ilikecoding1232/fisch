#include "boundrycheck.h"

void BoundryCheck(Player &player)
{
    if (player.x < 0)
    {
        player.x = 0;
    }
    if (player.x + player.width > 800)
    {
        player.x = (800 - player.width);
    }
    if (player.y < 0)
    {
        player.y = 0;
    }
    if (player.y + player.height > 600)
    {
        player.y = (600 - player.height);
    }
}