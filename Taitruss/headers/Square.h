#pragma once
#include <string>
class Square {
public:
	std::string type;
	std::string facing;
	bool isOccupied;
	bool isPlaced;
	int xLocation;
	int yLocation;
	Square(int xLoc,int yLoc):
		xLocation{xLoc},
		yLocation{yLoc},
		isOccupied{false},
		isPlaced{false},
		type{"Blank"},
		facing{"NA"}


	{}
};
