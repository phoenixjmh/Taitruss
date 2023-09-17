#include "../headers/Square.h"



Square* Square::FindCenterSquare(std::vector<Square*> &occupied_squares)
{
	for (auto& os : occupied_squares) {
		if (os->isCenter) {
			std::cout << "Found center\n";
			return os;
		}
	}
}
