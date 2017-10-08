#include "Parser.h"


//
//Parser::Parser()
//{
//}
//
//
//Parser::~Parser()
//{
//}

std::vector <std::string> Parser::test(std::vector <std::string> command, std::string mystring) {
	
	//clear the vector command
	command.clear();
	//set the delimiter
	std::string delimiter = " ";
	size_t pos = 0;
	std::string token;
	int i=0;
	//iterate through the string until you find the delimiter
	while ((pos = mystring.find(delimiter) && i != 1)) {
		//geth all the chars until the delimiter
		token = mystring.substr(0, pos+1);
		i++;
		command.push_back(token);
		
	};

	delimiter = " ";
	i = 0;
	pos = 0;
	while ((pos = mystring.find(delimiter) && i != 1)) {
		token = mystring.substr(pos+2, std::string::npos);
		command.push_back(token);
		i++;
	}
	std::cout << mystring << std::endl;
	return command;

	
}

