#pragma once
#include "../headers/Board.h"

class Engine {
public:
	bool Freeze;
	bool movedDown;
	int& m_blockResolution;
	Board* board;
	void BeginSession(int& resolution, SDL_Window* window);
	void Update();
	void Render(SDL_Renderer* renderer);
	void DropLogic();
	void MoveBlockDown();
	Engine(int& blockResolution) :
		Freeze{ false },
		movedDown{ false },
		board{ nullptr },
		m_blockResolution{ blockResolution }
	{}
};
