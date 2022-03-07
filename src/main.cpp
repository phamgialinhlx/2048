#include <iostream>
#include "Graphic.h"
#include "Clock.h"
#include "Input.h"
#include "Game.h"
#include "SDL2/SDL_timer.h"
#include <ctime>

int main(int argc, char **argv)
{
    
    std::cout << "Initialization" << std::endl;
    Graphic *graphic = new Graphic();
    Clock *clock = new Clock();
    Input *input = new Input();
    Game *game = new Game();
    while (true)
    {

        clock->tick();
        // Handle Input
        input->handleInput();
        if (input->quit())
            break;
        game->update(input->getInput());
        game->render(graphic);
        clock->delay();
    }

    return 0;
}