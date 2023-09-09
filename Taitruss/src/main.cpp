#include <iostream>
#include "../headers/Interface.h"
#include "../headers/Engine.h"
#include "../headers/EventManager.h"


int main(int argc, char* argv[]) {
	Uint32 frameStart;
	const int frameDelay = 500;
	const int blockResolution = 32;
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	Interface* interface = new Interface();
	Engine* engine = new Engine();
	EventManager* eventManager = new EventManager(engine, interface);
	SDL_Window* window = interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
	SDL_Renderer* renderer = Interface::renderer;
	Uint32 previousBlockFallTime = SDL_GetTicks();

	engine->BeginSession(blockResolution, window);

	while (interface->isRunning) {
		frameStart = SDL_GetTicks();
		eventManager->HandleEvents();
		engine->Render(renderer);
		engine->Update();

		if (frameStart - previousBlockFallTime >= frameDelay) {
			engine->MoveBlockDown();
			previousBlockFallTime = frameStart;
		}


	}
	interface->Clean();
	return 0;
}