#include "main.h"
#include "GameState.h"
#include "StateManager.h"
#include "mainMenuState.h"
#include "chooseAdventureState.h"
#include "aboutState.h"
#include "highScoreState.h"
#include "helpState.h"

//--Global Variable Declaration---

char mychar;

int main() {

	// makes a pointer to Gamestate
	GameState* gameState;

	////makes a new gamestate
	gameState = new mainMenuState();

	// make a new state called newState with a pointer *- instantiate
	StateManager* newState = new StateManager();

	//set/change the state to main menu in the vector list
	newState->changeState(gameState);

	// draws the gameState
	newState->render();

	//gets imput
	newState->input();

	//changes the state
	//newState->changeState(gameState);

	// while q isn't chosen
	while (mychar != 'q') {


		if (mychar == '1') {
			gameState = new chooseAdventureState();
			newState->changeState(gameState);
		};
		if (mychar == '2') {
			gameState = new highScoreState();
			newState->changeState(gameState);
		};
		if (mychar == '3') {
			gameState = new helpState();
			newState->changeState(gameState);
		};
		if (mychar == '4') {
			gameState = new aboutState();
			newState->changeState(gameState);
		};
	
		if (mychar == '5') {
			gameState = new mainMenuState();
			newState->changeState(gameState);
		};

		// draws the gameState
		newState->render();

		//gets input
		newState->input();

	};

	return 0;
};