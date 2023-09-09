#pragma once
#include <SDL.h>
#include <iostream>
#include "TextureManager.h"

class Interface {
public:
	SDL_Window* window;

	bool isRunning;
	
	static SDL_Renderer* renderer;
	
	SDL_Window* CreateWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* name);
	
	void Clean();
	
	Interface() :
		isRunning{ false },
		window{ nullptr }
	{}
};
