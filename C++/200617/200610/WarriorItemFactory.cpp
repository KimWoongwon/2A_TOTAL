#include "WarriorItemFactory.h"
Weapon* WarriorItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return new Weapon("��ö �Ѽհ˰� ����", new STATUS(75, 0, 30, 20), 1000, CODE_WARRIOR);
	else if (kind == ORC)
		return new Weapon("��ö �ֵ���", new STATUS(25, 0, 100, 0), 1000, CODE_WARRIOR);
	else if (kind == ELF)
		return new Weapon("��ö �����Ǿ�", new STATUS(0, 0, 100, 25), 1000, CODE_WARRIOR);
}
Armor* WarriorItemFactory::CreateArmor()
{
	if (kind == HUM)
		return new Armor("��ö����", new STATUS(100, 10, 0, 50), 500, CODE_WARRIOR);
	else if (kind == ORC)
		return new Armor("�罽����", new STATUS(120, -20, 10, 50), 500, CODE_WARRIOR);
	else if (kind == ELF)
		return new Armor("���װ���", new STATUS(80, 20, 20, 40), 500, CODE_WARRIOR);
}