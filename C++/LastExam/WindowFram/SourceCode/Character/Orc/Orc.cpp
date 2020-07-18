#include "Orc.h"
Orc::Orc(const char* p_name, CLASS pjob, ItemFactory* pblacksmith)
	: Character(p_name, pjob, pblacksmith)
{
	region = REGION::ORC;	// ������ ĳ������ ������ ���⼭ ����
}

Orc::~Orc()
{

}
// �������� �ʱ� ���ݰ��� �ٸ��� ����
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
