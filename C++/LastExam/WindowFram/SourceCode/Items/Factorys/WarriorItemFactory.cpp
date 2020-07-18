#include "WarriorItemFactory.h"
Weapon* WarriorItemFactory::CreateWeapon()
{
	if (region == REGION::HUM)
		return new Weapon("°­Ã¶ ÇÑ¼Õ°Ë°ú ¹æÆÐ", new STATUS(75, 0, 30, 20), 1000, CLASS::WARRIOR);
	else if (region == REGION::ORC)
		return new Weapon("°­Ã¶ ½Öµµ³¢", new STATUS(25, 0, 100, 0), 1000, CLASS::WARRIOR);
	else if (region == REGION::ELF)
		return new Weapon("°­Ã¶ ·¹ÀÌÇÇ¾î", new STATUS(0, 0, 100, 25), 1000, CLASS::WARRIOR);
}
Armor* WarriorItemFactory::CreateArmor()
{
	if (region == REGION::HUM)
		return new Armor("°­Ã¶°©¿Ê", new STATUS(100, 10, 0, 50), 500, CLASS::WARRIOR);
	else if (region == REGION::ORC)
		return new Armor("»ç½½°©¿Ê", new STATUS(120, -20, 10, 50), 500, CLASS::WARRIOR);
	else if (region == REGION::ELF)
		return new Armor("°¡Á×°©¿Ê", new STATUS(80, 20, 20, 40), 500, CLASS::WARRIOR);
}