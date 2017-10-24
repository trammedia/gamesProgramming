#include "GameState.h"

//GameState::GameState()
//{
//	std::cout << "pop" << std::endl;
//}

//GameState::~GameState()
//{
//}

//contains the implementations of the class GameState

void GameState::input() 
{ 
	std::cin >> mychar;
};

void GameState::changeState(GameState * gameState)
{

	//aboutstate = new aboutState();
	//gameState = aboutstate;
	//return gameState;
};

//overrides GameState render() from other class
void GameState::render() {

	std::cout << "Zorkish::About" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Written by : Justin C" << std::endl;
	std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
	std::cin >> mychar;
};