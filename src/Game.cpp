#include "Game.h"
#include "Param.h"

#include <iostream>

void Game::update(DIRECTION direction)
{
    if (direction != 4)
    board->update(direction);
}

void Game::render(Graphic *graphic) {
    graphic->clearScreen();
    board->render(graphic);
    graphic->rendererPresent();
}
