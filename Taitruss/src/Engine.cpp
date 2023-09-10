#include "../headers/Engine.h"

void Engine::BeginSession(int resolution, SDL_Window* window) {
	board = new Board(resolution,window);
	DropLogic();
}

void Engine::Update() {
	if (board)
		if (board->dropPiece) {
			board->AddPiece("Long");
		}
	board->UpdatePositions();
	board->CollisionCheck();
}

void Engine::Render(SDL_Renderer* renderer) {
	SDL_RenderClear(renderer);
	board->DrawBoard();
	SDL_RenderPresent(renderer);
}
void Engine::DropLogic() {
	//Use this later to scramble the bag.
	board->AddPiece("Long");
}
void Engine::MoveBlockDown() {
	if (!Freeze)
		board->MoveDown();

}



