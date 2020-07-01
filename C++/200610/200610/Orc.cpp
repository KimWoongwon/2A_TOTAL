#include "Orc.h"
Orc::Orc(const char* p_name, const char* p_petname, JOB pjob, ItemFactory* pblacksmith)
	: Character(p_name, p_petname, pjob, pblacksmith)
{
	kind = ORC;
}
Orc::~Orc()
{

}

void Orc::SetHp()
{
	status->Hp += 1000;
}
void Orc::SetMp()
{
	status->Mp += 100;
}
void Orc::SetATK()
{
	status->ATK += 50;
}
void Orc::SetDEF()
{
	status->DEF += 150;
}
