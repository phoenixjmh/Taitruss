#pragma once
#include <vector>
#include "Tile.h"
#include <SDL_rect.h>
#include "TextureManager.h"
#include "Piece.h"

class Board {
public:
	Board(int& res, SDL_Window* win)
		:dropPiece{ true },
		placeOnNextTick{ false },
		m_canMoveDown{ false },
		m_resolution{ res },
		src{ SDL_Rect{0,0,res,res} },
		dest{ SDL_Rect { 0,0,res,res } },
		m_blankSquare{ TextureManager::LoadTexture("res/img/BlankSquare.png",this->m_resolution,this->m_resolution) },
		m_blueSquare{ TextureManager::LoadTexture("res/img/BlueSquare.png",this->m_resolution,this->m_resolution) },
		m_yellowSquare{ TextureManager::LoadTexture("res/img/YellowSquare.png",this->m_resolution,this->m_resolution) },
		m_redSquare{ TextureManager::LoadTexture("res/img/RedSquare.png",this->m_resolution,this->m_resolution) },
		m_greenSquare{ TextureManager::LoadTexture("res/img/GreenSquare.png",this->m_resolution,this->m_resolution) },
		m_purpleSquare{ TextureManager::LoadTexture("res/img/PurpleSquare.png",this->m_resolution,this->m_resolution) },
		m_lightBlueSquare{ TextureManager::LoadTexture("res/img/LightBlueSquare.png",this->m_resolution,this->m_resolution) },
		m_orangeSquare{ TextureManager::LoadTexture("res/img/OrangeSquare.png",this->m_resolution,this->m_resolution) }, m_radiusSquare{ TextureManager::LoadTexture("res/img/BlankSquareDB.png",this->m_resolution,this->m_resolution) },
		m_currentPiece{ nullptr },
		m_placed{ false },
		m_pauseUpdate{ false }



	{
		SDL_GetWindowSize(win, &winWidth, &winHeight);
		std::cout << "Creating board here" << std::endl;
		for (int i = 0; i < Board::HEIGHT; i++)
		{
			for (int y = 0; y < WIDTH; y++)
			{
				Tile square(y, i);
				this->m_squareObjects.push_back(square);
			}
		}
	}
	void PlacePiece();
	void UpdateVectors();
	bool CanMoveDown();
	void CollisionCheck();
	void DrawBoard();
	void AddPiece(std::string type);
	void MoveDown();
	void RotatePiece();
	void Move(std::string dir);
	int winWidth = 0, winHeight = 0;


	bool dropPiece;
	bool placeOnNextTick;

private:
	bool m_canMoveDown;
	int& m_resolution;
	SDL_Rect src, dest;
	std::vector<Tile> m_squareObjects;
	std::vector<Tile*> m_occupiedSquares;
	std::vector<Tile*> placedSquares;
	static constexpr int HEIGHT = 15;
	static constexpr int WIDTH = 10;
	std::string m_currentType;
	std::string m_currentFacing;
	SDL_Texture* m_blankSquare;
	SDL_Texture* m_blueSquare;
	SDL_Texture* m_yellowSquare;
	SDL_Texture* m_redSquare;
	SDL_Texture* m_greenSquare;
	SDL_Texture* m_purpleSquare;
	SDL_Texture* m_lightBlueSquare;
	SDL_Texture* m_orangeSquare;
	SDL_Texture* m_radiusSquare;
	Piece* m_currentPiece;
	bool m_placed;
	bool m_pauseUpdate;
	void PauseUpdate();
	void ClearPlaced(int index);
	void ResumeUpdate();
	void CheckClearRow();
	void ClearRow(const std::vector<Tile*>& row_to_clear, int index);
	void MovePlacedDown(int index, int times_to_move);
	void ClearSquares() const;
	bool CanMove(std::string dir);
	void Print() const;
	void print_b();
	void print_radius() const;


};
