#include "../headers/Board.h"
#include <iostream>
#include <algorithm>
#include "../headers/Engine.h"


void Board::AddPiece(ALL_PIECES type) {
	dropPiece = false;
	if (type == SQUARE) {
		m_currentType = type;

		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : m_squareObjects) {
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
	if (type == LONG) {
		m_currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : m_squareObjects) {
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


	if (type == R_PIECE) {
		m_currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : m_squareObjects) {
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
	if (type == L_PIECE) {
		m_currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : m_squareObjects) {
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
	if (type == S_PIECE) {
		m_currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : m_squareObjects) {
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
	if (type == Z_PIECE) {
		m_currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : m_squareObjects) {
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

	if (type == T_PIECE) {
		m_currentType = type;
		std::cout << "Added " << type << " to board" << std::endl;
		for (auto& s : m_squareObjects) {
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

	UpdateVectors();
	if (type != BLANK && m_occupiedSquares.size() > 0 && m_squareObjects.size() > 0)
		m_currentPiece = new Piece(type, "N", m_occupiedSquares, m_squareObjects, WIDTH, HEIGHT);
	else {
		std::cout << "ERROR::Failed to create 'Piece' in Board::AddPiece function::ERROR\n";
		std::cout << "TYPE: " << type << " OCCUPIED SQUARES SIZE: " << m_occupiedSquares.size() << " ALLSQUARES SIZE: " << m_squareObjects.size() << "\n";
	}
}



void Board::RotatePiece() {
	//Clockwise Turn
	if(m_currentPiece!=nullptr)
	{
	if (m_currentPiece->CanRotate(m_currentType, m_currentFacing, m_occupiedSquares, m_squareObjects, WIDTH, HEIGHT)) {

		if (m_currentType == LONG) {
			PauseUpdate();
			m_currentPiece->RotateLong(m_occupiedSquares, m_squareObjects);
			ResumeUpdate();
		}
		else if (m_currentType != LONG) {
			PauseUpdate();
			m_currentPiece->Rotate();
			m_currentPiece->RefreshPiece();
			ResumeUpdate();

		}


	}
	else std::cout << "CANNOT ROTATE\n";
	}
}


/// <summary>
/// Assign tiles to row, then loop through and check if all in row are placed.
///	If full row is placed, clear it, passing in the yposition, for dropping the 
///	pieces above it, and the amount of rows to clear to the MovePlacedDown function
/// </summary>
void Board::CheckClearRow()
{

	std::vector<std::vector<Tile*>> rows;
	for (int r = 0; r < HEIGHT; r++)
	{
		std::vector<Tile*> row;
		for (int c = 0; c < WIDTH; c++)
		{
			int index = r * WIDTH + c;
			if (index < m_squareObjects.size()) {
				row.push_back(&m_squareObjects[index]);
			}
		}
		rows.push_back(row);
	}

	int clear_index = 0;
	std::vector<std::vector<Tile*>> rowsToClear;
	for (auto& row : rows) {
		int occupiedInRow = 0;
		for (const auto& column : row) {
			if (column->isPlaced) {
				occupiedInRow++;
			}
			if (occupiedInRow == WIDTH) {
				auto it = std::find(rowsToClear.begin(), rowsToClear.end(), row);
				if (it == rowsToClear.end()) {
					rowsToClear.push_back(row);
					clear_index = column->yLocation;
				}
				std::cout << "OCCUPIED IN ROW " << occupiedInRow << "\n";
			}
		}
	}
	if(rowsToClear.size()<=0)
	{
		return;
	}
	std::cout << "INDEX TO DELETE TO" << clear_index << "\n";
	//clear all rowsToClear
	for (auto& r : rowsToClear)
	{
		ClearRow(r, clear_index - 1);
		m_engine->scoreBoard->AddPoint();
	}
	const int times_to_move = rowsToClear.size();

	MovePlacedDown(clear_index, times_to_move);
}

void Board::ClearRow(const std::vector<Tile*>& row_to_clear, int index) {
	std::cout << "CLEARING ROW \n";
	int clearDelay = 20;
	int start =SDL_GetTicks();
	for (int i = 0; i < row_to_clear.size();) {
		row_to_clear[i]->isPlaced = false;
		row_to_clear[i]->type = BLANK;
		row_to_clear[i]->facing = "NA";
		int current = SDL_GetTicks();
		if(current-start>clearDelay)
		{
			i++;
			start = current;
		}
		m_engine->render();

	}
	/*for (auto& s : row_to_clear) {
		s->isPlaced = false;
		s->type = BLANK;
		s->facing = "NA";

	}*/

	UpdateVectors();


}
void Board::MovePlacedDown(int index, int times_to_move) {
	//Get highest cleared Y from index
	while (times_to_move > 0) {
		std::cout << "Moving down \n";
		PauseUpdate();
		ClearPlaced(index);
		for (auto& s : m_squareObjects) {
			for (auto& ps : placedSquares) {
				if (s.xLocation == ps->xLocation && s.yLocation == ps->yLocation + 1
					&& ps->yLocation <= index) {
					s.isPlaced = true;
					s.type = ps->type;
					s.facing = m_currentFacing;
				}
			}
		}
		ResumeUpdate();
		UpdateVectors();
		times_to_move--;
	}
	m_engine->gameSpeed -= 10;
}

void Board::ClearSquares() const
{
	for (auto& os : m_occupiedSquares) {
		if (os->isPlaced == false)
			os->isOccupied = false;

	}
}
void Board::ClearPlaced(int index) {
	int cnt = 0;
	std::cout << "Index:" << index << " Height:" << HEIGHT << "\n";
	for (const auto& os : placedSquares) {
		cnt++;
		if (os->isPlaced && os->yLocation < index) {
			os->isPlaced = false;
		}
	}
	std::cout << cnt << " <-- amount of placed to clear\n";
	ResumeUpdate();
}

bool Board::CanMove(std::string dir)
{

	if (dir == "Right") {
		for (auto& s : m_occupiedSquares) {
			if (s->xLocation + 1 == WIDTH && !s->isPlaced) {
				return false;
			}
		}
		for (const auto& i : m_squareObjects)
		{
			for (const auto& square_object : m_squareObjects)
			{
				if (i.isOccupied) {
					if (i.yLocation == square_object.yLocation) {
						if (i.xLocation + 1 == square_object.xLocation) {
							if (square_object.isPlaced) {
								return false;
							}
						}
					}
				}

			}
		}

	}
	else if (dir == "Left") {
		for (auto& s : m_occupiedSquares) {
			if (s->xLocation - 1 == -1 && !s->isPlaced) {
				return false;
			}
		}
		for (const auto& i : m_squareObjects)
		{
			for (const auto& square_object : m_squareObjects)
			{
				if (i.isOccupied) {
					if (i.yLocation == square_object.yLocation) {
						if (i.xLocation - 1 == square_object.xLocation) {
							if (square_object.isPlaced) {
								return false;
							}
						}

					}
				}

			}
		}

	}
	else if (dir == "Down") {
		for (auto& s : m_occupiedSquares) {
			if (s->yLocation + 1 == HEIGHT) {
				return false;
			}
		}
		for (const auto& square_object : m_squareObjects)
		{
			for (const auto& neighbor_square : m_squareObjects)
			{
				if (neighbor_square.isOccupied) {
					if (neighbor_square.xLocation == neighbor_square.xLocation) {
						if (neighbor_square.yLocation + 1 == neighbor_square.yLocation) {
							if (neighbor_square.isPlaced) {
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
	if(m_currentPiece!=nullptr){
	PauseUpdate();
	//check if can move direction
	if (dir == "Left" && CanMove("Left")) {
		ClearSquares();
		for (auto& s : m_squareObjects) {
			for (auto& os : m_occupiedSquares) {
				if (s.xLocation == os->xLocation - 1 && s.yLocation == os->yLocation) {

					s.isOccupied = true;
					s.type = m_currentType;
					s.facing = m_currentFacing;
					if (os->isCenter) {

						s.isCenter = true;
						os->isCenter = false;
					}
				}
			}
			m_currentPiece->UpdateRadius(m_occupiedSquares);
		}

		//return;
	}
	else if (dir == "Right" && CanMove("Right")) {
		bool moved_center = false;
		ClearSquares();

		for (auto& s : m_squareObjects) {
			for (const auto& os : m_occupiedSquares) {
				if (s.xLocation == os->xLocation + 1 && s.yLocation == os->yLocation) {
					s.isOccupied = true;
					s.type = m_currentType;
					s.facing = m_currentFacing;
					if (os->isCenter && !moved_center) {
						s.isCenter = true;
						os->isCenter = false;
						moved_center = true;
					}
				}
			}
		}
		m_currentPiece->UpdateRadius(m_occupiedSquares);
		//return;

	}
	else if (dir == "Down" && CanMove("Down")) {
		MoveDown();
		//return;

	}
	//currentPiece->Print();
	ResumeUpdate();
	}
}
void Board::MoveDown() {
	//push all occupied squares down one piece  
	//for every square, if it's location is directly below an occupied square,
	//we  call it as occupied
	if (placeOnNextTick)
		std::cout << "WILL MOVE DOWN " << placeOnNextTick << "\n";
	if (placeOnNextTick == false)
	{

		PauseUpdate();
		m_placed = false;
		ClearSquares();
		bool moved_center = false;
		//use those cleared square's location data to activate the tile's directly beneath
		for (auto& s : m_squareObjects) {
			for (const auto& os : m_occupiedSquares) {
				if (s.xLocation == os->xLocation && s.yLocation == os->yLocation + 1) {
					s.isOccupied = true;
					s.type = m_currentType;
					s.facing = m_currentFacing;
					if (os->isCenter && !moved_center) {
						s.isCenter = true;
						os->isCenter = false;
						moved_center = true;
					}
				}
			}
		}
		if (m_currentPiece != nullptr) {
			m_currentPiece->UpdateRadius(m_occupiedSquares);
		}

		//PrintRadius();
		//PrintB();
		ResumeUpdate();
	}
}
void Board::PauseUpdate() {
	m_pauseUpdate = true;
}
void Board::ResumeUpdate() {
	m_pauseUpdate = false;
}
void Board::UpdateVectors() {
	//Find all occupied squares
	if (!m_pauseUpdate) {
		m_occupiedSquares.clear();
		placedSquares.clear();
		for (auto& s : m_squareObjects) {
			if (s.isPlaced) {
				placedSquares.push_back(&s);
			}
			if (s.isOccupied && !s.isPlaced) {
				m_currentType = s.type;
				m_currentFacing = s.facing;
				auto it = std::find(m_occupiedSquares.begin(), m_occupiedSquares.end(), &s);
				if (it == m_occupiedSquares.end())
					m_occupiedSquares.push_back(&s);
			}
			else if (!s.isOccupied && !s.isPlaced) {
				s.facing = "NA";
				s.type = BLANK;
			}
		}
	}
}

bool Board::CanMoveDown()
{
	std::cout << "CHECKING UNDER\n";
	for (auto i = 0; i < m_squareObjects.size(); i++) {
		if (i > WIDTH * 2) {
			if (m_squareObjects[i].yLocation == HEIGHT - 1 && m_squareObjects[i].isOccupied && m_squareObjects[i].isPlaced == false) {
				if (!m_placed)
					return false;

			}

			//if this block is placed
			if (m_squareObjects[i].isPlaced && m_squareObjects[i - WIDTH].isPlaced == false) {
				//check if block above is occupied and not placed
				if (m_squareObjects[i - WIDTH].isOccupied) {
					//Wait for next tick, then place the piece.
					return false;
					//PlacePiece();
				}
			}
		}
	}
	return true;
}
void Board::CollisionCheck() {
	if (placeOnNextTick == false)
	{
		for (auto i = 0; i < m_squareObjects.size(); i++) {
			//Check gameOver
			if(i>0&&i<WIDTH)
			{
				if(m_squareObjects[i+WIDTH].isPlaced)
				{
					GAMEOVER = true;
				}
			}
			if (i > WIDTH * 2) {
				if (m_squareObjects[i].yLocation == HEIGHT - 1 && m_squareObjects[i].isOccupied && m_squareObjects[i].isPlaced == false) {
					if (!m_placed)
						placeOnNextTick = true;
					
				}

				//if this block is placed
				if (m_squareObjects[i].isPlaced && m_squareObjects[i - WIDTH].isPlaced == false) {
					//check if block above is occupied and not placed
					if (m_squareObjects[i - WIDTH].isOccupied) {
						std::cout << "Collision\n";
						//Wait for next tick, then place the piece.
						placeOnNextTick = true;
						//PlacePiece();
					}
				}
			}
		}
	}

}
void Board::PlacePiece() {
	placeOnNextTick = false;
	if (CanMoveDown())
	{
		MoveDown();
		return;
	}
	std::cout << "Place\n";
	m_placed = true;

 	for (const auto& all_occupied_squares : m_occupiedSquares) {
		all_occupied_squares->isPlaced = true;
		all_occupied_squares->isOccupied = false;
		all_occupied_squares->isCenter = false;
		std::cout << "Placed\n";
	}
	CheckClearRow();
	for (const auto& all_occupied_squares : m_occupiedSquares) {
		std::cout << all_occupied_squares->isPlaced << "\n";
	}
	dropPiece = true;
	placeOnNextTick = false;

}



void Board::DrawBoard() {
	for (auto& s : m_squareObjects) {
		const int centered_start_x = (winWidth / 2) + (s.xLocation * this->m_resolution) - ((WIDTH * this->m_resolution) / 2);
		const int centered_start_y = (winHeight / 2) + (s.yLocation * this->m_resolution) - ((HEIGHT * this->m_resolution) / 2);
		dest.x = centered_start_x;
		dest.y = centered_start_y;
		dest.w = this->m_resolution;
		dest.h = this->m_resolution;

		if (!s.isOccupied && !s.isPlaced || s.type == BLANK) {

			TextureManager::Draw(m_blankSquare, src, dest);
		}

		else {
			if (s.type == SQUARE) {
				TextureManager::Draw(m_yellowSquare, src, dest);
			}
			if (s.type == LONG) {
				TextureManager::Draw(m_lightBlueSquare, src, dest);
			}
			if (s.type == R_PIECE) {
				TextureManager::Draw(m_blueSquare, src, dest);
			}
			if (s.type == L_PIECE) {
				TextureManager::Draw(m_orangeSquare, src, dest);
			}
			if (s.type == T_PIECE) {
				TextureManager::Draw(m_purpleSquare, src, dest);
			}
			if (s.type == S_PIECE) {
				TextureManager::Draw(m_greenSquare, src, dest);
			}
			if (s.type == Z_PIECE) {
				TextureManager::Draw(m_redSquare, src, dest);
			}
		}
	}
}







