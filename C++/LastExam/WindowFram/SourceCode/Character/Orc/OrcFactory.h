#pragma once
#include "Orc.h"
#include "../CharacterFactory.h"

class OrcFactory : public CharacterFactory
{
private:
	int count;
	
	virtual Character* CreateCharacter(const char*, CLASS);
public:
	OrcFactory();
	~OrcFactory();
};

