#include "SorcererItemFactory.h"
const char* SorcererItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return "���� ���� ������";
	else if (kind == ORC)
		return "�ı��� �ϵ�";
	else if (kind == ELF)
		return "���ڿ��� ������";
}
const char* SorcererItemFactory::CreateArmor()
{
	if (kind == HUM)
		return "Ǫ���� �κ�";
	else if (kind == ORC)
		return "�������� �κ�";
	else if (kind == ELF)
		return "�ڿ��� ǰ�� �κ�";
}