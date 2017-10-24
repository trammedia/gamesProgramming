#pragma once
#include "GameState.h"

class highScoreState :
	public GameState
{
public:/*
	highScoreState();
	~highScoreState();*/
	void input();
	void render();
	void changeState(GameState* game);
};

