#include "SorcererItemFactory.h"
const char* SorcererItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "압축 비전 스태프";
	else if (kind == ORC)
		return "파괴의 완드";
	else if (kind == ELF)
		return "대자연의 스태프";
}
const char* SorcererItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "푸른색 로브";
	else if (kind == ORC)
		return "대족장의 로브";
	else if (kind == ELF)
		return "자연을 품은 로브";
}