#pragma once
#include <vector>
#include "Square.h"
#include <SDL_rect.h>
#include "TextureManager.h"

class Board {
public:
	bool rotated;
	int resolution;
	SDL_Rect src, dest;
	std::vector<Square> squareObjects;
	std::vector<Square*> occupiedSquares;

	int winWidth = 0, winHeight = 0;
	static const int HEIGHT=15;
	static const int WIDTH=10;
	int squares[HEIGHT][WIDTH];
	bool dropPiece = false;
	std::string currentType="";
	std::string currentFacing="";
	void CreateBoard(SDL_Window* window);
	void AddPiece(std::string type);
	void RotatePiece();
	void PauseUpdate();
	void ResumeUpdate();
	void RotateLogicForLong(std::string _facing,int pieceHeight, int pieceWidth, int middleXAxis, int middleYAxis);
	void MoveDown();
	void UpdatePositions();
	void CollisionCheck();
	void PlacePiece();
	void DrawBoard();
	void Print();
	void PrintB();
	SDL_Texture* BlankSquare;
	SDL_Texture* BlueSquare;
	SDL_Texture* YellowSquare;
	bool placed = false;
	bool pauseUpdate = false;
	Board(int res) {
		resolution = res;
		BlankSquare = TextureManager::LoadTexture("res/img/BlankSquare.png");
		BlueSquare = TextureManager::LoadTexture("res/img/BlueSquare.png");
		YellowSquare = TextureManager::LoadTexture("res/img/YellowSquare.png");
		pauseUpdate = false;
	}
};
