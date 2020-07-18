#include "CharacterFactory.h"
CharacterFactory::CharacterFactory()
{

}
CharacterFactory::~CharacterFactory()
{

}
Character* CharacterFactory::SettingCharacter(const char* p_name, CLASS p_cls)
{
	Character* tempchar = CreateCharacter(p_name, p_cls);

	tempchar->SetHp();
	tempchar->SetMp();
	tempchar->SetATK();
	tempchar->SetDEF();
	// ó���� �����ɶ� �κ��丮�� �̴ϼȶ������ �������� �������־��� ������ �̺κп��� ������ ������ ������ �߰����ش�.
	tempchar->GetStatus()->Hp += tempchar->GetWeapon()->GetStatus()->Hp + tempchar->GetArmor()->GetStatus()->Hp;
	tempchar->GetStatus()->Mp += tempchar->GetWeapon()->GetStatus()->Mp + tempchar->GetArmor()->GetStatus()->Mp;
	tempchar->GetStatus()->ATK += tempchar->GetWeapon()->GetStatus()->ATK + tempchar->GetArmor()->GetStatus()->ATK;
	tempchar->GetStatus()->DEF += tempchar->GetWeapon()->GetStatus()->DEF + tempchar->GetArmor()->GetStatus()->DEF;

	return tempchar;
}