#pragma once
#include "Engine.h"
#include "Interface.h"

class EventManager {
public:
	Engine* engine;
	Interface* interface;
	static SDL_Event event;
	void ResizeGraphics() const;
	void HandleEvents() const;
	EventManager(Engine* engine,Interface* interface):
		engine{engine},
		interface{interface}
	{}
};
