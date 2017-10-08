// zorkish Game in C++
//author Justin Caddaye
//created August 2017
//Swinburne Games Programming

//incude input output stream
#include <iostream>
//include string functions
#include <string>
//standard library .h means header
#include <stdlib.h>
#include <thread>
#include <vector>

using namespace std;

//--------------------------------Forward_Declarations-------------------------------

class PlayerCharacter;

//--------------------------------GLOBAL_VARIABLES-------------------------------

// declaring  variables:
//define a string outside a class makes it a global variable
string mystring;

char mychar;

//---------------------------------Item_Class---------------------------------

class Item {

public:
	string itemName;

	inline string printItems() const
	{
		return this->itemName;
	};

};


// inventory contains the vector array of items and the vectors functionality
class Inventory {

public:
	Inventory();
	//~Inventory();
	int numOfItems;

	// a vector array of Items pointers*
	vector <Item*> itemVector;

	void addItem(Item & item);

	void removeItem(int index);

	void getItem(Inventory inventory, Item item);

	inline void printItems() const {
		cout << "Inventory" << endl;
		cout << "---------" << endl;
		for (int i = 0; i < numOfItems; i++)
		{
			cout << (i) << ": " << this->itemVector[i]->itemName << endl;
		}
	}
};

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
	cout << " what would you like to do : add OR erase (Press 'a' or 'e')  ? ";
	cin >> mystring;
	if (mystring == "a") {
		cout << " what would you like to add  ? ";
		cin >> mystring;
		item.itemName = mystring;
		this->addItem(item);

		cout << "you now have" << endl;
		this->printItems();
	}
	else if (mystring == "e")
	{
		int choice;
		this->printItems();
		cout << " what number item would you like deleted ? ";
		cin >> choice;
		this->removeItem(choice);
		cout << "you now have" << endl;
		this->printItems();
	}
}


class PlayerCharacter {

public:

	//functions

	void printName() const;
	void initialize(const string name);

	inline const string& getName() const { return this->characterName; }
	inline const double& getXpos() const { return this->xpos; }
	inline const double& getYpos() const { return this->ypos; }

	//modifiers



private:
	string characterName;
	double xpos;
	double ypos;

};

void PlayerCharacter::printName() const
{
	cout << this->characterName;
}

void PlayerCharacter::initialize(const string name)
{
	this->characterName = name;
}



// ------------------------------------------main--------------------------------

int main() {
	cout << "Please add your name: ";
	cin >> mystring;
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
	playerCharacter.printName(); cout << "'s ";
	inventory.printItems();

	while (mystring != "q")
	{
		inventory.getItem(inventory, item);
	}

	return 0;
}