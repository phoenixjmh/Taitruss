#pragma once
#include <string>
class Square {
public:
	std::string type;
	enum orientation{N,E,S,W};
	orientation* facing;
	bool isOccupied;
	bool isPlaced;
	int xLocation;
	int yLocation;
	void init(int xLoc,int yLoc);
};
