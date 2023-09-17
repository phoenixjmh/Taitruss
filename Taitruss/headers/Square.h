#pragma once
#include <string>
#include <vector>
#include <iostream>

class Square {
public:
	std::string type;
	std::string facing;
	bool isOccupied;
	bool isCenter;
	bool isPlaced;
	int xLocation;
	int yLocation;
	static  Square* FindCenterSquare(std::vector<Square*>&occupied_squares);
	Square(int xLoc,int yLoc):
		xLocation{xLoc},
		yLocation{yLoc},
		isOccupied{false},
		isCenter{false},
		isPlaced{false},
		type{"Blank"},
		facing{"NA"}
	{}
};
