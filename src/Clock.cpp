#include "Clock.h"

void Clock::tick()
{
    lastTime = SDL_GetTicks();
}

void Clock::delay()
{
    int frameTime = SDL_GetTicks() - lastTime;
    if (frameDelay > frameTime)
    {
        SDL_Delay(frameDelay - frameTime);
    }
}