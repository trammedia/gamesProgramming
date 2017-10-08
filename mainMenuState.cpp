#include "mainMenuState.h"

//mainMenuState::mainMenuState()
//{
//	//GameState * gameState;
//	//gameState = new mainMenuState();
//}

//mainMenuState::~mainMenuState()
//{
//}

//inherits all member functions from from GameState 
//a game state i.e main menu state
//render can mean different things in different states
// the public allows access to GameStates private members 

void mainMenuState::input() {
	std::cin >> mychar;
};

void mainMenuState::changeState(GameState* gameState) { std::cout << "main menu change state"; };

void mainMenuState::render()  {

	std::cout << "Zorkish::Main Menu" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Welcome to Zorkish Adventures" << std::endl;
	std::cout << "1. Select Adventure and Play" << std::endl;
	std::cout << "2. Hall Of Fame" << std::endl;
	std::cout << "3. Help" << std::endl;
	std::cout << "4. About" << std::endl;
	std::cout << "5. Quit" << std::endl;
	std::cout << "Select 1 - 5:> _" << std::endl;
};
