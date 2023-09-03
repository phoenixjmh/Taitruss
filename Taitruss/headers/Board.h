#pragma once
#include <vector>;
#include "Square.h";

class Board {
public:
	std::vector<Square> squareObjects;
	static const int HEIGHT=10;
	static const int WIDTH=6;
	int squares[HEIGHT][WIDTH];
	void CreateBoard();
	void Print();
};
