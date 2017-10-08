#include "PlayerCharacter.h"



void PlayerCharacter::printName() const
{
	std::cout << this->characterName;
}

void PlayerCharacter::initialize(const std::string name)
{
	this->characterName = name;
}

