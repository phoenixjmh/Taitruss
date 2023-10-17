#include "../headers/Interface.h"

SDL_Renderer* Interface::renderer = nullptr;

SDL_Window* Interface::CreateWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* name) {
	m_WIDTH = &SCREEN_WIDTH;
	m_HEIGHT = &SCREEN_HEIGHT;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised!" << std::endl;
		window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		if (window)
		{
			std::cout << "Window Created" << std::endl;
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
			if (renderer) {
				SDL_SetRenderDrawColor(renderer, 10, 10, 10,255);
				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
				std::cout << "Renderer Created" << std::endl;
			}
		}
		isRunning = true;
		return window;
	}
	else return NULL;
}




void Interface::Clean() const
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
