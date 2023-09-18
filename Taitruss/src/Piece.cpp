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
							if (it == m_radius.end())
								m_radius.push_back(&square);
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
							if (it == m_radius.end())
								m_radius.push_back(&square);
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
								m_radius.push_back(&square);
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
								m_radius.push_back(&square);
						}
					}
				}
			}

		}

	}
	else {
		std::cout <<"OTHER TYPE"<< m_type;
		//branch out from center point to find radius.
		//     | -x,-y | x,-y | +x,-y |
		//     | -x, y |center| +x,y  |
		//     | -x,+y | x,+y | +x,+y |

		Tile* center = nullptr;
		for (auto& os : m_allSquares)
		{
			if (os.isCenter) {
				center = &os;
				break;
			}
		}
		if (center != nullptr) {
			for (auto& tile : m_allSquares)
			{
				auto it = std::find(m_radius.begin(), m_radius.end(), &tile);

				if (tile.yLocation == center->yLocation - 1) {
					if (tile.xLocation == center->xLocation - 1 ||
						tile.xLocation == center->xLocation ||
						tile.xLocation == center->xLocation + 1)
					{
						if (it == m_radius.end()) {
							m_radius.push_back(&tile);
						}
					}
				}
				if (tile.yLocation == center->yLocation) {
					if (tile.xLocation == center->xLocation - 1 ||
						tile.xLocation == center->xLocation ||
						tile.xLocation == center->xLocation + 1)
					{
						if (it == m_radius.end()) {
							m_radius.push_back(&tile);
						}
					}

				}
				if (tile.yLocation == center->yLocation + 1) {
					if (tile.xLocation == center->xLocation - 1 ||
						tile.xLocation == center->xLocation ||
						tile.xLocation == center->xLocation + 1)
					{
						if (it == m_radius.end()) {
							m_radius.push_back(&tile);
						}
					}
				}
			}
		}
	}
}
std::vector<Tile*> Piece::GetRadius() {
	return m_radius;
}

