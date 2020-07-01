#include "HealerItemFactory.h"
Weapon* HealerItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return new Weapon("����", new STATUS(0, 100, 10, 40), 1000, CODE_HEALER);
	else if (kind == ORC)
		return new Weapon("�ּ���", new STATUS(0, 100, 20, 30), 1000, CODE_HEALER);
	else if (kind == ELF)
		return new Weapon("ġ���� ����", new STATUS(0, 120, 10, 20), 1000, CODE_HEALER);
}
Armor* HealerItemFactory::CreateArmor()
{
	if (kind == HUM)
		return new Armor("��� ������", new STATUS(50, 100, -10, 20), 500, CODE_HEALER);
	else if (kind == ORC)
		return new Armor("�ּ��� �Ǻ�", new STATUS(50, 80, 0, 30), 500, CODE_HEALER);
	else if (kind == ELF)
		return new Armor("ġ���� �κ�", new STATUS(30, 100, 0, 30), 500, CODE_HEALER);
}