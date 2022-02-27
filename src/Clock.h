#pragma once
#ifndef CLOCK_H
#define CLOCK_H

#include "SDL2/SDL_timer.h"

class Clock {
public:
    unsigned long lastTime = 0;
    static const int FPS = 75;
	static const int frameDelay = 1000 / FPS;

    void tick();
    void delay();



};

#endif //CLOCK_H