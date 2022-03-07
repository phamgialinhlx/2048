#pragma once 
#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
public:
    Board *board = new Board();
    void update(DIRECTION direction);
    void render(Graphic* graphic);
};

#endif