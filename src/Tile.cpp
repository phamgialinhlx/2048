#include "Tile.h"
#include "Param.h"
#include <iostream>
#include <vector>
Tile::Tile(int x, int y, int xGraphic, int yGraphic)
{
    this->x = x;
    this->y = y;
    this->xGraphic = xGraphic;
    this->yGraphic = yGraphic;
}

Tile::~Tile()
{
}

bool validate(int x, int y)
{
    if (x < 0)
        return false;
    if (y < 0)
        return false;
    if (x > 3)
        return false;
    if (y > 3)
        return false;
    return true;
}

void Tile::update(std::vector<std::vector<Tile *>> tile, DIRECTION direction, bool modified)
{
    int nextX = x + DIRECT_X[direction];
    int nextY = y + DIRECT_Y[direction];
    // std::cout << nextY << " " << nextX << std::endl;
    if (!validate(nextX, nextY))
        return;
    if ((this->value == tile[nextY][nextX]->value) && !modified)
    {
        tile[nextY][nextX]->value += this->value;
        this->value = 0;
        tile[nextY][nextX]->update(tile, direction, true);
    }
    else if (tile[nextY][nextX]->value == 0)
    {
        tile[nextY][nextX]->value += this->value;
        this->value = 0;
        tile[nextY][nextX]->update(tile, direction, false);
    }
    else
    {
        tile[nextY][nextX]->update(tile, direction, false);
    }
}
void Tile::charge(std::vector<std::vector<Tile *>> tile, DIRECTION direction)
{
    int nextX = x + DIRECT_X[direction];
    int nextY = y + DIRECT_Y[direction];
    if (!validate(nextX, nextY))
        return;
    if (tile[nextY][nextX]->value == 0)
    {
        tile[nextY][nextX]->value += this->value;
        this->value = 0;
    }
    tile[nextY][nextX]->charge(tile, direction);
}

void Tile::render(Graphic *graphic)
{
    SDL_Texture *texture = graphic->resources->getTexture(value);
    if (texture == NULL)
        std::cout << "[Tile] texture is NULL" << std::endl;
    SDL_Rect shape = {xGraphic, yGraphic, height, height};
    SDL_RenderCopyEx(graphic->renderer, texture, NULL, &shape, 0, NULL, SDL_FLIP_NONE);
}
