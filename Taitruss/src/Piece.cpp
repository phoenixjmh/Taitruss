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
	std::vector<Tile*> radius = GetRadius(type, facing, occupiedSquares, allSquares);
	std::cout << "Radius size" << radius.size() << "\n";
	for (auto& square : radius) {
		std::cout << "Radius square X:" << square->xLocation << "  Y: " << square->yLocation << "\n";
		if (square->isPlaced) {
			return false;
		}
	}
	return true;
}
std::vector<Tile*> Piece::GetRadius(std::string type, std::string facing, std::vector<Tile*> occupiedSquares, std::vector<Tile>& allSquares)
{
	//Takes in the position of the occupied square, and returns a container around it
	//that has a radius of all potential rotation widths
	std::vector<Tile*> radius;
	if (type == "Long") {
		if (facing == "N") {
			for (auto& occupiedSquare : occupiedSquares)
			{
				radius.push_back(occupiedSquare);
				for (auto& square : allSquares)
				{
					if (square.xLocation == occupiedSquare->xLocation) {
						if (square.yLocation == occupiedSquare->yLocation - 1 ||
							square.yLocation == occupiedSquare->yLocation + 1 ||
							square.yLocation == occupiedSquare->yLocation + 2) {
							radius.push_back(&square);
						}
					}
				}
			}

		}
		else if (facing == "E") {
			for (auto& occupiedSquare : occupiedSquares)
			{
				radius.push_back(occupiedSquare);
				for (auto& square : allSquares)
				{
					if (square.yLocation == occupiedSquare->yLocation) {
						if (square.xLocation == occupiedSquare->xLocation - 1 ||
							square.xLocation == occupiedSquare->xLocation + 1 ||
							square.xLocation == occupiedSquare->xLocation - 2) {
							radius.push_back(&square);
						}
					}
				}
			}

		}
		if (facing == "S") {
			for (auto& occupiedSquare : occupiedSquares)
			{
				radius.push_back(occupiedSquare);
				for (auto& square : allSquares)
				{
					if (square.xLocation == occupiedSquare->xLocation) {
						if (square.yLocation == occupiedSquare->yLocation - 1 ||
							square.yLocation == occupiedSquare->yLocation - 2 ||
							square.yLocation == occupiedSquare->yLocation + 1) {
							radius.push_back(&square);
						}
					}
				}
			}

		}
		if (facing == "W") {
			for (auto& occupiedSquare : occupiedSquares)
			{
				radius.push_back(occupiedSquare);
				for (auto& square : allSquares)
				{
					if (square.yLocation == occupiedSquare->yLocation) {
						if (square.xLocation == occupiedSquare->xLocation - 1 ||
							square.xLocation == occupiedSquare->xLocation + 1 ||
							square.xLocation == occupiedSquare->xLocation + 2) {
							radius.push_back(&square);
						}
					}
				}
			}

		}
		return radius;
	}

}
