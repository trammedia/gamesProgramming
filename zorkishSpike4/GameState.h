#pragma once
#include "main.h"

// contains declarations but not implementations
//of the class GameState and its member functions

class GameState
{
public:
	//GameState();
	//~GameState();
	virtual void input();
	virtual void render();
	virtual void changeState(GameState * gameState);

};