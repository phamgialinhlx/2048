#pragma once
#ifndef BOARD_H
#define BOARD_H

#include "Param.h"
#include "Tile.h"
#include <vector>

class Board {
public:
    Board();
    ~Board();
    std::vector<std::vector<Tile*>> tile;
    void update(DIRECTION direction);
    void render(Graphic* graphic);
};

#endif