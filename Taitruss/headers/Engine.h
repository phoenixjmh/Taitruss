#pragma once
#include "../headers/Board.h"

class Engine {
public:
	bool Freeze;
	bool movedDown;
	Board* board;
	void BeginSession(int resolution,SDL_Window* window);
	void Update();
	void Render(SDL_Renderer* renderer);
	void AddPiece();
	void MoveBlockDown();
	Engine():
		Freeze{ false },
		movedDown{false},
		board{nullptr}
	{}
};
