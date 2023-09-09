#include "../headers/EventManager.h"

SDL_Event EventManager::event;

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
	default:
		break;
	}
}