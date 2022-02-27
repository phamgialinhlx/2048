#include "Resources.h"
#include <iostream>

Resources::Resources(SDL_Renderer* renderer) {
	this->renderer = renderer;
    loadResources();
}

void Resources::loadTexture(SDL_Texture **texture, std::string path) {
    *texture = NULL;
    SDL_Surface* loaded_surface = NULL;
    path = "res/" + path;
    loaded_surface = IMG_Load(path.c_str());
    if (loaded_surface == NULL) {
        printf("Error loading image: %s\n", SDL_GetError());
    }
    *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if (texture == NULL) {
        printf("Unable to create texture from surface: %s\n", SDL_GetError());
    }
    SDL_SetTextureBlendMode(*texture, SDL_BLENDMODE_BLEND);
    SDL_FreeSurface(loaded_surface);
}   


void Resources::loadResources() {
    loadTexture(&texture[2], "2.png");
    loadTexture(&texture[4], "4.png");
    loadTexture(&texture[8], "8.png");
    loadTexture(&texture[16], "16.png");
    loadTexture(&texture[32], "32.png");
    loadTexture(&texture[64], "64.png");
    loadTexture(&texture[128], "128.png");
    loadTexture(&texture[256], "256.png");
    loadTexture(&texture[512], "512.png");
    loadTexture(&texture[1024], "1024.png");
    loadTexture(&texture[2048], "2048.png");
    std::cout << "Init resources successfully" << std::endl;
}

SDL_Texture* Resources::getTexture(int number) {
    return texture[number];
}
