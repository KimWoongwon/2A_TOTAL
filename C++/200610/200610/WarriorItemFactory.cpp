#include "WarriorItemFactory.h"
const char* WarriorItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "°­Ã¶ ÇÑ¼Õ°Ë°ú ¹æÆÐ";
	else if (kind == ORC)
		return "°­Ã¶ ½Öµµ³¢";
	else if (kind == ELF)
		return "°­Ã¶ ·¹ÀÌÇÇ¾î";
}
const char* WarriorItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "°­Ã¶°©¿Ê";
	else if (kind == ORC)
		return "»ç½½°©¿Ê";
	else if (kind == ELF)
		return "°¡Á×°©¿Ê";
}