#include "../headers/Bag.h"
ALL_PIECES Bag::Pull()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	constexpr int enum_size = static_cast<int>(ALL_PIECES::Z_PIECE);
	int random_index =1+ std::rand() % enum_size;
	ALL_PIECES selectedPiece = static_cast<ALL_PIECES>(random_index);
	return selectedPiece;
}