#pragma once
#include "Engine.h";
#include "Interface.h";

class EventManager {
public:
	EventManager(Engine* engine, Interface* interface);
	Engine* _engine;
	Interface* _interface;
	static SDL_Event event;
	void HandleEvents();
};
