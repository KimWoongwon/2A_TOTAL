#pragma once
#include "../Weapon.h"
#include "../Armor.h"

// 캐릭터 팩토리에서 종족별로 정해져서 호출되는 팩토리 클래스
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

