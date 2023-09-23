#pragma once
#include <string>
#include <vector>
#include <iostream>

/// <summary>
	/// Positional data for the radius, used by piece
	/// T:TOP , M: MIDDLE , B: BOTTOM
	/// </summary>
enum Position {
	TL, TM, TR, ML, MM, MR, BL, BM, BR, NONE
};
class Tile {
public:
	std::string type;
	std::string facing;
	Position relativePos;
	bool isOccupied;
	bool isCenter;
	bool isPlaced;
	int xLocation;
	int yLocation;
	bool isRadius;
	static  Tile* FindCenterSquare(std::vector<Tile*>& occupied_squares);
	Tile() = default;
	Tile(int xLoc, int yLoc) :
		xLocation{ xLoc },
		yLocation{ yLoc },
		isOccupied{ false },
		isCenter{ false },
		isPlaced{ false },
		type{ "Blank" },
		facing{ "NA" },
		isRadius{ false },
		relativePos{ NONE }
	{}
	Tile& operator=(const Tile& other) {  // NOLINT(clang-diagnostic-deprecated-copy-with-user-provided-copy)

		this->type = other.type;
		this->isOccupied = other.isOccupied;
		this->facing = other.facing;

		return *this;
	}
};
