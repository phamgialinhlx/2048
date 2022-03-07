#pragma once
#ifndef TILE_H
#define TILE_H

#include "Graphic.h"
#include "Param.h"
#include <vector>


class Tile
{
public:
    int x = 0;
    int y = 0;
    int xGraphic;
    int yGraphic;
    int value = 0;
    Tile(int x, int y, int xGraphic, int yGraphic);
    ~Tile();
    static const int height = 200;
    void render(Graphic *graphic);
    void update(std::vector<std::vector<Tile*>> tile, DIRECTION direction, bool modified);
    void charge(std::vector<std::vector<Tile*>> tile, DIRECTION direction);
};

#endif