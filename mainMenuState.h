#pragma once
#include "GameState.h"

// contains declarations but not implementations
//of the class GameState and its member functions

class mainMenuState :
	public GameState
{
public:
	//mainMenuState();
	//~mainMenuState();
	 void input();
	 void render();
	void changeState(GameState* game);

};
