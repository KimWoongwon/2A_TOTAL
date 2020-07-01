#include "HealerItemFactory.h"
const char* HealerItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "성서";
	else if (kind == ORC)
		return "주술서";
	else if (kind == ELF)
		return "치유의 오브";
}
const char* HealerItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "흰색 사제복";
	else if (kind == ORC)
		return "주술사 의복";
	else if (kind == ELF)
		return "치유사의 로브";
}