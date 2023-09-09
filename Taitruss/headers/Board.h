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
	static const int HEIGHT = 15;
	static const int WIDTH = 10;
	bool dropPiece = false;
	std::string currentType = "";
	std::string currentFacing = "";
	SDL_Texture* BlankSquare;
	SDL_Texture* BlueSquare;
	SDL_Texture* YellowSquare;
	bool placed = false;
	bool pauseUpdate = false;
	void CreateBoard(SDL_Window* window);
	void AddPiece(std::string type);
	void RotatePiece();
	void PauseUpdate();
	void ResumeUpdate();
	void RotateLogicForLong(std::string _facing, int pieceHeight, int pieceWidth, int middleXAxis, int middleYAxis);
	void ClearSquares();
	bool CanMove(std::string dir);
	void Move(std::string dir);
	void MoveDown();
	void UpdatePositions();
	void CollisionCheck();
	void PlacePiece();
	void DrawBoard();
	void Print();
	void PrintB();
	Board(int res, SDL_Window* win)
		:rotated{ false }, resolution{ res },
		BlankSquare{ TextureManager::LoadTexture("res/img/BlankSquare.png") },
		BlueSquare{ TextureManager::LoadTexture("res/img/BlueSquare.png") },
		YellowSquare{ TextureManager::LoadTexture("res/img/YellowSquare.png") },
		pauseUpdate{ false }, src{ SDL_Rect{0,0,res,res} },
		dest{ SDL_Rect { 0,0,resolution,resolution } }
	{
		SDL_GetWindowSize(win, &winWidth, &winHeight);
		std::cout << "Creating board here" << std::endl;
		for (int i = 0; i < this->HEIGHT; i++)
		{
			for (int y = 0; y < WIDTH; y++)
			{
				Square square(y, i);
				this->squareObjects.push_back(square);
			}
		}
	}

};
