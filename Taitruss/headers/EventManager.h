#pragma once
#include "Engine.h"
#include "Interface.h"
#include <SDL_events.h>


class EventManager {
public:
	Engine* engine;
	Interface* interface;
	static SDL_Event event;
	void ResizeGraphics() const;
	void HandleEvents(int& pressDelay, const Uint32 input_start, Uint32& previous);
	EventManager(Engine* engine, Interface* interface) :
		engine{ engine },
		interface { interface },
		m_isHoldingButton{false}
	{}
private:
	bool m_isHoldingButton;

};
