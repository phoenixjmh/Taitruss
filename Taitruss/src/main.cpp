#include <iostream>
#include "../headers/Interface.h"
#include "../headers/Engine.h"
#include "../headers/EventManager.h"

int BLOCK_RESOLUTION = 32;
int& blockResolution = BLOCK_RESOLUTION;
constexpr int SCREEN_WIDTH = 760;
constexpr int SCREEN_HEIGHT = 480;
int main(int argc, char* argv[]) {
	int frame_delay = 1000;
	Interface* interface = new Interface();
	SDL_Window* window = interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
	SDL_Renderer* renderer = Interface::renderer;
	Engine* engine = new Engine(blockResolution, renderer,frame_delay);
	Uint32 previous_block_fall_time = SDL_GetTicks();
	Uint32 previous_input_time = SDL_GetTicks();
	int pressHoldDelay = 0;

	engine->BeginSession(blockResolution, window);
	const int X_RATIO = SCREEN_WIDTH / blockResolution;
	const int Y_RATIO = SCREEN_HEIGHT / blockResolution;
	EventManager* eventManager = new EventManager(engine, interface);
	
	eventManager->ResizeGraphics();


	std::cout << "RATIO:  " << X_RATIO << "  " << Y_RATIO << "\n";
	while (interface->isRunning) {
		bool& gameOver = engine->board->GAMEOVER;

		constexpr int input_delay = 100;
		const Uint32 frame_start = SDL_GetTicks();
		const Uint32 input_start = SDL_GetTicks();
		if (!gameOver)
		{
			eventManager->HandleEvents(pressHoldDelay, input_start, previous_input_time);
			engine->update();
			engine->render();

		}


		if (frame_start - previous_block_fall_time >= frame_delay) {
			if (gameOver)
			{
				engine->Reset();
			}
			std::cout << "GameSpeed"<<frame_delay<<"\n";
			engine->move_block_down();
			previous_block_fall_time = frame_start;
			engine->Tick();
		}


	}
	interface->Clean();
	return 0;
}