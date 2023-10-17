#include "../headers/Game.h"
#include "../headers/Engine.h"
#include "../headers/EventManager.h"
#include "../headers/Interface.h"

int Game::BLOCK_RESOLUTION = 32;
int Game::frame_delay = 700;
Interface* Game::interface = new Interface();
SDL_Window* Game::window =
    Game::interface->CreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Taitruss");
SDL_Renderer* Game::renderer = Interface::renderer;
Engine* Game::engine = new Engine();
Uint32 Game::previous_block_fall_time = SDL_GetTicks();
Uint32 Game::previous_input_time = SDL_GetTicks();
int Game::pressHoldDelay = 0;
EventManager* Game::eventManager = new EventManager();

void Game::MainLoop() {
  engine->BeginSession();
  const int X_RATIO = Game::SCREEN_WIDTH / Game::BLOCK_RESOLUTION;
  const int Y_RATIO = Game::SCREEN_HEIGHT / Game::BLOCK_RESOLUTION;

  Game::eventManager->ResizeGraphics();
  while (!Game::engine->StartGame) {
    Game::eventManager->HandleMenuEvents();
    Game::engine->RenderMenu();
  }

  Audio::PlayMusic();

  std::cout << "RATIO:  " << X_RATIO << "  " << Y_RATIO << "\n";
  while (interface->isRunning) {
    bool& gameOver = engine->board->GAMEOVER;

    constexpr int input_delay = 100;
    const Uint32 frame_start = SDL_GetTicks();
    const Uint32 input_start = SDL_GetTicks();
    if (!gameOver) {
      eventManager->HandleEvents(pressHoldDelay, input_start,
                                 previous_input_time);
      engine->update();
      engine->render();
    }

    if (frame_start - previous_block_fall_time >= frame_delay) {
      if (gameOver) {
        engine->Reset();
      }
      engine->move_block_down();
      previous_block_fall_time = frame_start;
      engine->Tick();
    }
  }
  interface->Clean();
}