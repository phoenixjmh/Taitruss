#include "../headers/Board.h";
#include <iostream>;

#define LOG(x) std::cout<<x<<std::endl;
void Board::CreateBoard(SDL_Window* win) {
	//Add an instance of square class to every position in board
	//store location maybe in XY coord
	//square has boolean of if it's space is occupied
	SDL_GetWindowSize(win, &winWidth, &winHeight);

	std::cout << "Creating board here" << std::endl;
	for (size_t i = 0; i < this->HEIGHT; i++)
	{
		std::cout << std::endl;
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
	BlueSquare = TextureManager::LoadTexture("res/img/BlueSquare.png");
	YellowSquare = TextureManager::LoadTexture("res/img/YellowSquare.png");
}
void Board::AddPiece(std::string type) {
	if (type == "Square") {

		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			//Add top pieces of square
			//index through squareObjectsBasedOnHeight
			if (s.yLocation == 0 || s.yLocation == 1) {
				if (s.xLocation == (WIDTH/2)-1 || s.xLocation == (WIDTH/2)+1) {
					s.type = type;
					s.isOccupied = true;
				}
			}
		}
	}
	if(type=="Long"){
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			//Add top pieces of square
			//index through squareObjectsBasedOnHeight
			if (s.yLocation == 0 || s.yLocation == 1 || s.yLocation == 2 || s.yLocation == 3) {
				if (s.xLocation == WIDTH/2) {
					s.type = type;
					s.isOccupied = true;
				}
			}
		}
	}



		}
	void Board::RotatePiece() {
		//Clockwise Turn
		std::string _type;
		std::vector<Square*> occupiedPieces;
		for (auto& s : squareObjects)
		{
			if (s.isOccupied && !s.isPlaced) {
			occupiedPieces.push_back(&s);
			_type = s.type;
			}
		}

		Square* first = occupiedPieces.front();
		Square* last = occupiedPieces.back();
		std::cout << "First y position" << first->yLocation << " Last y position" << last->yLocation << std::endl;
		int pieceHeight = last->yLocation - first->yLocation+1;
		int middleYAxis = first->yLocation + (pieceHeight / 2);
		int pieceWidth = last->xLocation - first->xLocation+1;
		int middleXAxis = first->xLocation + (pieceWidth / 2);
		std::cout << "Middle X " << middleXAxis << std::endl;
		std::cout << "Middle Y " << middleYAxis << std::endl;
		std::cout << "piece Height" << pieceHeight << "Piece width" << pieceWidth << std::endl;


	 

		for (auto& s : squareObjects) {
			if (/*s.isOccupied && */!s.isPlaced) {
				s.isOccupied = false;
				//for rotating clockwise vert to hori
				if (pieceHeight > pieceWidth) {
				if (s.yLocation == middleYAxis) {
					if (s.xLocation >= middleXAxis - (pieceHeight / 2) && s.xLocation <= middleXAxis-1 + (pieceHeight / 2)) {
						std::cout << "Found one @" << middleXAxis << std::endl;
						s.isOccupied=true;
						s.type = _type;
					}

				}

				}
				if (pieceWidth > pieceHeight) {
					if (s.xLocation == middleXAxis) {
						if (s.yLocation >= middleYAxis - (pieceWidth / 2) && s.yLocation <= middleYAxis - 1 + (pieceWidth / 2)) {
							std::cout << "Found one @" << middleXAxis << std::endl;
							s.isOccupied = true;
							s.type = _type;
						}
					}
				}
				//deactivate current positions
				
			}
		}

}
		void Board::MoveDown() {
			std::vector<Square*> occupiedSquares;
			std::string _type;
			//Find all occupied squares
			for (auto& s : squareObjects) {

				if (s.isOccupied && !s.isPlaced) {
					_type = s.type;
					occupiedSquares.push_back(&s);
					s.isOccupied = false;
				}
			}
			//push all occupied squares down one piece  
			//for every square, if it's location is directly below an occupied square,
			//we  call it as occupied
			for (auto& s : squareObjects) {
				for (auto& os : occupiedSquares) {
					if (s.xLocation == os->xLocation && s.yLocation == os->yLocation + 1) {
						if (s.yLocation + 1 == HEIGHT||s.yLocation==HEIGHT) {
							std::cout << "HIT BOTTOM";
							s.isPlaced = true;
							for (auto& allOccupiedSquares : occupiedSquares) {
								allOccupiedSquares->isPlaced = true;
							}
						}

						s.isOccupied = true;
						s.type = _type;



					}
				}
			}
			//   

		}


		void Board::DrawBoard() {
			for (auto& s : squareObjects) {

				int centeredStartX = (winWidth / 2) + (s.xLocation * this->resolution) - ((WIDTH * 32) / 2);
				int centeredStartY = (winHeight / 2) + (s.yLocation * this->resolution) - ((HEIGHT * 32) / 2);
				dest.x = centeredStartX;
				dest.y = centeredStartY;
				if (!s.isOccupied) {
					TextureManager::Draw(BlankSquare, src, dest);

				}
				else {
					if (s.type == "Square") {
						TextureManager::Draw(BlueSquare, src, dest);
					}
					if (s.type == "Long") {
						TextureManager::Draw(YellowSquare, src, dest);
					}
				}


			}
		}
		void Board::Print() {
			for (auto i = this->squareObjects.begin(); i != this->squareObjects.end(); ++i) {
				std::cout << i->xLocation << i->yLocation << std::endl;
			}
		}

		void Board::PrintB() {
			for (auto i = this->squareObjects.begin(); i != this->squareObjects.end(); ++i) {
				std::cout << "| " << i->isOccupied << " |" << std::endl;
			}
		}