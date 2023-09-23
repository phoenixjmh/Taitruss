#include <iostream>
#include "../headers/Interface.h"
#include "../headers/Engine.h"
#include "../headers/EventManager.h"

int BLOCK_RESOLUTION = 32;
int& blockResolution = BLOCK_RESOLUTION;
constexpr int SCREEN_WIDTH = 620;
constexpr int SCREEN_HEIGHT = 480;
int main(int argc, char* argv[]) {
	Interface* interface = new Interface();
	Engine* engine = new Engine(blockResolution);
	EventManager* eventManager = new EventManager(engine, interface);
	SDL_Window* window = interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
	SDL_Renderer* renderer = Interface::renderer;
	Uint32 previous_block_fall_time = SDL_GetTicks();

	engine->BeginSession(blockResolution, window);
	const int X_RATIO = SCREEN_WIDTH / blockResolution;
	const int Y_RATIO = SCREEN_HEIGHT / blockResolution;

	std::cout << "RATIO:  " << X_RATIO << "  " << Y_RATIO << "\n";
	while (interface->isRunning) {
		constexpr int frame_delay = 1000;
		const Uint32 frame_start = SDL_GetTicks();
		eventManager->HandleEvents();
		engine->update();
		engine->render(renderer);

		if (frame_start - previous_block_fall_time >= frame_delay) {
			engine->move_block_down();
			previous_block_fall_time = frame_start;
			engine->Tick();
		}


	}
	interface->Clean();
	return 0;
}