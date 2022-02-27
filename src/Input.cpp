#include "Input.h"
#include <iostream>
void Input::handleInput()
{
    // std::cout << "START HANDLE" << std::endl;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_KEYUP)
        {
            switch (e.key.keysym.sym)
            {
            case SDLK_UP:
                inputQueue.push(UP);
                // std::cout << "UP" << std::endl;
                break;
            case SDLK_DOWN:
                inputQueue.push(DOWN);
                // std::cout << "DOWN" << std::endl;
                break;
            case SDLK_LEFT:
                inputQueue.push(LEFT);
                // std::cout << "LEFT" << std::endl;
                break;
            case SDLK_RIGHT:
                inputQueue.push(RIGHT);
                // std::cout << "RIGHT" << std::endl;
                break;
            }
        }
    }
}

DIRECTION Input::getInput()
{
    if (!inputQueue.empty())
    {
        DIRECTION tmp = inputQueue.front();
        //std::cout << "TEST INPUT: " << tmp << std::endl;
        inputQueue.pop();
        return tmp;
    } else return NONE;
}
