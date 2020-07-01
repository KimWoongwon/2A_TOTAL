#include "Elf.h"
Elf::Elf(const char* p_name, const char* p_petname, JOB pjob, ItemFactory* pblacksmith)
	: Character(p_name, p_petname, pjob, pblacksmith)
{
	kind = ELF;
}
Elf::~Elf()
{

}

void Elf::SetHp()
{
	status->Hp += 500;
}
void Elf::SetMp()
{
	status->Mp += 600;
}
void Elf::SetATK()
{
	status->ATK += 150;
}
void Elf::SetDEF()
{
	status->DEF += 50;
}
