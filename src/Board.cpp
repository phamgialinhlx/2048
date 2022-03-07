#include "Board.h"
#include "Param.h"
#include <iostream>
#include <vector>
#include <ctime>

void randomTile(std::vector<std::vector<Tile *>> tile)
{
    std::vector<Tile *> temp;
    for (int i = 0; i < tile.size(); i++)
    {
        for (int j = 0; j < tile.size(); j++)
        {
            if (tile[i][j]->value == 0)
                temp.push_back(tile[i][j]);
        }
    }
    if (temp.size() != 0)
        temp[rand() % temp.size()]->value = 2;
}

void printBoard(std::vector<std::vector<Tile *>> tile)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << "[" << tile[i][j]->y << "," << tile[i][j]->x << "]"
                      << "(" << tile[i][j]->value << ")"
                      << " ";
        }
        std::cout << std::endl;
    }
}

Board::Board()
{
    tile.resize(4);
    for (int i = 0; i < 4; i++)
    {
        tile[i].resize(4);
        for (int j = 0; j < 4; j++)
        {
            tile[i][j] = new Tile(j, i, j * 200, i * 200); // i ~ y, j ~ x
        }
    }
    randomTile(tile);
    randomTile(tile);

    printBoard(tile);
    /*
    [0, 0] [200, 0] [400, 0] [600, 0]
    [0, 200] [200, 200] [400, 200] [600, 200]
    [0, 400] [200, 400] [400, 400] [600, 400]
    [0, 600] [200, 600] [400, 600] [600, 600]  */
}
Board::~Board() {}

void Board::update(DIRECTION direction)
{
    // tile.size() = 4
    switch (direction)
    {
    case UP:
        for (int x = 0; x < tile.size(); x++)
        {
            tile[0][x]->update(tile, DOWN, false);
            for (int y = 0; y < tile.size(); y++)
            {
                tile[y][x]->charge(tile, UP);
            }
        }
        break;
    case DOWN:
        for (int x = 0; x < tile.size(); x++)
        {
            tile[tile.size() - 1][x]->update(tile, UP, false);
            for (int y = tile.size() - 1; y >= 0; y--)
            {
                tile[y][x]->charge(tile, DOWN);
            }
        }
        break;
    case LEFT:
        for (int y = 0; y < tile.size(); y++)
        {
            tile[y][0]->update(tile, RIGHT, false);
            for (int x = 0; x < tile.size(); x++)
            {
                tile[y][x]->charge(tile, LEFT);
            }
        }
        break;
    case RIGHT:
        for (int y = 0; y < tile.size(); y++)
        {
            tile[y][tile.size() - 1]->update(tile, LEFT, false);
            for (int x = tile.size() - 1; x >= 0; x--)
            {
                tile[y][x]->charge(tile, RIGHT);
            }
        }
        // printBoard(tile);
        break;
    default: // NONE
        break;
    }
    randomTile(tile);
}

void Board::render(Graphic *graphic)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tile[i][j]->render(graphic);
        }
    }
}