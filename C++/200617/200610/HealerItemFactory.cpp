#include "HealerItemFactory.h"
Weapon* HealerItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return new Weapon("성서", new STATUS(0, 100, 10, 40), 1000, CODE_HEALER);
	else if (kind == ORC)
		return new Weapon("주술서", new STATUS(0, 100, 20, 30), 1000, CODE_HEALER);
	else if (kind == ELF)
		return new Weapon("치유의 오브", new STATUS(0, 120, 10, 20), 1000, CODE_HEALER);
}
Armor* HealerItemFactory::CreateArmor()
{
	if (kind == HUM)
		return new Armor("흰색 사제복", new STATUS(50, 100, -10, 20), 500, CODE_HEALER);
	else if (kind == ORC)
		return new Armor("주술사 의복", new STATUS(50, 80, 0, 30), 500, CODE_HEALER);
	else if (kind == ELF)
		return new Armor("치유사 로브", new STATUS(30, 100, 0, 30), 500, CODE_HEALER);
}