#pragma once
#include "main.h"

// contains declarations but not implementations
//of the class GameState and its member functions

class GameState
{
public:
	//GameState();
	//~GameState();
	virtual void input(GameState * gameState, std::unordered_multimap<std::string, std::string>  mapped2, std::map<std::string, std::string>  mapIds);
	virtual void render();
	virtual void changeState(GameState * gameState, std::unordered_multimap<std::string, std::string>  mapped2,int myint, std::unordered_multimap<std::string, std::string>  mapIds);

};