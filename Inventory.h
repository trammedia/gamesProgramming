#pragma once
#include "Item.h"

// inventory contains the vector array of items and the vectors functionality
class Inventory {

public:

	Inventory();
	//~Inventory();
	int numOfItems;

	// a vector array of Items pointers*
	std::vector <Item*> itemVector;

	void addItem(Item & item);

	void removeItem(int index);

	void getItem(Inventory inventory, Item item);

	inline void printItems() const {
		std::cout << "Inventory" << std::endl;
		std::cout << "---------" << std::endl;
		for (int i = 0; i < numOfItems; i++)
		{
			std::cout << (i) << ": " << this->itemVector[i]->itemName << std::endl;
		}
	}
};