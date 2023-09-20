#include "../headers/Piece.h"


bool Piece::CanRotate(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares, int WIDTH, int HEIGHT) {
	std::cout << "Facing: " << facing << "\n";

	if (BorderCheck(type, facing, occupiedSquares, WIDTH, HEIGHT) && NeighborCheck(type, facing, occupiedSquares, allSquares))
		return true;
	else return false;

}
bool Piece::BorderCheck(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, int WIDTH, int HEIGHT) {
	if (type == "Long") {
		if (facing == "N") {
			for (auto& os : occupiedSquares)
			{
				if (os->yLocation < 1) { //border check
					return false;
				}
				if (os->yLocation >= HEIGHT - 2) { //border check
					return false;
				}
			}
		}
		if (facing == "E") {
			for (auto& os : occupiedSquares)
			{
				if (os->xLocation > WIDTH - 2 || os->xLocation < 2) //border check
					return false;

			}
		}
		if (facing == "S") {
			for (auto& os : occupiedSquares)
			{
				if (os->yLocation < 1) { //border check
					return false;
				}
				if (os->yLocation >= HEIGHT - 2) { //border check
					return false;
				}
			}
		}
		if (facing == "W") {
			for (auto& os : occupiedSquares) {
				if (os->xLocation > WIDTH - 3 || os->xLocation < 1) //border check
					return false;
			}
		}
		return true;
	}
}
bool Piece::NeighborCheck(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares) {
	UpdateRadius(occupiedSquares);
	std::cout << "Radius size" << m_radius.size() << "\n";
	for (auto& square : m_radius) {
		if (square->isPlaced) {
			std::cout << "RADIUS INFILTRATED\n";
			return false;
		}
	}
	return true;
}
void Piece::RefreshPiece() {
	if (m_facing == "N") {
		m_facing = "E";
		return;
	}
	else if (m_facing == "E") {
		m_facing = "S";
		return;
	}
	else if (m_facing == "S") {
		m_facing = "E";
		return;
	}
	else if (m_facing == "E") {
		m_facing = "N";
		return;
	}
}

void Piece::Rotate()
{
	//copy every square with corresponding name
	//rotate the whole piece
	//full reassignment version
	Tile* tile0 = new Tile;
	Tile* tile1 = new Tile;
	Tile* tile2 = new Tile;
	Tile* tile3 = new Tile;
	Tile* tile4 = new Tile;
	Tile* tile5 = new Tile;
	Tile* tile6 = new Tile;
	Tile* tile7 = new Tile;
	Tile* tile8 = new Tile;
	//assign tiles to index[0-9] using relativePos, assigned in updateRadius
	for (auto& tile : m_radius)
	{
		switch (tile->relativePos) {
		case 0:
			tile0 = tile;
			break;
		case 1:
			tile1 = tile;
			break;
		case 2:
			tile2 = tile;
			break;
		case 3:
			tile3 = tile;
			break;
		case 4:
			tile4 = tile;
			break;
		case 5:
			tile5 = tile;
			break;
		case 6:
			tile6 = tile;
			break;
		case 7:
			tile7 = tile;
			break;
		case 8:
			tile8 = tile;
			break;
		default:
			break;
		}
	}
	//copy contents
	Tile tile0Copy = *tile0;
	Tile tile1Copy = *tile1;
	Tile tile2Copy = *tile2;
	Tile tile3Copy = *tile3;
	Tile tile4Copy = *tile4;
	Tile tile5Copy = *tile5;
	Tile tile6Copy = *tile6; 
	Tile tile7Copy = *tile7;
	Tile tile8Copy = *tile8;

	//reassign
	std::cout << "Tile 2: " << tile2->isOccupied << "  Tile0 Copy:  " << tile2Copy.isOccupied << "\n";

	*tile0 = tile6Copy;
	*tile1 = tile3Copy;
	*tile2 = tile0Copy;
	*tile3 = tile7Copy;
	*tile4 = *tile4;
	*tile5 = tile1Copy;
	*tile6 = tile8Copy;
	*tile7 = tile5Copy;
	*tile8 = tile2Copy;

	std::cout << "Copy completed brute reassignment\n" << "Tile 2: " << tile2->isOccupied << "\n";
	std::cout << "CENTER FROM ROTATE SCRIPT" << tile4->xLocation << tile4->yLocation << "\n";
}

void Piece::UpdateRadius(std::vector<Tile*> occupiedSquares)
{
	//Takes in the position of the occupied square, and returns a container around it
	//that has a radius of all potential rotation widths
	/*std::vector<Tile*> radius;*/
	m_radius.clear();
	if (m_type == "Long") {
		if (m_facing == "N") {
			for (auto& square : m_allSquares)
			{
				for (auto& occupiedSquare : occupiedSquares)
				{
					if (square.xLocation == occupiedSquare->xLocation) {
						if (square.yLocation == occupiedSquare->yLocation - 1 ||
							square.yLocation == occupiedSquare->yLocation ||
							square.yLocation == occupiedSquare->yLocation + 1 ||
							square.yLocation == occupiedSquare->yLocation + 2) {
							auto it = std::find(m_radius.begin(), m_radius.end(), &square);
							if (it == m_radius.end()) {
								square.isRadius = true;
								m_radius.push_back(&square);
							}
						}
					}
				}
			}

		}
		else if (m_facing == "E") {
			for (auto& square : m_allSquares)
			{
				for (auto& occupiedSquare : occupiedSquares)
				{
					if (square.yLocation == occupiedSquare->yLocation) {
						if (square.xLocation == occupiedSquare->xLocation - 1 ||
							square.xLocation == occupiedSquare->xLocation ||
							square.xLocation == occupiedSquare->xLocation + 1 ||
							square.xLocation == occupiedSquare->xLocation - 2) {
							auto it = std::find(m_radius.begin(), m_radius.end(), &square);
							if (it == m_radius.end()) {
								square.isRadius = true;
								m_radius.push_back(&square);
							}
						}
					}
				}
			}

		}
		else if (m_facing == "S") {
			for (auto& square : m_allSquares)
			{
				for (auto& occupiedSquare : occupiedSquares)
				{
					if (square.xLocation == occupiedSquare->xLocation) {
						if (square.yLocation == occupiedSquare->yLocation - 1 ||
							square.yLocation == occupiedSquare->yLocation ||
							square.yLocation == occupiedSquare->yLocation - 2 ||
							square.yLocation == occupiedSquare->yLocation + 1) {
							auto it = std::find(m_radius.begin(), m_radius.end(), &square);
							if (it == m_radius.end())
							{
								square.isRadius = true;
								m_radius.push_back(&square);
							}
						}
					}
				}
			}

		}
		else if (m_facing == "W") {
			for (auto& square : m_allSquares)
			{
				for (auto& occupiedSquare : occupiedSquares)
				{
					if (square.yLocation == occupiedSquare->yLocation) {
						if (square.xLocation == occupiedSquare->xLocation - 1 ||
							square.xLocation == occupiedSquare->xLocation ||
							square.xLocation == occupiedSquare->xLocation + 1 ||
							square.xLocation == occupiedSquare->xLocation + 2) {
							auto it = std::find(m_radius.begin(), m_radius.end(), &square);
							if (it == m_radius.end())
							{
								square.isRadius = true;
								m_radius.push_back(&square);
							}
						}
					}
				}
			}

		}

	}
	else {
		//branch out from center point to find radius.
		//     | -x,-y | x,-y | +x,-y |
		//     | -x, y |center| +x,y  |
		//     | -x,+y | x,+y | +x,+y |

		Tile* center = new Tile;
		for (auto& c : m_allSquares)
		{
			if (c.isCenter) {
				center = &c;
			}
		}
		if (center != nullptr) {
			for (auto& tile : m_allSquares)
			{
				tile.isRadius = false;
				tile.relativePos = NONE;

				if (tile.yLocation == center->yLocation - 1) {
					if (tile.xLocation == center->xLocation - 1 ||
						tile.xLocation == center->xLocation ||
						tile.xLocation == center->xLocation + 1)
					{
						//assign this square it's relativepos name
						if (tile.xLocation == center->xLocation - 1) {
							tile.relativePos = TL;
						}
						if (tile.xLocation == center->xLocation) {
							tile.relativePos = TM;
						}
						if (tile.xLocation == center->xLocation + 1) {
							tile.relativePos = TR;
						}
						tile.isRadius = true;
						m_radius.push_back(&tile);
					}
				}
				if (tile.yLocation == center->yLocation) {
					if (tile.xLocation == center->xLocation - 1 ||
						tile.xLocation == center->xLocation ||
						tile.xLocation == center->xLocation + 1)
					{
						if (tile.xLocation == center->xLocation - 1) {
							tile.relativePos = ML;
						}
						if (tile.xLocation == center->xLocation) {
							tile.relativePos = MM;
						}
						if (tile.xLocation == center->xLocation + 1) {
							tile.relativePos = MR;
						}
						tile.isRadius = true;
						m_radius.push_back(&tile);
					}

				}
				if (tile.yLocation == center->yLocation + 1) {
					if (tile.xLocation == center->xLocation - 1 ||
						tile.xLocation == center->xLocation ||
						tile.xLocation == center->xLocation + 1)
					{
						if (tile.xLocation == center->xLocation - 1) {
							tile.relativePos = BL;
						}
						if (tile.xLocation == center->xLocation) {
							tile.relativePos = BM;
						}
						if (tile.xLocation == center->xLocation + 1) {
							tile.relativePos = BR;
						}
						tile.isRadius = true;
						m_radius.push_back(&tile);
					}
				}
			}
		}
	}
}

std::vector<Tile*> Piece::GetRadius() {
	return m_radius;
}

