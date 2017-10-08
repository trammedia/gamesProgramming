#pragma once
#include "GameState.h"

class chooseAdventureState :
	public GameState
{
public:
	/*chooseAdventureState();
	~chooseAdventureState();*/
	void input();
	void render();
	void changeState(GameState* game);
};