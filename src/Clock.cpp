#include "Clock.h"
#include <ctime>

void Clock::tick()
{
    srand(time(NULL));
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