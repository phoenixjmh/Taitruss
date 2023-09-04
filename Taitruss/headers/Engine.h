#pragma once
#include "../headers/Board.h";

class Engine {
public:
	void BeginSession(int resolution);
	void Render(SDL_Renderer* renderer);
};
