#pragma once
#include "Bag.h"
#include "Board.h"
#include "ScoreBoard.h"

class Engine {
public:
	bool Freeze;
	bool movedDown;
	SDL_Renderer* mRenderer;
	int& m_blockResolution;
	Board* board;
	Scoreboard* scoreBoard;
	SDL_Window* m_window;
	int& gameSpeed; //Lower is higher, it's a delay
	
	void BeginSession(int& resolution, SDL_Window* window);
	void update();
	void render();
	void drop_logic() const;
	void move_block_down() const;
	void OnTick();
	void Tick();
	void Reset();

	Engine(int& blockResolution, SDL_Renderer* renderer, int& frame_delay) :
		mRenderer(renderer),
		Freeze{ false },
		movedDown{ false },
		board{ nullptr },
		m_blockResolution{ blockResolution },
		gameSpeed{frame_delay}
		
		
	{
		
	}
private:
	int m_ticks;
};
