#pragma once
#include "../headers/Board.h";

class Engine {
public:
	Board* board;
	void BeginSession(int resolution,SDL_Window* window);
	void Render(SDL_Renderer* renderer);
};
