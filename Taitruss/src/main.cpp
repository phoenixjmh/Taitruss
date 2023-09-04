#include <iostream>;
#include "../headers/Interface.h"
#include"../headers/Engine.h";

Interface* interface = nullptr;
Engine* engine = nullptr;
SDL_Renderer* renderer=nullptr;
int blockResolution = 32;
int main(int argc, char* argv[]) {
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	std::cout << "Hello world!";
	interface = new Interface();
	engine = new Engine();
	renderer=interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
	engine->BeginSession(blockResolution);

	while (interface->isRunning) {
		interface->HandleEvents();
		engine->Render(renderer);

	}
	interface->Clean();
	return 0;
}