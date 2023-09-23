#include "../headers/EventManager.h"

SDL_Event EventManager::event;


void EventManager::ResizeGraphics() const
{
	//gather pointers to resolutions
	int screen_width = 0;
	int screen_height = 0;
	int& blockResolution = engine->m_blockResolution;
	SDL_GetWindowSize(interface->window, &screen_width, &screen_height);

	// use calculated height for block size
	// 
	blockResolution = screen_height/15;
	engine->board->winWidth = screen_width;
	engine->board->winHeight = screen_height;
	


}
void EventManager::HandleEvents() const
{
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_SPACE:
			engine->board->RotatePiece();
			break;
		case SDLK_e:
			engine->Freeze = !engine->Freeze;
		case SDLK_LEFT:
			engine->board->Move("Left");
			break;
		case SDLK_RIGHT:
			engine->board->Move("Right");
			break;
		case SDLK_DOWN:
			engine->board->Move("Down");
			break;
		default:
			break;
		}
	}
	switch (event.type) {

	case SDL_QUIT:
		interface->isRunning = false;
		break;
	case SDL_WINDOWEVENT:
		if (event.window.event == SDL_WINDOWEVENT_RESIZED) {

			ResizeGraphics();
		}
	default:
		break;
	}
}
