#include "ArchorItemFactory.h"
const char* ArchorItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "Àå±Ã";
	else if (kind == ORC)
		return "¿ÀÅ©Á¦ °Å±Ã";
	else if (kind == ELF)
		return "¿¤ÇÁÁ¦ ´Ü±Ã";
}
const char* ArchorItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "»ç³É²ÛÀÇ °¡Á×Á¶³¢";
	else if (kind == ORC)
		return "´Á´ëÀÇ °¡Á×Á¶³¢";
	else if (kind == ELF)
		return "Áú±ä ³ª¹«µ¢Äð Á¶³¢";
}