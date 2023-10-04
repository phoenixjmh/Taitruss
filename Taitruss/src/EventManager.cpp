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
	blockResolution = screen_height / 20;
	engine->board->winWidth = screen_width;
	engine->board->winHeight = screen_height;
	engine->scoreBoard->winWidth = screen_width;
	engine->scoreBoard->winHeight = screen_height;




}
void EventManager::HandleEvents(int& pressDelay ,const Uint32 input_start, Uint32& previous)
{
	if (pressDelay > 0)
	{
	std::cout << pressDelay << "PRESSDELAY\n";
		pressDelay--;
		
	}
	//DELAY INPUT
	const int delay = 100;

	auto start = SDL_GetTicks();

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		interface->isRunning = false;
	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
		ResizeGraphics();


	if (event.type == SDL_KEYDOWN&&!m_isHoldingButton) {
		switch (event.key.keysym.sym) {
		case SDLK_LEFT:
			engine->board->Move("Left");
			pressDelay = 300;
			return;
		case SDLK_RIGHT:
			engine->board->Move("Right");
			pressDelay = 300;
			return;
		case SDLK_DOWN:
			engine->board->Move("Down");
			pressDelay = 300;
			return;
		case SDLK_SPACE:
			engine->board->RotatePiece();
			return;
		default:
			break;

		}
		return;
	}

	if (input_start - previous >= delay)
	{
		const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
		if(pressDelay<=0)
		{
		if (keyboardState[SDL_SCANCODE_LEFT]) {
			engine->board->Move("Left");
			std::cout << "HELD\n";
			m_isHoldingButton = true;
		}

		else if (keyboardState[SDL_SCANCODE_RIGHT]) {
			engine->board->Move("Right");
			m_isHoldingButton = true;
		}

		else if (keyboardState[SDL_SCANCODE_DOWN]) {
			engine->board->Move("Down");
			m_isHoldingButton = true;
		}
		else
		{
			m_isHoldingButton = false;
		}

		previous = input_start;
		pressDelay = 0;
			
		}
	}
}
