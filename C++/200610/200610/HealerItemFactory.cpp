#include "HealerItemFactory.h"
const char* HealerItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "����";
	else if (kind == ORC)
		return "�ּ���";
	else if (kind == ELF)
		return "ġ���� ����";
}
const char* HealerItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "��� ������";
	else if (kind == ORC)
		return "�ּ��� �Ǻ�";
	else if (kind == ELF)
		return "ġ������ �κ�";
}