#pragma once
#include <SDL_rect.h>

#include <vector>

#include "Bag.h"
#include "Game.h"
#include "Piece.h"
#include "Textures.h"
#include "Tile.h"

class Board {
 public:
  void PlacePiece();
  void HardDrop();
  void UpdateVectors();
  bool CanMoveDown();
  void CollisionCheck();
  void DrawBoard();
  void AddPiece(ALL_PIECES type);
  void MoveDown();
  void RotatePiece();
  void Move(std::string dir);
  int winWidth = 0, winHeight = 0;
  bool hard_drop;
  bool dropPiece;
  bool placeOnNextTick;
  bool GAMEOVER;
  bool isPressDown;
  bool busyMoving;
  int tempGameSpeed;

  Board()

      : dropPiece{true},
        placeOnNextTick{false},
        m_canMoveDown{false},
        src{SDL_Rect{0, 0, Game::BLOCK_RESOLUTION, Game::BLOCK_RESOLUTION}},
        dest{SDL_Rect{0, 0, Game::BLOCK_RESOLUTION, Game::BLOCK_RESOLUTION}},
        m_currentPiece{nullptr},
        m_placed{false},
        m_pauseUpdate{false},
        GAMEOVER{false},
        isPressDown{false},
        busyMoving{false},
        tempGameSpeed{0},
        hard_drop(false)
     

  {
    SDL_GetWindowSize(Game::window, &winWidth, &winHeight);
    for (int i = 0; i < Board::HEIGHT; i++) {
      for (int y = 0; y < Board::WIDTH; y++) {
        Tile square(y, i);
        this->m_squareObjects.push_back(square);
      }
    }
  }

 private:
  bool m_canMoveDown;
  int blockTextureRes = 256;
  SDL_Rect src, dest;
  std::vector<Tile> m_squareObjects;
  std::vector<Tile*> m_occupiedSquares;
  std::vector<Tile*> placedSquares;
  static constexpr int HEIGHT = 20;
  static constexpr int WIDTH = 10;
  ALL_PIECES m_currentType;
  std::string m_currentFacing;
  std::unique_ptr<Piece> m_currentPiece;
  bool m_placed;
  bool m_pauseUpdate;
  void PauseUpdate();
  void ClearPlaced(int index);
  void ResumeUpdate();
  void CheckClearRow();
  void ClearRow(const std::vector<Tile*>& row_to_clear);
  void MovePlacedDown(int index, int times_to_move);
  void ClearSquares();
  bool CanMove(std::string dir);
};
