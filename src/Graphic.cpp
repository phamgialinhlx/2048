#include "Graphic.h"
#include <iostream>

// Init the window
bool Graphic::initSDL()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) {
        printf("Error: Failed to init SDL2: %s\n", SDL_GetError());
        return false;
    }

    screenWindow = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (screenWindow == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }

    std::cout << "[Graphic] Init window successfully" << std::endl;

    renderer = SDL_CreateRenderer(screenWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Could not init renderer: %s\n", SDL_GetError());
        return false;
    }

    std::cout << "[Graphic] Init renderer successfully" << std::endl;

    return true;
} 

Graphic::Graphic() {
    if(initSDL()) std::cout << "Init graphic successfully" << std::endl;
    resources = new Resources(renderer);
}


Graphic::~Graphic() {
    SDL_DestroyWindow(screenWindow);
    SDL_DestroyRenderer(renderer);
}


// Clear screen
void Graphic::clearScreen() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Graphic::rendererPresent() {
    SDL_RenderPresent(renderer);

}