//Render a board
//Add a list of possible pieces. 
//Create a bag, containing all pieces
//shuffle the bag
//drop a piece
//ability to rotate
#include "../headers/Engine.h"

void Engine::BeginSession() {
	Board* board = new Board();
	board->CreateBoard();
	board->Print();
}