#include "../headers/EventManager.h"

SDL_Event EventManager::event;


void EventManager::ResizeGraphics() {
	//gather pointers to resolutions
	int screen_width = 0;
	int screen_height = 0;
	int& blockResolution = _engine->m_blockResolution;
	SDL_GetWindowSize(_interface->window, &screen_width, &screen_height);

	// use calculated height for block size
	// 
	blockResolution = screen_height/15;
	_engine->board->winWidth = screen_width;
	_engine->board->winHeight = screen_height;
	


}
void EventManager::HandleEvents() {
	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_SPACE:
			_engine->board->RotatePiece();
			break;
		case SDLK_e:
			_engine->Freeze = !_engine->Freeze;
		case SDLK_LEFT:
			_engine->board->Move("Left");
			break;
		case SDLK_RIGHT:
			_engine->board->Move("Right");
			break;
		case SDLK_DOWN:
			_engine->board->Move("Down");
			break;
		default:
			break;
		}
	}
	switch (event.type) {

	case SDL_QUIT:
		_interface->isRunning = false;
		break;
	case SDL_WINDOWEVENT:
		if (event.window.event == SDL_WINDOWEVENT_RESIZED) {

			ResizeGraphics();
		}
	default:
		break;
	}
}