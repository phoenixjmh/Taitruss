#pragma once
#include <vector>;
#include "Square.h";
#include <SDL_rect.h>
#include "TextureManager.h";

class Board {
public:
	bool rotated;
	int resolution;
	SDL_Rect src, dest;
	std::vector<Square> squareObjects;
	int winWidth = 0, winHeight = 0;
	static const int HEIGHT=15;
	static const int WIDTH=10;
	int squares[HEIGHT][WIDTH];
	void CreateBoard(SDL_Window* window);
	void AddPiece(std::string type);
	void RotatePiece();
	void RotateLogicForLong(std::string _type,std::string _facing,int pieceHeight, int pieceWidth, int middleXAxis, int middleYAxis);
	void MoveDown();
	void DrawBoard();
	void Print();
	void PrintB();
	SDL_Texture* BlankSquare;
	SDL_Texture* BlueSquare;
	SDL_Texture* YellowSquare;

	Board(int res) {
		resolution = res;
	}
};
