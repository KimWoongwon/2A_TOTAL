#pragma once
#include "../../Global.h"
#include "ItemFactory.h"

// 워리어 클래스 아이템 팩토리
class WarriorItemFactory : public ItemFactory
{
public: 
	WarriorItemFactory(REGION p_kind) : ItemFactory(p_kind) {}
	~WarriorItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

