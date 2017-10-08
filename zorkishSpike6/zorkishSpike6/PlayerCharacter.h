#pragma once
#include "main.h"

class PlayerCharacter {

public:

	//functions

	void printName() const;
	void initialize(const std::string name);

	inline const std::string& getName() const { return this->characterName; }
	inline const double& getXpos() const { return this->xpos; }
	inline const double& getYpos() const { return this->ypos; }

	//modifiers



private:
	std::string characterName;
	double xpos;
	double ypos;

};