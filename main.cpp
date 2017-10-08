#include "main.h"
#include "GameState.h"
#include "StateManager.h"
#include "mainMenuState.h"
#include "chooseAdventureState.h"
#include "aboutState.h"
#include "highScoreState.h"
#include "helpState.h"
#include "Inventory.h"
#include "Item.h"
#include "PlayerCharacter.h"
#include "Area.h"
#include <map>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>

//--Global Variable Declaration---

char mychar;

int myint;

std::string mystring;


std::map<std::string, std::string> getMapIds(std::map<std::string, std::string> mapIds)
{
	std::ifstream myfile;
	int i = 0;
	std::string line, desc, exits, idNum;

	std::cout << " \n -----------Map  ID Listings Start--------------\n";

	//open the text file
	myfile.open("adventure4.txt");

	//creates a complete record
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			//get all the characters until ':'
			getline(myfile, mystring, ':');
			std::cout << "name: " << mystring << " " << std::endl;
			//add then into the map as 'name,name'
			//mapped3.insert({ mystring ,mystring });

			//get the new char until ':'
			getline(myfile, idNum, ':');
			std::cout << "ID: " << idNum << " " << std::endl;
			// add as 'name, idnumber'
			mapIds.insert(std::pair<std::string,std::string>( mystring ,idNum ));


			getline(myfile, desc, ':');
			std::cout << "desc: " << desc << " ";
			//mapped3.insert({ mystring ,desc });

			//get the exits as a group
			getline(myfile, exits);
			std::cout << "exits: " << exits << " " << std::endl;
			// get the group characters
			std::stringstream ss(exits);

			std::string token;
			std::string token2;
			//get all the characters from the group break at ',' i.e. 'south'
			//nect pass will get the number i.e.'4'
			while (std::getline(ss, token, ','))
			{
				std::cout << token << "\n";
				// add into the map as 'name, exit to room number'
				//mapped3.insert({ mystring ,token });

			}
		};

	};
	myfile.close();

	std::cout << " \n -----------Map  ID Listings End--------------\n";

	return mapIds;
};

// gets the whole line, puts the heading into the key, value into the element by Csv file 'Comma separated values'
//
std::unordered_multimap<std::string, std::string> getMapElements(std::unordered_multimap<std::string, std::string> mapped2)
{
	std::ifstream myfile;
	int i = 0;
	std::string line, desc, exits, idNum;

	std::cout << "\n -----------Map Listings-------------- \n";

	//open the text file
	myfile.open("adventure4.txt");
	//creates a complete record
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			//get all the characters until ':'
			getline(myfile, mystring, ':');
			std::cout << "name: " << mystring << " " << std::endl;
			//add then into the map as 'name,name'
			mapped2.insert({ mystring ,mystring });

			//get the new char until ':'
			getline(myfile, idNum, ':');
			std::cout << "ID: " << idNum << " " << std::endl;
			// add as 'name, idnumber'
			mapped2.insert({ mystring ,idNum });
			

			getline(myfile, desc, ':');
			std::cout << "desc: " << desc << " ";
			mapped2.insert({ mystring ,desc });

			//get the exits as a group
			getline(myfile, exits);
			std::cout << "exits: " << exits << " " << std::endl;
			
			// get the group characters
			std::stringstream ss(exits);
			std::string token;
			//get all the characters from the group break at ',' i.e. 'south'
			//nect pass will get the number i.e.'4'
			while (std::getline(ss, token, ','))
			{
				// add into the map as 'name, exit to room number'
				mapped2.insert({ mystring ,token });

			}
		}
	};

	myfile.close();

	std::cout << " \n -----------Map Listings End--------------\n";

	return mapped2;
}
//map graph of locations
class mygraph {
	struct node {  // nodes that you read:  
		std::string name; // name of area
		int id;            // index of the node in the nodes vector / room id
		std::vector<int> in;    // parent(s) that can lead to this node / what leads to it 
		std::vector<int> out;   // children you can go to / exits it leads to 
	};
	std::vector<node> nodes;    // all the nodes in arbitrary sequential order  / ??
	std::map<std::string, int> dict; // map converting the names into ids (redundant and optional, useful for efficien search by name); 
public:
	// members to populate the structure and to acces the nodes cleanly.   
};


int main() {

	mygraph gameMapGraph;

	std::cout << "Please add your name: ";
	std::cin >> mystring;
	//create variable called playercharacter
	PlayerCharacter playerCharacter;
	//initialize characyer with user string
	playerCharacter.initialize(mystring);

	//creates a new Item variable called 'item'
	Item item;
	//make the new item variables name equal to 'cat'
	item.itemName = "cat";
	// create a new inventory variable
	Inventory inventory;
	// add a new item to the inventory
	inventory.addItem(item);

	item.itemName = "dog";

	inventory.addItem(item);

	//print out new name
	playerCharacter.printName(); std::cout << "'s ";

	inventory.printItems();

	std::cout << " where to ?";

	typedef std::unordered_multimap<std::string, std::string> defineArea;
	typedef std::map<std::string, std::string> defineArea2;
	defineArea mapped2;
	defineArea2 mapped3;

	//assign results of getMap to mapped2
	mapped2 = getMapElements(mapped2);

	mapped3 = getMapIds(mapped3);

	// only finds the name "caveHole"
	//std::multimap<char, int>::iterator it, itlow, itup;
	/*auto search = mapped2.find("CaveHole");
	if (search != mapped2.end()) {
		std::cout << search->first << search->second << "\n";*/
		//mapCounter.insert(search->second);
	//}


	//for (auto it = mapped2.find("Staircase"); it != mapped2.end(); ++it) {
	//	//std::cout << "\n";
	//	std::cout << " first search about the map.= " << it->first << std::endl;
	//	std::cout << " 2nd entry= " << it->second << std::endl;
	//};


	////print all entries by iteration
	//for (auto it = mapped3.begin(); it != mapped3.end(); ++it) {
	//	//std::cout << "\n";
	//	std::cout << " first entry about the map.= " << it->first << std::endl;
	//	/*if ( % 2 == 1) {
	//		std::cout << " yippee!";
	//	}*/
	//	std::cout << " 2nd entry= " << it->second << std::endl;
	//};

	////cycle through all entries that begin with a Key'name'
	////i.e. staircase -> value
	//std::cout << "Entries with a:" << std::endl;
	//auto range = mapped3.equal_range("Staircase");
	//for_each(
	//	range.first,
	//	range.second,

	//	[](defineArea::value_type& x) {std::cout << " " << x.second << std::endl; }
	//);

	//create a new area and give it's details
	Area * areaState;
	areaState = new Area();

	//needs to be automated and self governing
	//setup areaState first fields
	areaState->name = "Riverside";
	areaState->areaId = 4;
	areaState->description = "Your at a bend in the river. There are is a path north. A path across the river to the east. Or you can go south to the wood along a dirt track.";
	areaState->mapExits["west"] = 2;
	
	std::set<std::string> dic;
	dic.insert("sword");
	dic.insert("kill");
	dic.insert("monster");

	std::string str = "take sword and kill monster";
	std::string delimiters = " ";

	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		if (dic.find(str.substr(lastPos, pos - lastPos)) != dic.end())
			std::cout << str.substr(lastPos, pos - lastPos)
			<< " is part of the dic.\n";
		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}


	// makes a pointer to Gamestate
	GameState* gameState;

	//makes a new gamestate mainMenuState
	//gameState = new mainMenuState();

	gameState = areaState;
	// constructor?
	//gameState = new Area(std::string name, std::string description, std::vector <std::string> mapExits);

	// make a new state called newState with a pointer *- instantiate
	StateManager* newState = new StateManager();

	//changes the state places areaState into m_states vector
	newState->changeState(gameState);
	//tells gamestate to render itself
	//gameState->render();
	
	std::cout << "begin";
	//gets input
	
	std::getline(std::cin , mystring);
	
	// while q isn't chosen
	while (mystring != "q") {

		/*if (mychar == '1') {
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
		};*/

		// draws the gameState
		//newState->render();
		std::cout << "before \n";
		//render the current state
		gameState->render();
		std::cout << "between \n";
		//go to this areas input member function
		gameState->input(gameState, mapped2, mapped3);

	};

	return 0;
};