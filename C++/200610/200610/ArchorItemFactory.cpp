#include "ArchorItemFactory.h"
Weapon* ArchorItemFactory::CreateWeapon()
{
	if (kind == HUM)
		return new Weapon("���", new STATUS(0, 0, 50, 0), 1000, CODE_ARCHOR);
	else if (kind == ORC)
		return new Weapon("��ũ�� �ű�", new STATUS(0, 0, 75, -25), 1000, CODE_ARCHOR);
	else if (kind == ELF)
		return new Weapon("������ �ܱ�", new STATUS(0, 0, 100, -50), 1000, CODE_ARCHOR);
}
Armor* ArchorItemFactory::CreateArmor()
{
	if (kind == HUM)
		return new Armor("��ɲ��� ���� ����", new STATUS(80, 40, 0, 40), 500, CODE_ARCHOR);
	else if (kind == ORC)
		return new Armor("���� ���� ����", new STATUS(100, -20, 40, 40), 500, CODE_ARCHOR);
	else if (kind == ELF)
		return new Armor("���� �������� ����", new STATUS(60, -20, 60, 20), 500, CODE_ARCHOR);
}