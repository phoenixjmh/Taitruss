#include "../headers/EventManager.h"

SDL_Event EventManager::event;


void EventManager::ResizeGraphics() const
{
	//gather pointers to resolutions
	int screen_width = 0;
	int screen_height = 0;
	SDL_GetWindowSize(Game::interface->window, &screen_width, &screen_height);

	// use calculated height for block size
	// 
	Game::BLOCK_RESOLUTION = screen_height / 20;
	Game::engine->board->winWidth = screen_width;
	Game::engine->board->winHeight = screen_height;
	Game::engine->scoreBoard->winWidth = screen_width;
	Game::engine->scoreBoard->winHeight = screen_height;




}
void EventManager::HandleMenuEvents()
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		Game::interface->isRunning = false;
	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
		ResizeGraphics();
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_RETURN:
			Audio::PlaySound(Audio::SOUNDS::PAUSE);
			Game::engine->StartGame = true;
			SDL_SetRenderDrawColor(Game::interface->renderer, 10, 10, 10, 0);
			break;
		
		default:
			break;
		}
	}
}

void EventManager::HandleEvents(int& pressDelay, const Uint32 input_start, Uint32& previous)
{
	
	if (pressDelay > 0)
	{
		pressDelay--;

	}
	//DELAY INPUT
	const int delay = 50;

	auto start = SDL_GetTicks();

	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		Game::interface->isRunning = false;
	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
		ResizeGraphics();
	if (event.type == SDL_KEYDOWN&&!Game::engine->board->busyMoving)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_RETURN:
			Audio::PlaySound(Audio::SOUNDS::PAUSE);
			Game::engine->GamePausedEvent = true;
			std::cout << "ENTER PRESSED";
			break;
		case SDLK_LEFT:
			Game::engine->board->Move("Left");
			Audio::PlaySound(Audio::SOUNDS::MOVE);
			break;
		case SDLK_RIGHT:
			Game::engine->board->Move("Right");
			Audio::PlaySound(Audio::SOUNDS::MOVE);
			break;
		case SDLK_SPACE:
			Game::engine->board->HardDrop();
			std::cout << "SPACE\n";
			Audio::PlaySound(Audio::SOUNDS::PAUSE);
			break;
		case SDLK_UP:
			Game::engine->board->RotatePiece();
			Audio::PlaySound(Audio::SOUNDS::MOVE);
			break;
		default:
			break;
		}
	}

	

	if (input_start - previous >= delay)
	{
		const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
		if (pressDelay <= 0&&!Game::engine->board->busyMoving)
		{
			


			if (keyboardState[SDL_SCANCODE_DOWN]) {
				Game::engine->board->Move("Down");
				m_isHoldingButton = true;
				Game::engine->board->isPressDown = true;
			}
			else
			{
				m_isHoldingButton = false;
				Game::engine->board->isPressDown = false;
			}

			previous = input_start;
			pressDelay = 0;

		}
	}
}
