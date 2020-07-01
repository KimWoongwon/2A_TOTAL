#pragma once
#include "Weapon.h"
#include "Armor.h"
class ItemFactory
{
protected:
	CHAR_MENU kind;
public:
	ItemFactory(CHAR_MENU p_kind) { kind = p_kind; }
	~ItemFactory() {}

	virtual Weapon* CreateWeapon() = 0;
	virtual Armor* CreateArmor() = 0;
};

