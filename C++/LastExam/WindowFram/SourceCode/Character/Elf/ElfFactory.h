#pragma once
#include "Elf.h"
#include "../CharacterFactory.h"

class ElfFactory : public CharacterFactory
{
private:
	int count;
	virtual Character* CreateCharacter(const char*, CLASS);
public:
	ElfFactory();
	~ElfFactory();
};

