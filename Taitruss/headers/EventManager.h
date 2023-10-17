#pragma once
#include <SDL_events.h>

#include "Engine.h"
#include "Interface.h"

class EventManager {
 public:
  static SDL_Event event;
  void ResizeGraphics() const;
  void HandleEvents(int& pressDelay, const Uint32 input_start,
                    Uint32& previous);
  void HandleMenuEvents();
  EventManager() : m_isHoldingButton{false} {}

 private:
  bool m_isHoldingButton;
};
