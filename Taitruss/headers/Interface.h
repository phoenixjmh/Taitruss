#pragma once
#include <SDL.h>

#include <iostream>

#include "Audio.h"
#include "TextureManager.h"

class Interface {
 public:
  Audio* audio;
  static SDL_Renderer* renderer;
  SDL_Window* window;
  bool isRunning;
  int *m_WIDTH, *m_HEIGHT;

  SDL_Window* CreateWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT,
                           const char* name);
  void GetResolutions(int& screen_width, int& screen_height,
                      int& block_resolution);

  void Clean() const;

  Interface()
      : isRunning{false},
        window{nullptr},
        audio{new Audio},
        m_WIDTH{new int},
        m_HEIGHT{new int} {}
};
