#include "../headers/Board.h";
#include "../headers/Square.h"
#include <iostream>;

void Board::CreateBoard() {
	//Add an instance of square class to every position in board
	//store location maybe in XY coord
	//square has boolean of if it's space is occupied
	
	std::cout << "Creating board here" << std::endl;
	for (size_t i = 0; i <this->HEIGHT ; i++)
	{
		std::cout<<std::endl;
		for (size_t y = 0; y < WIDTH; y++)
		{
			Square square;
			square.init(y, i);
			this->squareObjects.push_back(square);
			//std::cout << this->squares[i][y];
		}
	}
}
void Board::Print() {
	for (auto i = this->squareObjects.begin(); i != this->squareObjects.end(); ++i) {
		std::cout << i->xLocation<<i->yLocation<<std::endl;
	}
}