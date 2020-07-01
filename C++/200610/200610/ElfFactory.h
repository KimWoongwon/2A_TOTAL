#pragma once
#include "Elf.h"
#include "CharacterFactory.h"
class ElfFactory : public CharacterFactory
{
private:
	Pet* PossiblePetList[4];
	int count;

	virtual Character* CreateCharacter(const char*, const char*);
	virtual Pet* PetSelect();
public:
	ElfFactory();
	~ElfFactory();
};

