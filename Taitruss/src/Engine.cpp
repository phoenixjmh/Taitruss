#include "../headers/Engine.h"


void Engine::BeginSession(int& resolution, SDL_Window* window) {
	board = new Board(m_blockResolution, window, this);
	scoreBoard = new Scoreboard(m_blockResolution);
	m_window = window;

}

void Engine::update()
{
	drop_logic();
	board->UpdateVectors();
	board->CollisionCheck();
}

void Engine::render()
{
	SDL_RenderClear(mRenderer);
	board->DrawBoard();
	scoreBoard->Draw();
	SDL_RenderPresent(mRenderer);
}
int times = -1;
void Engine::drop_logic() const
{
	//Use this later to scramble the bag.
	//board->AddPiece("Long");

	if (board)
		if (board->dropPiece) {
			ALL_PIECES nextPiece = Bag::Pull();
			std::cout << nextPiece << "PIECE\n";
			board->AddPiece(nextPiece);

		}

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
	//scoreBoard->AddPoint();
	m_ticks++;
	OnTick();

}
void Engine::Reset()
{

	std::cout << "Resetting board\n";
	board = new Board(m_blockResolution, m_window, this);
	gameSpeed = 1000;
	scoreBoard = new Scoreboard(m_blockResolution);


}



