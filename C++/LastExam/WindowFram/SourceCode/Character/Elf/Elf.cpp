#include "Elf.h"
Elf::Elf(const char* p_name, CLASS pjob, ItemFactory* pblacksmith)
	: Character(p_name, pjob, pblacksmith)
{
	region = REGION::ELF;	// ������ ĳ������ ������ ���⼭ ����
}
Elf::~Elf()
{

}
// �������� �ʱ� ���ݰ��� �ٸ��� ����
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
