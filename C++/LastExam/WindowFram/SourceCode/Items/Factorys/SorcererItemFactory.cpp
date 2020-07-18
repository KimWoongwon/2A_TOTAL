#include "SorcererItemFactory.h"
Weapon* SorcererItemFactory::CreateWeapon()
{
	if (region == REGION::HUM)
		return new Weapon("압축 비전 스태프", new STATUS(0, 75, 40, 10), 1000, CLASS::SORCERER);
	else if (region == REGION::ORC)
		return new Weapon("파괴의 완드", new STATUS(0, 50, 70, 10), 1000, CLASS::SORCERER);
	else if (region == REGION::ELF)
		return new Weapon("대자연의 스태프", new STATUS(0, 100, 30, 20), 1000, CLASS::SORCERER);
}
Armor* SorcererItemFactory::CreateArmor()
{
	if (region == REGION::HUM)
		return new Armor("푸른색 로브", new STATUS(50, 100, 0, 10), 500, CLASS::SORCERER);
	else if (region == REGION::ORC)
		return new Armor("대족장의 로브", new STATUS(50, 75, 0, 35), 500, CLASS::SORCERER);
	else if (region == REGION::ELF)
		return new Armor("자연을 품은 로브", new STATUS(20, 125, 0, 5), 500, CLASS::SORCERER);
}