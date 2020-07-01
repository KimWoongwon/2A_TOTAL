#pragma once
#include "Global.h"
#include "ItemFactory.h"

class HealerItemFactory : public ItemFactory
{
public:
	HealerItemFactory(CHAR_MENU p_kind) : ItemFactory(p_kind) {}
	~HealerItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

