#pragma once
#include <SDL.h>

#include <iostream>

class Engine;
class EventManager;
class Interface;

class Game {
 public:
  static void MainLoop();
  static Engine* engine;
  static Interface* interface;
  static EventManager* eventManager;
  static SDL_Window* window;
  static SDL_Renderer* renderer;
  static Uint32 previous_block_fall_time;
  static Uint32 previous_input_time;
  static int pressHoldDelay;
  static int BLOCK_RESOLUTION;
  static int frame_delay;
  static constexpr int SCREEN_WIDTH = 760;
  static constexpr int SCREEN_HEIGHT = 480;

 private:
  void Init();
};