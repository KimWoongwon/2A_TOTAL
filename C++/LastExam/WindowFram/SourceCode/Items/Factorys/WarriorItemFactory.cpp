#include "WarriorItemFactory.h"
Weapon* WarriorItemFactory::CreateWeapon()
{
	if (region == REGION::HUM)
		return new Weapon("��ö �Ѽհ˰� ����", new STATUS(75, 0, 30, 20), 1000, CLASS::WARRIOR);
	else if (region == REGION::ORC)
		return new Weapon("��ö �ֵ���", new STATUS(25, 0, 100, 0), 1000, CLASS::WARRIOR);
	else if (region == REGION::ELF)
		return new Weapon("��ö �����Ǿ�", new STATUS(0, 0, 100, 25), 1000, CLASS::WARRIOR);
}
Armor* WarriorItemFactory::CreateArmor()
{
	if (region == REGION::HUM)
		return new Armor("��ö����", new STATUS(100, 10, 0, 50), 500, CLASS::WARRIOR);
	else if (region == REGION::ORC)
		return new Armor("�罽����", new STATUS(120, -20, 10, 50), 500, CLASS::WARRIOR);
	else if (region == REGION::ELF)
		return new Armor("���װ���", new STATUS(80, 20, 20, 40), 500, CLASS::WARRIOR);
}