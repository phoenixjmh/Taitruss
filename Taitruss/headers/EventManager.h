#pragma once
#include "Engine.h"
#include "Interface.h"

class EventManager {
public:
	Engine* _engine;
	Interface* _interface;
	static SDL_Event event;
	void HandleEvents();
	EventManager(Engine* engine,Interface* interface):
		_engine{engine},
		_interface{interface}
	{}
};
