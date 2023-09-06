#include <iostream>;
#include "../headers/Interface.h"
#include"../headers/Engine.h";
#include "../headers/EventManager.h";

Interface* interface = nullptr;
Engine* engine = nullptr;
SDL_Renderer* renderer=nullptr;
SDL_Window* window = nullptr;
EventManager* eventManager;
int blockResolution = 32;
Uint32 frameStart;
const int frameDelay = 1000;

int frameTime;
int main(int argc, char* argv[]) {
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	interface = new Interface();
	engine = new Engine();
	eventManager = new EventManager(engine, interface);

	renderer=interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
	window = interface->window;
	Uint32 previousBlockFallTime = SDL_GetTicks();
	engine->BeginSession(blockResolution,window);

	while (interface->isRunning) {
		frameStart = SDL_GetTicks();
		eventManager->HandleEvents();
		engine->Render(renderer);

		if (frameStart - previousBlockFallTime >= frameDelay) {
			engine->MoveBlockDown();
			previousBlockFallTime = frameStart;
		}
		

	}
	interface->Clean();
	return 0;
}