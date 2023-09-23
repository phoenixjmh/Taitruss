#pragma once
#include <vector>
#include "Tile.h"
#include <SDL_rect.h>
#include "TextureManager.h"
#include "Piece.h"

class Board {
public:
	bool rotated;
	int& resolution;
	int rowToClearIndex = 0;
	SDL_Rect src, dest;
	std::vector<Tile> squareObjects;
	std::vector<Tile*> occupiedSquares;
	std::vector<Tile*> placedSquares;
	int winWidth = 0, winHeight = 0;
	static const int HEIGHT = 15;
	static const int WIDTH = 10;
	bool dropPiece;
	std::string currentType = "";
	std::string currentFacing = "";
	SDL_Texture* BlankSquare;
	SDL_Texture* BlueSquare;
	SDL_Texture* YellowSquare;
	SDL_Texture* RedSquare;
	SDL_Texture* GreenSquare;
	SDL_Texture* PurpleSquare;
	SDL_Texture* LightBlueSquare;
	SDL_Texture* OrangeSquare;
	SDL_Texture* RadiusSquare;
	Piece* currentPiece;
	bool placed = false;
	bool pauseUpdate = false;
	void AddPiece(std::string type);
	void RotatePiece();
	void PauseUpdate();
	void ClearPlaced(int index);
	void ResumeUpdate();
	void RotateLogicFor_Long_Shape(std::string _facing, int pieceHeight, int pieceWidth, int middleXAxis, int middleYAxis);
	void CheckClearRow();
	void ClearRow(std::vector<Tile*>& rowToClear, int index);
	void MovePlacedDown(int index,int timesToMove);
	void ClearSquares();
	bool CanMove(std::string dir);
	void Move(std::string dir);
	void MoveDown();
	void UpdateVectors();
	void CollisionCheck();
	void PlacePiece();
	void HandleTextureResize();
	void DrawBoard();
	void Print();
	void PrintB();
	void PrintRadius();
	Board(int& res, SDL_Window* win)
		:rotated{ false }, resolution{ res },
		BlankSquare{ TextureManager::LoadTexture("res/img/BlankSquare.png",this->resolution,this->resolution) },
		BlueSquare{ TextureManager::LoadTexture("res/img/BlueSquare.png",this->resolution,this->resolution) },
		YellowSquare{ TextureManager::LoadTexture("res/img/YellowSquare.png",this->resolution,this->resolution) },
		RedSquare{ TextureManager::LoadTexture("res/img/RedSquare.png",this->resolution,this->resolution) },
		GreenSquare{ TextureManager::LoadTexture("res/img/GreenSquare.png",this->resolution,this->resolution) },
		PurpleSquare{ TextureManager::LoadTexture("res/img/PurpleSquare.png",this->resolution,this->resolution) },
		LightBlueSquare{ TextureManager::LoadTexture("res/img/LightBlueSquare.png",this->resolution,this->resolution) },
		OrangeSquare{ TextureManager::LoadTexture("res/img/OrangeSquare.png",this->resolution,this->resolution) },
		RadiusSquare{ TextureManager::LoadTexture("res/img/BlankSquareDB.png",this->resolution,this->resolution) },
		pauseUpdate{ false }, src{ SDL_Rect{0,0,res,res} },
		dest{ SDL_Rect { 0,0,res,res } }, dropPiece{ true },
		currentPiece{nullptr}


	{
		SDL_GetWindowSize(win, &winWidth, &winHeight);
		std::cout << "Creating board here" << std::endl;
		for (int i = 0; i < this->HEIGHT; i++)
		{
			for (int y = 0; y < WIDTH; y++)
			{
				Tile square(y, i);
				this->squareObjects.push_back(square);
			}
		}
	}

};
