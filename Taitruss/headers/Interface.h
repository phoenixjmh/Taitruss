#pragma once
#include <SDL.h>
#include <iostream>
#include "TextureManager.h"

class Interface {
public:
	SDL_Window* window;

	bool isRunning;
	int* m_WIDTH, * m_HEIGHT;
	static SDL_Renderer* renderer;
	
	SDL_Window* CreateWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* name);
	void GetResolutions(int& screen_width, int& screen_height, int& block_resolution);
	
	void Clean();
	
	Interface() :
		isRunning{ false },
		window{ nullptr },
		m_WIDTH{new int},
		m_HEIGHT{new int}
	{}
};
