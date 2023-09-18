#pragma once
#include <string>
#include <vector>
#include <iostream>

class Tile {
public:
	std::string type;
	std::string facing;
	bool isOccupied;
	bool isCenter;
	bool isPlaced;
	int xLocation;
	int yLocation;
	static  Tile* FindCenterSquare(std::vector<Tile*>&occupied_squares);
	Tile(int xLoc,int yLoc):
		xLocation{xLoc},
		yLocation{yLoc},
		isOccupied{false},
		isCenter{false},
		isPlaced{false},
		type{"Blank"},
		facing{"NA"}
	{}
};
