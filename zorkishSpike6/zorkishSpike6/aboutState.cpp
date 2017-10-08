#include "aboutState.h"

aboutState::aboutState()
{
}

aboutState::~aboutState()
{
}

void aboutState::input()  { std::cin >> mychar; };

void aboutState::changeState(GameState* game) {
	};

//overrides GameState render() from other class
 void aboutState::render()  {

		std::cout << "Zorkish::About" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "Written by : Justin C" << std::endl;
		std::cout << "Press ESC or Enter to return to the Main Menu" << std::endl;
		std::cin >> mychar;
 };

