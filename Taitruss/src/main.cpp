#include <iostream>;
#include "../headers/Interface.h"
#include"../headers/Engine.h";

Interface* interface = nullptr;
Engine* engine = nullptr;
int main(int argc,char *argv[]) {
	int SCREEN_WIDTH = 640;
	int SCREEN_HEIGHT = 480;
	std::cout << "Hello world!";
	interface= new Interface();
	engine = new Engine();
	interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
	engine->BeginSession();

	while (interface->isRunning) {
		interface->HandleEvents();

	}
	interface->Clean();
	return 0;
}