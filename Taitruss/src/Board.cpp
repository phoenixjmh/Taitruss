#include "../headers/Board.h"
#include <iostream>
#include <algorithm>

void Board::CreateBoard(SDL_Window* win) {

	SDL_GetWindowSize(win, &winWidth, &winHeight);

	std::cout << "Creating board here" << std::endl;
	for (int i = 0; i < this->HEIGHT; i++)
	{
		std::cout << std::endl;
		for (int y = 0; y < WIDTH; y++)
		{
			Square square(y,i);
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
	if (rotated)
		return;

	if (_facing == "N") {
		for (auto& s : squareObjects) {
			if (!s.isPlaced)
				s.isOccupied = false;
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

	else if (_facing == "E") {
		for (auto& s : squareObjects) {
			if (!s.isPlaced) {
				s.isOccupied = false;

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
	else if (_facing == "S") {
		for (auto& s : squareObjects) {
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
	else if (_facing == "W") {
		for (auto& s : squareObjects) {
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

	PrintB();
	rotated = false;
}

void Board::ClearSquares() {
	for (auto& os : occupiedSquares) {
		if (os->isPlaced == false)
			os->isOccupied = false;
	}
}
bool Board::CanMove(std::string dir) {
	if (dir == "Right") {
		for (auto& s : occupiedSquares) {
			if (s->xLocation + 1 == WIDTH&&!s->isPlaced) {
				return false;
			}
		}
		for (int i = 0; i < squareObjects.size(); i++) {
			for (int y = 0; y < squareObjects.size(); y++)
			{
			if (squareObjects[i].isOccupied) {
				if (squareObjects[i].yLocation == squareObjects[y].yLocation) {
					if (squareObjects[i].xLocation + 1 == squareObjects[y].xLocation) {
						if (squareObjects[y].isPlaced) {
							return false;
						}
					}
				}
			}

			}
		}

	}
	if (dir == "Left") {
		for (auto& s : occupiedSquares) {
			if (s->xLocation - 1 == -1&&!s->isPlaced) {
				return false;
			}
		}
		for (int i = 0; i < squareObjects.size(); i++) {
			for (int y = 0; y < squareObjects.size(); y++)
			{
				if (squareObjects[i].isOccupied) {
					if(squareObjects[i].yLocation==squareObjects[y].yLocation){
					if (squareObjects[i].xLocation - 1 == squareObjects[y].xLocation) {
						if (squareObjects[y].isPlaced) {
							return false;
						}
					}

					}
				}

			}
		}

	}
	if (dir == "Down") {
		for (auto& s : occupiedSquares) {
			if (s->yLocation + 1 == HEIGHT ) {
				return false;
			}
		}
		for (int i = 0; i < squareObjects.size(); i++) {
			for (int y = 0; y < squareObjects.size(); y++)
			{
				if (squareObjects[i].isOccupied) {
					if (squareObjects[i].xLocation == squareObjects[y].xLocation) {
						if (squareObjects[i].yLocation + 1 == squareObjects[y].yLocation) {
							if (squareObjects[y].isPlaced) {
								return false;
							}
						}

					}
				}

			}
		}

	}

	return true;
}

void Board::Move(std::string dir) {
	//check if can move direction

	if (dir == "Left"&&CanMove("Left")) {
	ClearSquares();
		for (auto& s : squareObjects) {
			for (auto& os : occupiedSquares) {
				if (s.xLocation == os->xLocation - 1 && s.yLocation == os->yLocation) {
					s.isOccupied = true;
					s.type = currentType;
					s.facing = currentFacing;
				}
			}
		}


	}
	else if (dir == "Right"&&CanMove("Right")) {
	ClearSquares();
		for (auto& s : squareObjects) {
			for (auto& os : occupiedSquares) {
				if (s.xLocation == os->xLocation + 1 && s.yLocation == os->yLocation) {
					s.isOccupied = true;
					s.type = currentType;
					s.facing = currentFacing;
				}
			}
		}

	}
	else if (dir == "Down"&&CanMove("Down")) {
		MoveDown();

	}
}
void Board::MoveDown() {
	//push all occupied squares down one piece  
	//for every square, if it's location is directly below an occupied square,
	//we  call it as occupied
	PauseUpdate();
	placed = false;
	ClearSquares();
	//use those cleared square's location data to activate the tile's directly beneath
	for (auto& s : squareObjects) {
		for (auto& os : occupiedSquares) {
			if (s.xLocation == os->xLocation && s.yLocation == os->yLocation + 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = currentFacing;
			}
		}
	}
	ResumeUpdate();
}
void Board::UpdatePositions() {
	//Find all occupied squares
	if (!pauseUpdate) {
		occupiedSquares.clear();
		for (auto& s : squareObjects) {

			if (s.isOccupied && !s.isPlaced) {
				currentType = s.type;
				currentFacing = s.facing;
				auto it = std::find(occupiedSquares.begin(), occupiedSquares.end(), &s);
				if (it == occupiedSquares.end())
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
			if (squareObjects[i].yLocation == HEIGHT - 1 && squareObjects[i].isOccupied && squareObjects[i].isPlaced == false) {
				if (!placed)
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
		allOccupiedSquares->isOccupied = false;
		std::cout << "Placed\n";
	}
	dropPiece = true;
	for (auto& allOccupiedSquares : occupiedSquares) {
		std::cout << allOccupiedSquares->isPlaced << "\n";
	}
}
void Board::DrawBoard() {
	for (auto& s : squareObjects) {

		int centeredStartX = (winWidth / 2) + (s.xLocation * this->resolution) - ((WIDTH * 32) / 2);
		int centeredStartY = (winHeight / 2) + (s.yLocation * this->resolution) - ((HEIGHT * 32) / 2);
		dest.x = centeredStartX;
		dest.y = centeredStartY;
		if (!s.isOccupied&&!s.isPlaced) {
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