#include "../headers/Interface.h";


SDL_Event Interface::event;
void Interface::CreateWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* name) {
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout<<"Subsystems initialised!"<<std::endl;
	
		//Create window
		window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window)
		{
			std::cout<<"Window Created"<<std::endl;
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer) {
				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
				std::cout << "Renderer Created"<<std::endl;
			}
			
		}
		isRunning = true;
	}
}

void Interface::HandleEvents() {
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
void Interface::Clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned"<<std::endl;
}