#include "../headers/Board.h";
#include <iostream>;
#include <algorithm>;

void Board::CreateBoard(SDL_Window* win) {

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
		}
	}
	this->resolution = resolution;
	src.x = src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	
	rotated = false;
}
void Board::AddPiece(std::string type) {
	dropPiece = false;
	
	if (type == "Square") {

		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0 || s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2) - 1 || s.xLocation == (WIDTH / 2) + 1) {
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}
	if (type == "Long") {
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0) {
				if (s.xLocation == (WIDTH / 2) - 2 || s.xLocation == (WIDTH / 2) - 1 || s.xLocation == WIDTH / 2 || s.xLocation == (WIDTH / 2) + 1) {
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}



}

void Board::RotatePiece() {
	std::cout << currentType << "TYPE in ROTATE\n";
	//Clockwise Turn
	
	
	
	if (currentType == "Long") {
		Square* first = occupiedSquares.front();
		Square* last = occupiedSquares.back();
		
		std::cout << "First y position" << first->yLocation << " Last y position" << last->yLocation << std::endl;
		int pieceHeight = last->yLocation - first->yLocation + 1;
		int middleYAxis = first->yLocation + (pieceHeight / 2);
		int pieceWidth = last->xLocation - first->xLocation + 1;
		int middleXAxis = first->xLocation + (pieceWidth / 2);
		PauseUpdate();
		RotateLogicForLong(currentFacing, pieceHeight, pieceWidth, middleXAxis, middleYAxis);
		ResumeUpdate();
	}


}
void Board::PauseUpdate() {
	pauseUpdate = true;
}
void Board::ResumeUpdate() {
	pauseUpdate = false;
}
void Board::RotateLogicForLong(std::string _facing, int pieceHeight, int pieceWidth, int middleXAxis, int middleYAxis) {

	if (!rotated) {


		std::cout << occupiedSquares.size() << "BEFORE ROTATE \n";
		for (auto& s : squareObjects) {
			if (/*s.isOccupied && */!s.isPlaced)
				s.isOccupied = false;

			if (_facing == "N") {

				if (s.xLocation == middleXAxis) {
					if (s.yLocation >= middleYAxis + 1 - (pieceWidth / 2) && s.yLocation <= middleYAxis + (pieceWidth / 2)) {

						s.isOccupied = true;
						s.type = currentType;
						s.facing = "E";
						rotated = true;
						std::cout << "Rotated\n";
						continue;
					}
				}
			}
		}

	}

	if (!rotated) {
		for (auto& s : squareObjects) {
			if (!s.isPlaced) {
				s.isOccupied = false;
				if (_facing == "E") {

					if (s.yLocation == middleYAxis) {
						if (s.xLocation >= middleXAxis - (pieceHeight / 2) && s.xLocation <= middleXAxis - 1 + (pieceHeight / 2)) {

							s.isOccupied = true;
							s.type = currentType;
							s.facing = "S";

							rotated = true;
						}

					}
				}
			}
		}
	}
	if (!rotated) {

		for (auto& s : squareObjects) {
			if (_facing == "S") {
				s.isOccupied = false;

				if (s.xLocation + 1 == middleXAxis) {
					if (s.yLocation >= middleYAxis - (pieceWidth / 2) && s.yLocation <= middleYAxis - 1 + (pieceWidth / 2)) {

						s.isOccupied = true;
						s.type = currentType;
						s.facing = "W";
						rotated = true;
					}
				}
			}
		}
	}
	if (!rotated) {
		for (auto& s : squareObjects) {
			if (_facing == "W") {
				s.isOccupied = false;

				if (s.yLocation + 1 == middleYAxis) {
					if (s.xLocation >= middleXAxis + 1 - (pieceHeight / 2) && s.xLocation <= middleXAxis + (pieceHeight / 2)) {

						s.isOccupied = true;
						s.type = currentType;
						s.facing = "N";
						rotated = true;
					}


				}
			}
		}
	}
	PrintB();
	rotated = false;
	std::cout << occupiedSquares.size()<<"SIZE IN ROTATE\n";
}

void Board::MoveDown() {
	

	//push all occupied squares down one piece  
	//for every square, if it's location is directly below an occupied square,
	//we  call it as occupied
	PauseUpdate();
	std::cout << occupiedSquares.size() << " SIZE AT MOVE \n";
	placed = false;
	//clear current squares
	for (auto& os : occupiedSquares) {
		if (os->isPlaced == false)
		os->isOccupied = false;
	}
	//use those cleared square's location data to activate the tile's directly beneath
	for (auto& s : squareObjects) {
		for (auto& os : occupiedSquares) {
			if (s.xLocation == os->xLocation && s.yLocation == os->yLocation + 1) {
				std::cout << "MOVING DOWN" << s.yLocation << "\n";
				s.isOccupied = true;
				s.type = currentType;
				s.facing = currentFacing;



			}
			
		}
	}
	

	

	
	//   
	Print();
	ResumeUpdate();
}
void Board::UpdatePositions() {
	//Find all occupied squares
	if (!pauseUpdate) {
		//std::cout << "UPDATING POSITIONS" << occupiedSquares.size() << "SIZE AT START\n";
		occupiedSquares.clear();
	for (auto& s : squareObjects) {

		if (s.isOccupied && !s.isPlaced) {
			currentType = s.type;
			currentFacing = s.facing;
			auto it = std::find(occupiedSquares.begin(), occupiedSquares.end(), &s);
			if(it==occupiedSquares.end())
			occupiedSquares.push_back(&s);

		}
		else if (!s.isOccupied && !s.isPlaced) {
			s.facing = "NA";
		}
	}
	
	}
}
void Board::CollisionCheck() {
	for (auto i = 0; i < squareObjects.size(); i++) {
		if (i > WIDTH * 2) {
			if (squareObjects[i].yLocation == HEIGHT - 1 && squareObjects[i].isOccupied&&squareObjects[i].isPlaced==false) {
				if(!placed)
				PlacePiece();
			}
			//if this block is placed
			if (squareObjects[i].isPlaced && squareObjects[i - WIDTH].isPlaced == false) {
				//check if block above is occupied and not placed
				if (squareObjects[i - WIDTH].isOccupied) {
					std::cout << "Collision\n";
					PlacePiece();
				}


			}

		}
	}

}
void Board::PlacePiece() {
	std::cout << "Place\n";
		placed = true;
	
	for (auto& allOccupiedSquares : occupiedSquares) {
		allOccupiedSquares->isPlaced = true;
		std::cout << "Placed\n";
	}
	dropPiece = true;
	for (auto& allOccupiedSquares : occupiedSquares) {
		std::cout<<allOccupiedSquares->isPlaced<<"\n";
	}
	
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
	int counter = 0;
	for (auto& os : occupiedSquares) {
		std::cout << ++counter << "OS COUNTER\n";
	}
}

void Board::PrintB() {
	int counter = 0;
	std::cout << "----------------------------------" << std::endl;
	for (auto i = this->squareObjects.begin(); i != this->squareObjects.end(); ++i) {
		counter++;
		if (i->isPlaced)
			std::cout << "| " << "*" << " |";
		else if (i->isOccupied)
			std::cout << "| " << i->facing << " |";
		else
			std::cout << "| " << "O" << " |";
		if (counter >= WIDTH) {
			std::cout << std::endl;
			counter = 0;
		}
	}
	std::cout << "----------------------------------" << std::endl;

}