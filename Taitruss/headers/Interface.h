#pragma once
#include <SDL.h>
#include<iostream>
#include "TextureManager.h";

class Interface {
public:
	SDL_Window* window;
	bool isRunning;
	static SDL_Renderer* renderer;
	/*static SDL_Event event;*/
	SDL_Renderer* CreateWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* name);
	//void KeyboardInput();
	//void HandleEvents();
	void Clean();
	Interface();




};
