#include "Area.h"
#include <unordered_map>
#include <algorithm>
#include <istream>
#include <ostream>
#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include "Parser.h"

//Area::Area()
//{
//	this->name = name;
//	this->description = description;
//	this->mapExits = mapExits;
//}

//Area::~Area()
//{
//}



void Area::printName() const
{
	std::cout << this->areaName;
}

void Area::printAreaId() const
{
	std::cout << this->areaId2;
}

void Area::initialize(const std::string name)
{
	this->areaName = name;
}

void Area::input(GameState * gameState, std::unordered_multimap<std::string, std::string>
	mapped2, std::map<std::string, std::string> mapIds)
{
	// get input
	std::string userCommands;
	std::getline(std::cin , userCommands);
	std::vector <std::string> command;
	// crete the parser object
	Parser parser;
	//pass the vector and userCommands to the Parser
	command = parser.test(command, userCommands);

	//begin testing the first userCommand
	if (command[0] == "l" || command[0] == "look" )
	{
		this->Look();
	}
	if (command[0] == "e" || command[0] == "exit")
	{
		this->Exits();
	}
	if (command[0] == "g" || command[0] == "go")
	{
		// there is such an element in mapExits i.e. south
		if (this->mapExits.find(command[1]) != this->mapExits.end())
		{ // search through all mapExits
			for (auto it = this->mapExits.begin(); it != this->mapExits.end(); ++it) {
				//when you find the right one e.g if mapExits.first = east
				if (it->first == command[1]) {
					//make myint the new areaId
					myint = it->second;
					//change the state
					this->changeState(gameState, mapped2, myint, mapIds);
				};
			};
		};
		
	}
	else { std::cout << "command not found"; };
};

void Area::render() 
{
	std::cout << "\n-------------------\n" << std::endl;
	std::cout  << this->name << "\n" ;
	std::cout << this->description << "\n";
	std::cout << "It has exits: = ";

	for (auto it = this->mapExits.begin(); it != this->mapExits.end(); ++it) {
			std::cout <<  it->first ;
			std::cout <<  it->second << std::endl;
		};

};

void Area::changeState(GameState * gameState, std::unordered_multimap<std::string, std::string>
	mapped2, int myint, std::map<std::string, std::string>  mapIds)
{
	//in here it needs to know where to go beyond n,s,e,w 
	//so go - [word] , match word with available exits
	//
	std::vector <std::string> areaValues;

	//change areStateID to new ID
	this->areaId = myint;

	//cast int to string
	std::string castString = static_cast<std::ostringstream*>(&(std::ostringstream() << myint))->str();

	//print all entries by iteration from -> to key value
	//cycle through mapped 3
	for (auto it = mapIds.begin(); it != mapIds.end(); ++it) {
		// if the id matches a record , get the name
		//if id matched new int
		if (it->second == castString) {
			//change this area name is ...
			this->name = it->first;
		};
	};

	int i = 0;
	// all entries by iteration from -> to key value
	//cycle through mapped 2 
	for (auto it = mapped2.begin(); it != mapped2.end(); ++it) {
		// if the id matches a record , get the name
		// if cave = cave
		if (it->first == this->name) {
			//this area name is ...
			//gather values in vector with matching areaNAme i.e name,id,desc,exits
			areaValues.push_back(it->second);
			i++;

		};
	};

	//change this area desc  to the new area desc
	this->description = areaValues[2];

	//set up mapExits
	std::vector <std::string> temp;
	std::vector <int> temp2;
	int i2;
	i = 0;
	//get the fields after the name and ID num in mapped2
	// i.e. cave north, cave 1
	//and divides them into two vectors
	for (unsigned i = 3; i < areaValues.size(); i++) {
		i2 = i;
		//get the even values
		if (i2 % 2 == 1) {
			temp.push_back(areaValues[i]);
		};

		//get the odd values
		if (i2 % 2 != 1) {
			int Number;
			if (!(std::istringstream(areaValues[i]) >> Number)) Number = 0;
			temp2.push_back(Number);
		};
	};
			i = 0;
			//gather new mapExits in new area
			for (unsigned i = 0; i < temp.size(); i++)
			{
				//match names and room ids
				this->mapExits.insert(std::pair <std::string,int>( temp[i], temp2[i] ));
			};
	};

void Area::Look() {

	std::cout << "You are in " << this->name;
	std::cout << this->description;
	std::cout << "There are exits to \n";
	for (auto it = this->mapExits.begin(); it != this->mapExits.end(); ++it) {
		std::cout << "\n";
		std::cout << it->first;
		std::cout << it->second << std::endl;
	};
	
};

void Area::Exits() {

	std::cout << "There are exits to \n";
	for (auto it = this->mapExits.begin(); it != this->mapExits.end(); ++it) {
		std::cout << "\n";
		std::cout << it->first;
		std::cout << it->second << std::endl;
	};
	
};