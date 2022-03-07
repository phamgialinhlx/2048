#pragma once
#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "Resources.h"

class Graphic {
public:
    SDL_Window* screenWindow;
	SDL_Renderer* renderer;
    Resources* resources;


    static const int screenWidth = 800, screenHeight = 800;
	const std::string windowTitle = "2048";


    Graphic();
    ~Graphic();
    bool initSDL();
    void clearScreen();
    void rendererPresent();
    
};

#endif //GRAPHIC_H