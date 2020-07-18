#pragma once
#include "../../Global.h"
#include "ItemFactory.h"

// ��ó Ŭ���� ������ ���丮
class ArchorItemFactory : public ItemFactory
{
public:
	ArchorItemFactory(REGION p_kind) : ItemFactory(p_kind) {}
	~ArchorItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

