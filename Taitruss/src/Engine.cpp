#include "../headers/Engine.h"
//#define db
//#define test3

void Engine::BeginSession(int& resolution, SDL_Window* window) {
	board = new Board(m_blockResolution, window);
}

void Engine::Update() {
	DropLogic();
	board->UpdateVectors();
	board->CollisionCheck();
	//board->currentPiece->UpdateRadius(board->occupiedSquares);
}

void Engine::Render(SDL_Renderer* renderer) {
	SDL_RenderClear(renderer);
	board->DrawBoard();
	SDL_RenderPresent(renderer);
}
int times = 1;
void Engine::DropLogic() {
	//Use this later to scramble the bag.
	//board->AddPiece("Long");
	
	if (board)
		if (board->dropPiece) {
#ifdef test1
			++times;
			switch (times) {
			case 0:
				board->AddPiece("Long");
				break;
			case 1:
				board->AddPiece("Long");
				break;
			case 2:
				board->AddPiece("Long");
				break;
			case 3:
				board->AddPiece("Long");
				break;
			case 4:
				board->AddPiece("Square");
				break;
			case 5:
				board->AddPiece("T");
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
#endif
#ifdef test2
			++times;
			switch (times) {
			case 0:
				board->AddPiece("Long");
				break;
			case 1:
				board->AddPiece("Long");
				break;
			case 2:
				board->AddPiece("Long");
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
				board->AddPiece("Long");
				break;
			case 8:
				board->AddPiece("Square");
				break;
			case 9:
				times = -1;
				break;
			default:
				break;
			}
#endif
#ifdef test3
			++times;
			switch (times) {
			case 0:
				board->AddPiece("Long");
				break;
			case 1:
				times = -1;
				break;
			default:
				break;
			}

#else

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
#endif
			//board->AddPiece("R");

		}


}
void Engine::MoveBlockDown() {
	if (!Freeze)
		board->MoveDown();

}



