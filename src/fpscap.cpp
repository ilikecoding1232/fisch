#include "fpscap.h"
#include <stdio.h>
#include <SDL.h>

void fpsCap(int fps, int startTime)
{
    int frameDelay = 1000 / fps;                     // Calculate the delay in milliseconds for the desired FPS
    Uint32 elapsedTime = SDL_GetTicks() - startTime; // Get the elapsed time since the start of the frame
    if (elapsedTime < frameDelay)
    {
        SDL_Delay(frameDelay - elapsedTime);
    } // If the elapsed time is less than the frame delay, delay the remaining time to maintain the desired FPS
}
