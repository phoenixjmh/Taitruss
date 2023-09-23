#include <iostream>
#include "../headers/Interface.h"
#include "../headers/Engine.h"
#include "../headers/EventManager.h"

int BLOCK_RESOLUTION = 32;
int& blockResolution = BLOCK_RESOLUTION;
const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 480;
int main(int argc, char* argv[]) {
	Uint32 frameStart;
	const int frameDelay = 500;
	Interface* interface = new Interface();
	Engine* engine = new Engine(blockResolution);
	EventManager* eventManager = new EventManager(engine, interface);
	SDL_Window* window = interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
	SDL_Renderer* renderer = Interface::renderer;
	Uint32 previousBlockFallTime = SDL_GetTicks();

	engine->BeginSession(blockResolution, window);
	int XRATIO = SCREEN_WIDTH / blockResolution;
	int YRATIO = SCREEN_HEIGHT / blockResolution;

	std::cout << "RATIO:  " << XRATIO << "  " << YRATIO << "\n";
	while (interface->isRunning) {
		frameStart = SDL_GetTicks();
		eventManager->HandleEvents();
		engine->Update();
		engine->Render(renderer);

		if (frameStart - previousBlockFallTime >= frameDelay) {
			engine->MoveBlockDown();
			previousBlockFallTime = frameStart;
		}


	}
	interface->Clean();
	return 0;
}