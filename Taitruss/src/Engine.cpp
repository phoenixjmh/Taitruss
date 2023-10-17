#include "../headers/Engine.h"
// #define test

void Engine::BeginSession() {
  board = new Board();
  scoreBoard = new Scoreboard(Game::BLOCK_RESOLUTION);
  scoreBoard->GetTextures();
  scoreBoard->GetLevelNumberTexture();
  m_src = SDL_Rect{0, 0, 256, 178};
  m_dest = SDL_Rect{(board->winWidth / 2) - (m_src.w / 2),
                    (board->winHeight / 2) - (m_src.h / 2), 256, 178};
  menuSrc = SDL_Rect{0, 0, 1160, 800};
  menuDest =
      SDL_Rect{(board->winWidth / 2) - (menuSrc.w / 2), 0,
               Game::BLOCK_RESOLUTION * 150, Game::BLOCK_RESOLUTION * 100};
}

void Engine::update() {
  ChangeLevel();
  scoreBoard->Update();
  if (GamePausedEvent) {
    if (!GamePaused) {
      Audio::Pause();
    } else
      Audio::Resume();
    GamePaused = !GamePaused;
    GamePausedEvent = false;
  }
  if (!GamePaused) {
    drop_logic();
    board->UpdateVectors();
    board->CollisionCheck();
  }
}

void Engine::render() {
  if (!GamePaused) {
    SDL_RenderClear(Game::renderer);
    SDL_SetRenderDrawColor(Game::renderer, 10, 10, 10, 255);
    board->DrawBoard();
    scoreBoard->Draw();
    SDL_RenderPresent(Game::renderer);
  }
  if (GamePaused) {
    SDL_RenderClear(Game::renderer);
    SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);
    m_dest.w = board->winWidth / 3;
    m_dest.h = m_dest.w * 0.7;
    m_dest.x = (board->winWidth / 2) - (m_dest.w / 2);
    m_dest.y = (board->winHeight / 2) - (m_dest.h / 2);

    TextureManager::Draw(PauseScreen, m_src, m_dest);
    SDL_RenderPresent(Game::renderer);
  }
}
void Engine::RenderMenu() {
  SDL_RenderClear(Game::renderer);
  SDL_SetRenderDrawColor(Game::renderer, 0, 0, 0, 255);

  menuDest.w = board->winHeight * 1.5;
  menuDest.h = board->winHeight;
  menuDest.x = (board->winWidth / 2) - (menuDest.w / 2);
  TextureManager::Draw(StartMenu, menuSrc, menuDest);
  SDL_RenderPresent(Game::renderer);
}

int times = -1;
void Engine::drop_logic() {
#ifdef test
  if (board)
    if (board->dropPiece) {
      if (m_test1.size() > 0) {
        ALL_PIECES piece = m_test1.front();
        board->AddPiece(piece);
        m_test1.erase(m_test1.begin());
      }
    }

#endif

#ifndef test
  if (board)
    if (board->dropPiece) {
      ALL_PIECES nextPiece = Bag::Pull();
      board->AddPiece(nextPiece);
    }
#endif
}
void Engine::move_block_down() const {
  std::cout << "LEVEL: " << scoreBoard->level << "\n";

  std::cout << "GameSpeed" << Game::frame_delay << "\n"
            << scoreBoard->TOTAL_CLEARED_ROWS;
  if (!GamePaused && !board->isPressDown && !board->busyMoving)
    board->MoveDown();
}
void Engine::ChangeLevel() {
  scoreBoard->CheckLevel();
  // std::cout <<"LEVEL: " <<scoreBoard->level<<"\n";
  if (board->hard_drop) {
    return;
  } else {
    switch (scoreBoard->level) {
      case 1:
        Game::frame_delay = 700;
        break;
      case 2:
        Game::frame_delay = 500;
        break;
      case 3:
        Game::frame_delay = 350;
        break;
      case 4:
        Game::frame_delay = 200;
        break;
      default:
        break;
    }
  }
}

void Engine::OnClearRow(int cleared_rows) const {
  std::cout << "ADDING" << cleared_rows << "\n";
  scoreBoard->AddPoints(cleared_rows);
}
void Engine::OnPlaceBlock() { Audio::PlaySound(Audio::SOUNDS::PLACE); }

void Engine::OnTick() const {
  if (board->placeOnNextTick) {
    board->PlacePiece();
  }
}

void Engine::Tick() {
  m_ticks++;
  OnTick();
}
void Engine::Reset() {
  Audio::PlaySound(Audio::SOUNDS::GAMEOVER);

  board = new Board();
  Game::frame_delay = 700;
  scoreBoard->isBlinking = true;
  scoreBoard->blinkStartTime = SDL_GetTicks();
  // scoreBoard = new Scoreboard(m_blockResolution);
}
