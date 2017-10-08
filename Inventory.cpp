#include "Inventory.h"


//inventory constructor
Inventory::Inventory()
{
	this->numOfItems = this->itemVector.size();
};

void Inventory::addItem(Item & item)
{
	this->itemVector.push_back(new Item(item));
	this->numOfItems = this->itemVector.size();
};

void Inventory::removeItem(int index)
{
	this->itemVector.erase(this->itemVector.begin() + index);
	this->numOfItems = this->itemVector.size();
}

void Inventory::getItem(Inventory inventory, Item item)
{
	std::cout << " what would you like to do : add OR erase (Press 'a' or 'e')  ? ";
	std::cin >> mystring;
	if (mystring == "a") {
		std::cout << " what would you like to add  ? ";
		std::cin >> mystring;
		item.itemName = mystring;
		this->addItem(item);

		std::cout << "you now have" << std::endl;
		this->printItems();
	}
	else if (mystring == "e")
	{
		int choice;
		this->printItems();
		std::cout << " what number item would you like deleted ? ";
		std::cin >> choice;
		this->removeItem(choice);
		std::cout << "you now have" << std::endl;
		this->printItems();
	}
}
