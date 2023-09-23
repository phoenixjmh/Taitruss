#include "../headers/Engine.h"
//#define test1

void Engine::BeginSession(int& resolution, SDL_Window* window) {
	board = new Board(m_blockResolution, window);
}

void Engine::update() const
{
	drop_logic();
	board->UpdateVectors();
	board->CollisionCheck();
}

void Engine::render(SDL_Renderer* renderer) const
{
	SDL_RenderClear(renderer);
	board->DrawBoard();
	SDL_RenderPresent(renderer);
}
int times = -1;
void Engine::drop_logic() const
{
	//Use this later to scramble the bag.
	//board->AddPiece("Long");
#ifdef test1
	if (board)
		if (board->dropPiece) {
			++times;
			switch (times) {
			case 0:
				board->AddPiece("L");
				break;
			case 1:
				board->AddPiece("R");
				break;
			case 2:
				board->AddPiece("T");
				break;
			case 3:
				board->AddPiece("Long");
				break;
			case 4:
				board->AddPiece("Long");
				break;
			case 5:
				board->AddPiece("Long");
				break;
			case 6:
				board->AddPiece("Long");
				break;
			case 7:
				board->AddPiece("Z");
				break;
			case 8:
				board->AddPiece("S");

				break;
			case 9:
				board->AddPiece("Square");

				break;

			default:
				break;
			}


#else
	if (board)
		if (board->dropPiece) {
			++times;
			switch (times) {
			case 0:
				board->AddPiece("Long");
				break;
			case 1:
				board->AddPiece("Square");
				break;
			case 2:
				board->AddPiece("L");
				break;
			case 3:
				board->AddPiece("R");
				break;
			case 4:
				board->AddPiece("T");
				break;
			case 5:
				board->AddPiece("S");
				break;
			case 6:
				board->AddPiece("Z");
				break;
			case 7:
				times = -1;
				break;
			default:
				break;
			}


		}
#endif


}
void Engine::move_block_down() const
{
	if (!Freeze)
		board->MoveDown();

}

void Engine::OnTick()
{
	if (board->placeOnNextTick) {
		board->PlacePiece();
		std::cout << "PLACED" << "\n";
	}
}

void Engine::Tick()
{
	m_ticks++;
	std::cout << "TICK: " << m_ticks;
	OnTick();

}



