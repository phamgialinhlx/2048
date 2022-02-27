#pragma once
#ifndef INPUT_H
#define INPUT_H

#include "SDL2/SDL_events.h"
#include "Param.h"
#include <queue>

class Input {
public:
    SDL_Event e;
    std::queue<DIRECTION> inputQueue;

    void handleInput();
    DIRECTION getInput();
};

#endif // INPUT_H