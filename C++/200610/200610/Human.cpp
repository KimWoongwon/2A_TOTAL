#include "Human.h"
Human::Human(const char* p_name, const char* p_petname,JOB pjob, ItemFactory* pblacksmith)
	: Character(p_name, p_petname,pjob,pblacksmith)
{
	kind = HUM;
}
Human::~Human()
{
	
}

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
