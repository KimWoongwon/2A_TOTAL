#include "Human.h"
Human::Human(const char* p_name,CLASS pjob, ItemFactory* pblacksmith)
	: Character(p_name,pjob,pblacksmith)
{
	region = REGION::HUM;	// 생성될 캐릭터의 종족을 여기서 설정
}
Human::~Human()
{
	
}
// 종족별로 초기 스텟값을 다르게 설정
void Human::SetHp()
{
	status->Hp = 700;
}
void Human::SetMp()
{
	status->Mp = 400;
}
void Human::SetATK()
{
	status->ATK = 100;
}
void Human::SetDEF()
{
	status->DEF = 100;
}
