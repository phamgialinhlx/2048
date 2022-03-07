#pragma once
#ifndef PARAM_H
#define PARAM_H

enum DIRECTION {
    UP, DOWN, LEFT, RIGHT, NONE
};

const int DIRECT_X[4] = {0, 0, -1, 1};
const int DIRECT_Y[4] = {-1, 1, 0, 0};

#endif