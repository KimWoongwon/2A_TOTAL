#include "SorcererItemFactory.h"
Weapon* SorcererItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return new Weapon("압축 비전 스태프", new STATUS(0, 75, 40, 10), 1000, CODE_SORCERER);
	else if (kind == ORC)
		return new Weapon("파괴의 완드", new STATUS(0, 50, 70, 10), 1000, CODE_SORCERER);
	else if (kind == ELF)
		return new Weapon("대자연의 스태프", new STATUS(0, 100, 30, 20), 1000, CODE_SORCERER);
}
Armor* SorcererItemFactory::CreateArmor()
{
	if (kind == HUM)
		return new Armor("푸른색 로브", new STATUS(50, 100, 0, 10), 500, CODE_SORCERER);
	else if (kind == ORC)
		return new Armor("대족장의 로브", new STATUS(50, 75, 0, 35), 500, CODE_SORCERER);
	else if (kind == ELF)
		return new Armor("자연을 품은 로브", new STATUS(20, 125, 0, 5), 500, CODE_SORCERER);
}