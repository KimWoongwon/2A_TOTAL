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
	// 처음에 생성될때 인벤토리의 이니셜라이즈로 아이템을 설정해주었기 때문에 이부분에서 강제로 아이템 스텟을 추가해준다.
	tempchar->GetStatus()->Hp += tempchar->GetWeapon()->GetStatus()->Hp + tempchar->GetArmor()->GetStatus()->Hp;
	tempchar->GetStatus()->Mp += tempchar->GetWeapon()->GetStatus()->Mp + tempchar->GetArmor()->GetStatus()->Mp;
	tempchar->GetStatus()->ATK += tempchar->GetWeapon()->GetStatus()->ATK + tempchar->GetArmor()->GetStatus()->ATK;
	tempchar->GetStatus()->DEF += tempchar->GetWeapon()->GetStatus()->DEF + tempchar->GetArmor()->GetStatus()->DEF;

	return tempchar;
}