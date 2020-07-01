#include "ArchorItemFactory.h"
const char* ArchorItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "���";
	else if (kind == ORC)
		return "��ũ�� �ű�";
	else if (kind == ELF)
		return "������ �ܱ�";
}
const char* ArchorItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "��ɲ��� ��������";
	else if (kind == ORC)
		return "������ ��������";
	else if (kind == ELF)
		return "���� �������� ����";
}