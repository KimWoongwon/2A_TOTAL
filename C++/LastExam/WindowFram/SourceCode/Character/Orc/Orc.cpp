#include "Orc.h"
Orc::Orc(const char* p_name, CLASS pjob, ItemFactory* pblacksmith)
	: Character(p_name, pjob, pblacksmith)
{
	region = REGION::ORC;	// 생성될 캐릭터의 종족을 여기서 설정
}

Orc::~Orc()
{

}
// 종족별로 초기 스텟값을 다르게 설정
void Orc::SetHp()
{
	status->Hp = 1000;
}
void Orc::SetMp()
{
	status->Mp = 100;
}
void Orc::SetATK()
{
	status->ATK = 50;
}
void Orc::SetDEF()
{
	status->DEF = 150;
}
