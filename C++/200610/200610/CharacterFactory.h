#pragma once
#include "Global.h"
#include "Character.h"

class CharacterFactory
{
protected:
	struct Pet
	{
		char pet_Name[20];

		Pet(const char* name)
		{
			strcpy_s(pet_Name, sizeof(pet_Name), name);
		}
	};

	virtual Character* CreateCharacter(const char*, const char*) = 0;
	virtual Pet* PetSelect() = 0;
public:
	CharacterFactory();
	virtual ~CharacterFactory();
	Character* SettingCharacter();

};

