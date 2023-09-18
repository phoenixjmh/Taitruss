#include "../headers/Tile.h"



Tile* Tile::FindCenterSquare(std::vector<Tile*> &occupied_squares)
{
	for (auto& os : occupied_squares) {
		if (os->isCenter) {
			std::cout << "Found center\n";
			return os;
		}
	}
}
