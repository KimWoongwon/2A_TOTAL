#include "Global.h"
#include "Character.h"
Character::Character(const char* p_name, const char* p_petname,JOB pjob, ItemFactory* p_factory)
{
	strcpy_s(name, sizeof(name), p_name);
	strcpy_s(pet, sizeof(pet), p_petname);
	Level = 1;
	status = new STATUS(10, 5, 20, 3);
	blacksmith = p_factory;
	strcpy_s(Weapon, sizeof(Weapon), blacksmith->CreateWeapon());
	strcpy_s(Armor, sizeof(Armor), blacksmith->CreateArmor());
	job = pjob;
}
Character::~Character()
{
	delete status;
}
void Character::SetName(const char* p_name)
{
	strcpy_s(name, sizeof(name), p_name);
}
const char* Character::GetName()
{
	return name;
}
int Character::GetLevel()
{
	return Level;
}
STATUS* Character::GetStatus()
{
	return status;
}
const char* Character::GetPetkind()
{
	return pet;
}
const char* Character::GetKind()
{
	if (kind == HUM)
		return "�ΰ�";
	else if (kind == ORC)
		return "��ũ";
	else if (kind == ELF)
		return "����";
}
const char* Character::GetJOB()
{
	if (job == WARRIOR)
		return "����";
	else if (job == HEALER)
		return "����";
	else if (job == ARCHER)
		return "�ü�";
	else if (job == SORCERER)
		return "������";
}
const char* Character::GetWeapon()
{
	return Weapon;
}
const char* Character::GetArmor()
{
	return Armor;
}