#pragma once
#include "Global.h"
#include "ItemFactory.h"

class ArchorItemFactory : public ItemFactory
{
public:
	ArchorItemFactory(CHAR_MENU p_kind) : ItemFactory(p_kind) {}
	~ArchorItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

