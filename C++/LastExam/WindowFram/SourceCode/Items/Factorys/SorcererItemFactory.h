#pragma once
#include "../../Global.h"
#include "ItemFactory.h"

// 소서러 클래스 아이템 팩토리
class SorcererItemFactory : public ItemFactory
{
public:
	SorcererItemFactory(REGION p_kind) : ItemFactory(p_kind) {}
	~SorcererItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

