#pragma once
#include "Audio.h"
#include "Bag.h"
#include "Board.h"
#include "Game.h"
#include "ScoreBoard.h"

class Engine {
 public:
  void BeginSession();
  void update();
  void render();
  void drop_logic();
  void move_block_down() const;
  void OnTick() const;
  void Tick();
  void Reset();
  void OnClearRow(int cleared_rows) const;
  void OnPlaceBlock();
  void PauseGame();
  void RenderMenu();
  void ChangeLevel();
  int TOTAL_ROWS_CLEARED;
  bool blinkingScore;
  SDL_Texture* StartMenu;
  bool GamePaused;
  bool GamePausedEvent;
  bool movedDown;
  Board* board;
  Scoreboard* scoreBoard;
  bool StartGame;

  Engine()
      : blinkingScore{false},
        blinkStartTime{0},
        GamePaused{false},
        movedDown{false},
        StartGame(false),
        board{nullptr},
        m_test1{T_PIECE,T_PIECE,T_PIECE,LONG,LONG,T_PIECE,LONG},  // jacket
        StartMenu(TextureManager::LoadTexture("res/img/StartMenuTitle.png")) {}

 private:
  SDL_Texture* PauseScreen =
      TextureManager::LoadTexture("res/img/PauseScreen.png");
  SDL_Rect m_src, m_dest;
  int m_ticks;
  std::vector<ALL_PIECES> m_test1;
  SDL_Rect menuSrc, menuDest;
  int blinkStartTime;
};
