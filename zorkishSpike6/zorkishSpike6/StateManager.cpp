#include "StateManager.h"

//Constructor
StateManager::StateManager()
{
}

//Destructor
StateManager::~StateManager()
{
}


// ------------------------------StateManager --------------------------------

//member functions implementation
// these get / set the StateManager class
// ' :: ' is a getter / setter - keyword
//sets the change state in stateManager
void StateManager::changeState(GameState* gameState) {

	//StateManager* newState;
	//if the m_states vector is not empty
	if (!m_states.empty())
	{
		//vector.pop_back removes last element from the array 
		// this loop empties the vector
		m_states.pop_back();

	}
	// push new vector to the back of the array.
	m_states.push_back(gameState);

	//change the actual state to be shown //
	//m_states.back()->changeState(gameState);
};

//puts the given state into last place on the array
void StateManager::pushState(GameState* gameState) {

	//if the m_states vector is not empty
	if (!m_states.empty())
	{
		//puts the value into the last place on the array
		m_states.push_back(gameState);

		//returns a reference to the last element in the array
		m_states.back();
	}
};

// :: = getter, setter
//removes the last element in the vector (array)
void StateManager::popState(GameState* gameState) {

	//if the m_states vector is not empty
	if (!m_states.empty())
	{
		//vector.pop_back removes last element from the array 
		m_states.pop_back();
	}
};

void StateManager::render()
{
	//if the m_states vector is not empty
	if (!m_states.empty())
	{
		// render the state
		m_states.back()->render();
	}
};

void StateManager::input(GameState * gameState, std::unordered_multimap<std::string, std::string>  mapped2, std::map<std::string, std::string>  mapIds)
{
	//if the m_states vector is not empty
	if (!m_states.empty())
	{
		//goto the last vector array item access input 
		m_states.back()->input(gameState,  mapped2, mapIds);
		//return *gameState;
	}
};
