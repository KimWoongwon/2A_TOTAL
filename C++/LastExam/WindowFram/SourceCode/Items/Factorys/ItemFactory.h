#pragma once
#include "../Weapon.h"
#include "../Armor.h"

// ĳ���� ���丮���� �������� �������� ȣ��Ǵ� ���丮 Ŭ����
class ItemFactory
{
protected:
	REGION region;
public:
	ItemFactory(REGION p_kind) { region = p_kind; }
	~ItemFactory() {}

	virtual Weapon* CreateWeapon() = 0;
	virtual Armor* CreateArmor() = 0;
};

