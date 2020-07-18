#include "Elf.h"
Elf::Elf(const char* p_name, CLASS pjob, ItemFactory* pblacksmith)
	: Character(p_name, pjob, pblacksmith)
{
	region = REGION::ELF;	// 생성될 캐릭터의 종족을 여기서 설정
}
Elf::~Elf()
{

}
// 종족별로 초기 스텟값을 다르게 설정
void Elf::SetHp()
{
	status->Hp = 500;
}
void Elf::SetMp()
{
	status->Mp = 600;
}
void Elf::SetATK()
{
	status->ATK = 150;
}
void Elf::SetDEF()
{
	status->DEF = 50;
}
