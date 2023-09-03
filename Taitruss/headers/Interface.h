#pragma once
#include <SDL.h>
#include<iostream>
class Interface {
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
	static SDL_Event event;
	void CreateWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* name);
	void HandleEvents();
	void Clean();




};
