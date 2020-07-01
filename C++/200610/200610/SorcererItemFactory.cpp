#include "SorcererItemFactory.h"
Weapon* SorcererItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return new Weapon("���� ���� ������", new STATUS(0, 75, 40, 10), 1000, CODE_SORCERER);
	else if (kind == ORC)
		return new Weapon("�ı��� �ϵ�", new STATUS(0, 50, 70, 10), 1000, CODE_SORCERER);
	else if (kind == ELF)
		return new Weapon("���ڿ��� ������", new STATUS(0, 100, 30, 20), 1000, CODE_SORCERER);
}
Armor* SorcererItemFactory::CreateArmor()
{
	if (kind == HUM)
		return new Armor("Ǫ���� �κ�", new STATUS(50, 100, 0, 10), 500, CODE_SORCERER);
	else if (kind == ORC)
		return new Armor("�������� �κ�", new STATUS(50, 75, 0, 35), 500, CODE_SORCERER);
	else if (kind == ELF)
		return new Armor("�ڿ��� ǰ�� �κ�", new STATUS(20, 125, 0, 5), 500, CODE_SORCERER);
}