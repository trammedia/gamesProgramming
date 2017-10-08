#pragma once
#include "GameState.h"

class StateManager
{
public:
	StateManager();
	~StateManager();

	//place a new gamestate into the vector
	void pushState(GameState * gameState);

	// take out (pop) a gamestate from the vector
	void popState(GameState * gameState);

	void render();

	void input(GameState * gameState, std::unordered_multimap<std::string, std::string>  mapped2, std::map<std::string, std::string>  mapIds);

	//void determine();

	//change the state with abstract gamestate param, but return nothing, 'void'
	void changeState(GameState* gameState);

private:
	//make a vector of the <Gamestates> called m_states , an array like object
	// this is private
	std::vector <GameState*> m_states;

};

