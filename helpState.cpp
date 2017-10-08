#include "helpState.h"

helpState::helpState()
{
}


helpState::~helpState()
{
}

void helpState::input()  { std::cin >> mychar; };

void helpState::changeState(GameState* game) {};

//overrides GameState draw() from other class
void helpState::render()  {

		std::cout << "Zorkish::Help" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "The following commands are supported :" << std::endl;
		std::cout << "quit" << std::endl;
		std::cout << "hiscore(for testing)" << std::endl;
};

