#pragma once
#include <vector>;
#include "Square.h";
#include <SDL_rect.h>
#include "TextureManager.h";

class Board {
public:
	int resolution;
	SDL_Rect src, dest;
	std::vector<Square> squareObjects;
	static const int HEIGHT=10;
	static const int WIDTH=6;
	int squares[HEIGHT][WIDTH];
	void CreateBoard();
	void DrawBoard();
	void Print();
	SDL_Texture* BlankSquare;

	Board(int res) {
		resolution = res;
	}
};
