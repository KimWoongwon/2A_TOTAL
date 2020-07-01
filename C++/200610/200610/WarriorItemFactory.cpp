#include "WarriorItemFactory.h"
const char* WarriorItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "��ö �Ѽհ˰� ����";
	else if (kind == ORC)
		return "��ö �ֵ���";
	else if (kind == ELF)
		return "��ö �����Ǿ�";
}
const char* WarriorItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "��ö����";
	else if (kind == ORC)
		return "�罽����";
	else if (kind == ELF)
		return "���װ���";
}