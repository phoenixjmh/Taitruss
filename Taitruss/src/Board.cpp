#include "../headers/Board.h";
#include <iostream>;

void Board::CreateBoard(SDL_Window* win) {
	//Add an instance of square class to every position in board
	//store location maybe in XY coord
	//square has boolean of if it's space is occupied
	SDL_GetWindowSize(win, &winWidth, &winHeight);
	
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
	this->resolution = resolution;
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	BlankSquare = TextureManager::LoadTexture("res/img/BlankSquare.png");
}

void Board::DrawBoard() {
	for (auto& s : squareObjects) {
		int centeredStartX = (winWidth / 2) + (s.xLocation * this->resolution) - ((WIDTH * 32) / 2);
		int centeredStartY = (winHeight / 2 )+ (s.yLocation * this->resolution) - ((HEIGHT*32)/2);
		dest.x = centeredStartX;
		dest.y = centeredStartY;
		TextureManager::Draw(BlankSquare,src,dest);
	}
}
void Board::Print() {
	for (auto i = this->squareObjects.begin(); i != this->squareObjects.end(); ++i) {
		std::cout << i->xLocation<<i->yLocation<<std::endl;
	}
}