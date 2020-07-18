#include "Human.h"
Human::Human(const char* p_name,CLASS pjob, ItemFactory* pblacksmith)
	: Character(p_name,pjob,pblacksmith)
{
	region = REGION::HUM;	// ������ ĳ������ ������ ���⼭ ����
}
Human::~Human()
{
	
}
// �������� �ʱ� ���ݰ��� �ٸ��� ����
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
