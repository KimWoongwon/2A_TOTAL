#pragma once
#include "Human.h"
#include "CharacterFactory.h"
class HumanFactory : public CharacterFactory
{
private:
	Pet* PossiblePetList[2];
	int count;

	virtual Character* CreateCharacter(const char*, const char*);
	virtual Pet* PetSelect();

public:
	HumanFactory();
	~HumanFactory();
};

