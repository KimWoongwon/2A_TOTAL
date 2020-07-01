#pragma once
#include "Global.h"
#include "ItemFactory.h"
class ArchorItemFactory : public ItemFactory
{
public:
	ArchorItemFactory(CHAR_MENU p_kind) : ItemFactory(p_kind) {}
	~ArchorItemFactory() {}

	virtual const char* CreateWeapon();
	virtual const char* CreateArmor();
};

