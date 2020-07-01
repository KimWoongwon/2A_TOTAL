#pragma once
#include "Global.h"
#include "ItemFactory.h"

class WarriorItemFactory : public ItemFactory
{
public: 
	WarriorItemFactory(CHAR_MENU p_kind) : ItemFactory(p_kind) {}
	~WarriorItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

