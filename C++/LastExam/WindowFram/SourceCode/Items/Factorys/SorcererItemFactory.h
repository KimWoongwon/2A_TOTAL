#pragma once
#include "../../Global.h"
#include "ItemFactory.h"

// �Ҽ��� Ŭ���� ������ ���丮
class SorcererItemFactory : public ItemFactory
{
public:
	SorcererItemFactory(REGION p_kind) : ItemFactory(p_kind) {}
	~SorcererItemFactory() {}

	virtual Weapon* CreateWeapon();
	virtual Armor* CreateArmor();
};

