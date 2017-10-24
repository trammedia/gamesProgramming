#include "chooseAdventureState.h"


//chooseAdventureState::chooseAdventureState()
//{
//}

//chooseAdventureState::~chooseAdventureState()
//{
//};
void chooseAdventureState::input() { std::cin >> mychar; };

void chooseAdventureState::changeState(GameState * gameState) {
		std::cout << "main menu change state";
	};

//overrides GameState init() from other class
void chooseAdventureState::render() {

		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "Choose your adventure :" << std::endl;
		std::cout << "1. Mountain World" << std::endl;
		std::cout << "2. Water World" << std::endl;
		std::cout << "3. Box World" << std::endl;
		std::cout << "Select 1 - 3 :" << std::endl;
};

