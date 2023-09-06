#include "../headers/EventManager.h";

SDL_Event EventManager::event;
EventManager::EventManager(Engine* engine,Interface* interface) {
	_engine = engine;
	_interface = interface;

}
void EventManager::HandleEvents() {
	SDL_PollEvent(&event);
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				std::cout << "SPACE" << std::endl;
				//Call event to board.
				_engine->board->RotatePiece();
	
				break;
			case SDLK_e:
				_engine->Freeze = !_engine->Freeze;
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