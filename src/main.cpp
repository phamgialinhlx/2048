#include <iostream>
#include "Graphic.h"
#include "Clock.h"
#include "Input.h"
#include "SDL2/SDL_timer.h"
// #include

int main(int argc, char **argv)
{
    std::cout << "Initialization" << std::endl;
    Graphic *graphic = new Graphic();
    Clock *clock = new Clock();
    Input *input = new Input();
    while (true)
    {
        clock->tick();
        input->handleInput();
        graphic->clearScreen();

        SDL_Texture *test = graphic->resources->getTexture(2);
        if (test == NULL)
            std::cout << "texturenull" << std::endl;
        SDL_Rect backgroundRect = {0, 0, 200, 200};
        SDL_RenderCopyEx(graphic->renderer, test, NULL, &backgroundRect, 0, NULL, SDL_FLIP_NONE);

        test = graphic->resources->getTexture(2048);
        if (test == NULL)
            std::cout << "texturenull" << std::endl;
        backgroundRect = {0, 200, 200, 200};
        SDL_RenderCopyEx(graphic->renderer, test, NULL, &backgroundRect, 0, NULL, SDL_FLIP_NONE);
        graphic->rendererPresent();
        DIRECTION tmp = input->getInput();
        if (!(tmp == NONE))
        {
            std::cout << tmp << std::endl;
        }
        clock->delay();
    }

    return 0;
}
