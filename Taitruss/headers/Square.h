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
	void init(int xLoc,int yLoc);
};
