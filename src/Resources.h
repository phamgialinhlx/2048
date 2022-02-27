#pragma once
#ifndef RESOURCES_H
#define RESOURCES_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <map>

class Resources {
private:
	SDL_Renderer* renderer = NULL;
	std::map<int, SDL_Texture*> texture;
	


public:
	Resources(SDL_Renderer* renderer);
	~Resources();
	void loadResources();
	void loadTexture(SDL_Texture** texture, std::string filename);
	SDL_Texture* getTexture(int number);
};




#endif //RESOURCES_H