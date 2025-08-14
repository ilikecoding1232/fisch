#ifndef FPSCAP_H
#define FPSCAP_H

/**
 * fpsCap - limits the frame rate of the game
 * @param fps: the desired frames per second
 * @param startTime: the time when the frame started
 * @note make sure to create a variable to store the start time at the beginning of the main loop
 * @example Uint32 startTime = SDL_GetTicks(); // Get the current time in milliseconds
 * @note this function should be called at the end of the main loop
 * @note it uses SDL_Delay to limit the frame rate
 * @example fpsCap(60); // limits to 60 FPS
 */
void fpsCap(int fps, int startTime);

#endif