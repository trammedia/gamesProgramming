#pragma once
#include "GameState.h"
class Area :
	public GameState
{
public:
	int areaId;
	std::string name;
	std::string description;
	std::map <std::string,int> mapExits;

	void printName() const;
	void printAreaId() const;
	void initialize(const std::string name);

	inline const std::string& getName() const { return this->areaName; }
	inline const int& getAreaId() const { return this->areaId2; }

	virtual void Look();
	void Exits();

	virtual void input(GameState * gameState, std::unordered_multimap<std::string, std::string> mapped2, std::map<std::string, std::string>  mapIds);

	virtual void render();

	virtual void changeState(GameState * gameState, std::unordered_multimap<std::string, std::string> mapped2, int myint, std::map<std::string, std::string>  mapIds);

	inline std::string prinName() const
	{
		return this->name;
	};

private:

	std::string areaName;
	int areaId2;
};

