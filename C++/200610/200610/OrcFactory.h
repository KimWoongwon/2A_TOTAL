#pragma once
#include "Orc.h"
#include "CharacterFactory.h"
class OrcFactory : public CharacterFactory
{
private:
	Pet* PossiblePetList[2];
	int count;

	virtual Character* CreateCharacter(const char*, const char*);
	virtual Pet* PetSelect();
public:
	OrcFactory();
	~OrcFactory();
};

