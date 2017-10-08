#pragma once
#include "GameState.h"

class helpState :
	public GameState
{
public:
	helpState();
	~helpState();
	void input();
	void render();
	void changeState(GameState* game);

};

