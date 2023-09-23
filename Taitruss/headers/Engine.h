#pragma once
#include "../headers/Board.h"

class Engine {
public:
	bool Freeze;
	bool movedDown;
	int& m_blockResolution;
	Board* board;
	void BeginSession(int& resolution, SDL_Window* window);
	void update() const;
	void render(SDL_Renderer* renderer) const;
	void drop_logic() const;
	void move_block_down() const;
	void OnTick();
	void Tick();

	Engine(int& blockResolution) :
		Freeze{ false },
		movedDown{ false },
		board{ nullptr },
		m_blockResolution{ blockResolution }
	{}
private:
	int m_ticks;
};
