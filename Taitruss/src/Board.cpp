#include "../headers/Board.h"
#include <iostream>
#include <algorithm>

void Board::AddPiece(std::string type) {
	dropPiece = false;

	if (type == "Square") {
		currentType = type;

		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0 || s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2) - 1 ||
					s.xLocation == (WIDTH / 2)) {
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}
	if (type == "Long") {
		currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0) {
				if (s.xLocation == (WIDTH / 2) - 2 ||
					s.xLocation == (WIDTH / 2) - 1 ||
					s.xLocation == WIDTH / 2 ||
					s.xLocation == (WIDTH / 2) + 1) {
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}
	if (type == "R") {
		currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0) {
				if (s.xLocation == (WIDTH / 2) - 1) { //top left
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}

			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2)) {
					s.isCenter = true;
				}
			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2) - 1 || //mid left
					s.xLocation == WIDTH / 2 ||    //mid
					s.xLocation == (WIDTH / 2) + 1) { //mid right
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}
	if (type == "L") {
		currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0) {
				if (s.xLocation == (WIDTH / 2) + 1) { //top right
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}

			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2)) {
					s.isCenter = true;
				}
			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2) - 1 || //mid left
					s.xLocation == WIDTH / 2 ||    //mid
					s.xLocation == (WIDTH / 2) + 1) { //mid right
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}
	if (type == "S") {
		currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0) {
				if (s.xLocation == (WIDTH / 2) ||  //top center
					s.xLocation == (WIDTH / 2) + 1) {  //top right
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}

			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2)) {
					s.isCenter = true;
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";

				}
			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2) - 1) { //mid left
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}
	if (type == "Z") {
		currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0) {
				if (s.xLocation == (WIDTH / 2) ||  //top center
					s.xLocation == (WIDTH / 2) - 1) {  //top left
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}

			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2)) {
					s.isCenter = true;
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";

				}
			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2) + 1) { //mid right
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}
			}
		}
	}

	if (type == "T") {
		currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : squareObjects) {
			if (s.yLocation == 0) {
				if (s.xLocation == (WIDTH / 2)) { //top center
					s.type = type;
					s.isOccupied = true;
					s.facing = "N";
				}

			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2)) {
					s.isCenter = true;
				}
			}
			if (s.yLocation == 1) {
				if (s.xLocation == (WIDTH / 2) - 1 || //mid left
					s.xLocation == WIDTH / 2 ||    //mid
					s.xLocation == (WIDTH / 2) + 1) { //mid right
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

		first = nullptr;
		last = nullptr;
		PauseUpdate();
		RotateLogicFor_Long_Shape(currentFacing, pieceHeight, pieceWidth, middleXAxis, middleYAxis);
		ResumeUpdate();
	}
	else if (currentType == "R") {
		PauseUpdate();
		RotateLogicFor_R_Shape();
		ResumeUpdate();
	}
	else if (currentType == "L") {
		PauseUpdate();
		RotateLogicFor_L_Shape();
		ResumeUpdate();
	}
	else if (currentType == "T") {
		PauseUpdate();
		RotateLogicFor_T_Shape();
		ResumeUpdate();
	}
	else if (currentType == "S") {
		PauseUpdate();
		RotateLogicFor_S_Shape();
		ResumeUpdate();
	}
	else if (currentType == "Z") {
		PauseUpdate();
		RotateLogicFor_Z_Shape();
		ResumeUpdate();
	}


}
void Board::PauseUpdate() {
	pauseUpdate = true;
}
void Board::ResumeUpdate() {
	pauseUpdate = false;
}
void Board::RotateLogicFor_Long_Shape(std::string _facing, int pieceHeight, int pieceWidth, int middleXAxis, int middleYAxis) {
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

	//PrintB();
	rotated = false;
}

void Board::RotateLogicFor_R_Shape()
{
	ClearSquares();
	Square* centerSquare = Square::FindCenterSquare(occupiedSquares);
	if (rotated) {
		return;
	}
	if (currentFacing == "N") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation - 1 ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "E";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}


		}

	}
	else if (currentFacing == "E") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation + 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "S";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	//
	else if (currentFacing == "S") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 ||
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation + 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "W";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	else if (currentFacing == "W") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation - 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "N";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	rotated = false;
}

void Board::RotateLogicFor_L_Shape()
{
	ClearSquares();
	Square* centerSquare = Square::FindCenterSquare(occupiedSquares);
	if (rotated) {
		return;
	}
	if (currentFacing == "N") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 || //top
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation + 1 ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //mid
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "E";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}


		}

	}
	else if (currentFacing == "E") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation + 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "S";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	//
	else if (currentFacing == "S") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 ||
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation - 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "W";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	else if (currentFacing == "W") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation - 1) {
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "N";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	rotated = false;
}

void Board::RotateLogicFor_T_Shape()
{

	ClearSquares();
	Square* centerSquare = Square::FindCenterSquare(occupiedSquares);
	if (rotated) {
		return;
	}
	if (currentFacing == "N") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||//TOP
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 || //BOTTOM
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation) { //RIGHT
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "E";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}


		}

	}
	else if (currentFacing == "E") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 ||//BOTTOM
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation || //LEFT
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation)//RIGHT {
			{
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "S";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}

	//
	else if (currentFacing == "S") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||//LEFT
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 ||//BOTTOM
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1) { //TOP
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "W";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	else if (currentFacing == "W") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||//TOP
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||//LEFT
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation) {//RIGHT
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "N";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	rotated = false;
}

void Board::RotateLogicFor_S_Shape()
{

	ClearSquares();
	Square* centerSquare = Square::FindCenterSquare(occupiedSquares);
	if (rotated) {
		return;
	}
	if (currentFacing == "N") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||//RIGHT
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation + 1 || //RIGHT BOTTOM
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1) { //TOP
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "E";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}


		}

	}
	else if (currentFacing == "E") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||//RIGHT
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 || //BOTTOM
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation + 1)//BOTTOMLEFT 
			{
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "S";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}

	//
	else if (currentFacing == "S") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation - 1 ||//TOP LEFT
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 ||//BOTTOM
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation) { //LEFT
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "W";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	else if (currentFacing == "W") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||//TOP
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||//LEFT
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation - 1) {// TOP RIGHT
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "N";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	rotated = false;
}
void Board::RotateLogicFor_Z_Shape()
{

	ClearSquares();
	Square* centerSquare = Square::FindCenterSquare(occupiedSquares);
	if (rotated) {
		return;
	}
	if (currentFacing == "N") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||//RIGHT
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation - 1 || //TOP RIGHT
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) { //BOTTOM
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "E";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}


		}

	}
	else if (currentFacing == "E") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation ||//LEFT
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1 || //BOTTOM
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation + 1)//BOTTOMRIGHT 
			{
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "S";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}

	//
	else if (currentFacing == "S") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||//TOP
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation + 1 ||//BOTTOM LEFT
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation) { //LEFT
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "W";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	else if (currentFacing == "W") {
		for (auto& s : squareObjects) {
			if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation || //CENTER
				s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation - 1 ||//TOP
				s.xLocation == centerSquare->xLocation + 1 && s.yLocation == centerSquare->yLocation ||//RIGHT
				s.xLocation == centerSquare->xLocation - 1 && s.yLocation == centerSquare->yLocation - 1) {// TOP LEFT
				s.isOccupied = true;
				s.type = currentType;
				s.facing = "N";
				rotated = "true";
				if (s.xLocation == centerSquare->xLocation && s.yLocation == centerSquare->yLocation + 1) {
					s.isCenter = true;
				}
			}
		}
	}
	rotated = false;
}

void Board::CheckClearRow()
{
	std::vector<std::vector<Square*>> rows;
	//Check each row
	for (int r = 0; r < HEIGHT; r++)
	{
		std::vector<Square*> row;
		//if yposition==HEIGHT
		// count amount of xPositions that are filled in that height
		//if count>WIDTH
		//CLEAR ROW
		for (int c = 0; c < WIDTH; c++)
		{
			int index = r * WIDTH + c;
			if (index < squareObjects.size()) {
				row.push_back(&squareObjects[index]);
				std::cout << "Y: " << squareObjects[index].yLocation << " | " << "X: " << squareObjects[index].xLocation << "\n";

			}
		}
		rows.push_back(row);
	}

	//std::cout << rows.size() * rows[0].size() << "   " << squareObjects.size() << std::endl;
	int clearIndex = 0;
	std::vector<std::vector<Square*>> rowsToClear;
	for (auto& row : rows) {
		++clearIndex;
		int occupiedInRow = 0;
		for (auto& column : row) {
			if (column->isPlaced) {
				occupiedInRow++;
			}
			if (occupiedInRow == WIDTH) {
				auto it = std::find(rowsToClear.begin(), rowsToClear.end(), row);
				if (it == rowsToClear.end()) {
					rowsToClear.push_back(row);
				}
				//ClearRow(row, clearIndex);
				std::cout << "OCCUPIED IN ROW " << occupiedInRow << "\n";
			}
		}
	}
	//clear all rowsToClear
	for (auto& r : rowsToClear)
	{
		ClearRow(r, clearIndex-1);
	}


}

void Board::ClearRow(std::vector<Square*>& rowToClear, int index) {
	std::cout << "CLEARING ROW \n";
	for (auto& s : rowToClear) {
		s->isPlaced = false;
		s->type = "Blank";
		s->facing = "NA";
	}
	//PrintB();
	//SOMEWHERE IN THIS LOGIC LIES THE PROBLEM
	UpdateVectors();
	//std::cout <<"Size of placed vec" << placedSquares.size() << "\n";
	MovePlacedDown(index);
	//UP THERE
}
void Board::MovePlacedDown(int index) {
	std::cout << "Moving down \n";
	PauseUpdate();
	//clear all squares above the cleared row.
	ClearPlaced(index);
	/*ResumeUpdate();
	return;*/

	//use those cleared square's location data to activate the tile's directly beneath
	for (auto& s : squareObjects) {
		for (auto& ps : placedSquares) {
			/*if (ps->yLocation >= index) {
				ps->isPlaced = true;
			}*/
			if (s.xLocation == ps->xLocation && s.yLocation == ps->yLocation + 1
				&& ps->yLocation <= index) {
				s.isPlaced = true;
				s.type = ps->type;
				s.facing = currentFacing;
			}
		}
	}
	ResumeUpdate();


}

void Board::ClearSquares() {
	for (auto& os : occupiedSquares) {
		if (os->isPlaced == false)
			os->isOccupied = false;

	}
}
void Board::ClearPlaced(int index) {
	int cnt = 0;
	std::cout << "Index:" << index << " Height:" << HEIGHT << "\n";
	for (auto& os : placedSquares) {
		cnt++;
		if (os->isPlaced && os->yLocation < index) {
			os->isPlaced = false;
		}
	}
	std::cout << cnt << " <-- amount of placed to clear\n";
}

bool Board::CanMove(std::string dir) {
	if (dir == "Right") {
		for (auto& s : occupiedSquares) {
			if (s->xLocation + 1 == WIDTH && !s->isPlaced) {
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
	else if (dir == "Left") {
		for (auto& s : occupiedSquares) {
			if (s->xLocation - 1 == -1 && !s->isPlaced) {
				return false;
			}
		}
		for (int i = 0; i < squareObjects.size(); i++) {
			for (int y = 0; y < squareObjects.size(); y++)
			{
				if (squareObjects[i].isOccupied) {
					if (squareObjects[i].yLocation == squareObjects[y].yLocation) {
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
	else if (dir == "Down") {
		for (auto& s : occupiedSquares) {
			if (s->yLocation + 1 == HEIGHT) {
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
	PauseUpdate();
	//check if can move direction

	if (dir == "Left" && CanMove("Left")) {
		ClearSquares();
		for (auto& s : squareObjects) {
			for (auto& os : occupiedSquares) {
				if (s.xLocation == os->xLocation - 1 && s.yLocation == os->yLocation) {

					s.isOccupied = true;
					s.type = currentType;
					s.facing = currentFacing;
					if (os->isCenter) {
						s.isCenter = true;
						os->isCenter = false;
					}
				}

			}
		}

		//return;
	}
	else if (dir == "Right" && CanMove("Right")) {
		ClearSquares();
		for (auto& s : squareObjects) {
			for (auto& os : occupiedSquares) {
				if (s.xLocation == os->xLocation + 1 && s.yLocation == os->yLocation) {
					if (os->isCenter) {
						s.isCenter = true;
						os->isCenter = false;
					}
					s.isOccupied = true;
					s.type = currentType;
					s.facing = currentFacing;
				}
			}
		}
		//return;

	}
	else if (dir == "Down" && CanMove("Down")) {
		MoveDown();
		//return;

	}
	ResumeUpdate();
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
				if (os->isCenter) {
					s.isCenter = true;
					os->isCenter = false;
				}

			}
		}
	}
	ResumeUpdate();
	//PrintB();
}
void Board::UpdateVectors() {
	//Find all occupied squares
	if (!pauseUpdate) {
		occupiedSquares.clear();
		placedSquares.clear();
		for (auto& s : squareObjects) {
			if (s.isPlaced) {
				placedSquares.push_back(&s);
			}
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
		allOccupiedSquares->isCenter = false;
		std::cout << "Placed\n";
	}
	CheckClearRow();
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
		if (!s.isOccupied && !s.isPlaced || s.type == "Blank") {
			TextureManager::Draw(BlankSquare, src, dest);
		}
		else {
			if (s.type == "Square") {
				TextureManager::Draw(BlueSquare, src, dest);
			}
			if (s.type == "Long") {
				TextureManager::Draw(YellowSquare, src, dest);
			}
			if (s.type == "R") {
				TextureManager::Draw(RedSquare, src, dest);
			}
			if (s.type == "L") {
				TextureManager::Draw(BlueSquare, src, dest);
			}
			if (s.type == "T") {
				TextureManager::Draw(YellowSquare, src, dest);
			}
			if (s.type == "S") {
				TextureManager::Draw(BlueSquare, src, dest);
			}
			if (s.type == "Z") {
				TextureManager::Draw(RedSquare, src, dest);
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
		if (i->isCenter) {
			std::cout << "| " << "C" << " |";
		}
		else if (i->isPlaced)
			std::cout << "| " << "*" << " |";
		else if (i->isOccupied && !i->isCenter)
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