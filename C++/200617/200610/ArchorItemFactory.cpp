#include "ArchorItemFactory.h"
Weapon* ArchorItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return new Weapon("Àå±Ã", new STATUS(0, 0, 50, 0), 1000, CODE_ARCHOR);
	else if (kind == ORC)
		return new Weapon("¿ÀÅ©Á¦ °Å±Ã", new STATUS(0, 0, 75, -25), 1000, CODE_ARCHOR);
	else if (kind == ELF)
		return new Weapon("¿¤ÇÁÁ¦ ´Ü±Ã", new STATUS(0, 0, 100, -50), 1000, CODE_ARCHOR);
}
Armor* ArchorItemFactory::CreateArmor()
{
	if (kind == HUM)
		return new Armor("»ç³É²ÛÀÇ °¡Á× Á¶³¢", new STATUS(80, 40, 0, 40), 500, CODE_ARCHOR);
	else if (kind == ORC)
		return new Armor("´Á´ë °¡Á× Á¶³¢", new STATUS(100, -20, 40, 40), 500, CODE_ARCHOR);
	else if (kind == ELF)
		return new Armor("Áú±ä ³ª¹«µ¢Äð Á¶³¢", new STATUS(60, -20, 60, 20), 500, CODE_ARCHOR);
}