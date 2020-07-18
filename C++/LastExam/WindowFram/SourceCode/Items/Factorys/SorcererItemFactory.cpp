#include "SorcererItemFactory.h"
Weapon* SorcererItemFactory::CreateWeapon()
{
	if (region == REGION::HUM)
		return new Weapon("���� ���� ������", new STATUS(0, 75, 40, 10), 1000, CLASS::SORCERER);
	else if (region == REGION::ORC)
		return new Weapon("�ı��� �ϵ�", new STATUS(0, 50, 70, 10), 1000, CLASS::SORCERER);
	else if (region == REGION::ELF)
		return new Weapon("���ڿ��� ������", new STATUS(0, 100, 30, 20), 1000, CLASS::SORCERER);
}
Armor* SorcererItemFactory::CreateArmor()
{
	if (region == REGION::HUM)
		return new Armor("Ǫ���� �κ�", new STATUS(50, 100, 0, 10), 500, CLASS::SORCERER);
	else if (region == REGION::ORC)
		return new Armor("�������� �κ�", new STATUS(50, 75, 0, 35), 500, CLASS::SORCERER);
	else if (region == REGION::ELF)
		return new Armor("�ڿ��� ǰ�� �κ�", new STATUS(20, 125, 0, 5), 500, CLASS::SORCERER);
}