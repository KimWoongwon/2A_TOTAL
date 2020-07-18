#pragma once
#include "../../Global.h"
#include "ItemFactory.h"

// ������ Ŭ���� ������ ���丮
class WarriorItemFactory : public ItemFactory
{
public: 
	WarriorItemFactory(REGION p_kind) : ItemFactory(p_kind) {}
	~WarriorItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

