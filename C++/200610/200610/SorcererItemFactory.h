#pragma once
#include "Global.h"
#include "ItemFactory.h"
class SorcererItemFactory : public ItemFactory
{
public:
	SorcererItemFactory(CHAR_MENU p_kind) : ItemFactory(p_kind) {}
	~SorcererItemFactory() {}

	virtual const char* CreateWeapon();
	virtual const char* CreateArmor();
};
