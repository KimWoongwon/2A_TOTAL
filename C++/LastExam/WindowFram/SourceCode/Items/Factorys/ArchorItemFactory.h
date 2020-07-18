#pragma once
#include "../../Global.h"
#include "ItemFactory.h"

// 아처 클래스 아이템 팩토리
class ArchorItemFactory : public ItemFactory
{
public:
	ArchorItemFactory(REGION p_kind) : ItemFactory(p_kind) {}
	~ArchorItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

