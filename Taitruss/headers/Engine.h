#pragma once
#include "../headers/Board.h";

class Engine {
public:
	bool Freeze;
	Uint32* _frameStart;
	bool movedDown = false;
	Board* board;
	void BeginSession(int resolution,SDL_Window* window);
	void Render(SDL_Renderer* renderer);
	void AddPiece();
	void MoveBlockDown();
};
