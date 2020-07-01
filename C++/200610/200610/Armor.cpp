#include "Armor.h"
#include "Character.h"

Armor::Armor(const char* pName, STATUS* pStatus, int pPrice, int pJobCode ) : Item(pName, pStatus, pPrice, pJobCode, CODE_ARMOR)
{
}
Armor::~Armor()
{

}

void Armor::OnItem(Character* pChar)
{
	if (pChar->GetAStatus())
	{
		cout << "�̹� ���� �������Դϴ�." << endl;
		return;
	}
	STATUS* temp = pChar->GetStatus();
	temp->Hp += status->Hp;
	temp->Mp += status->Mp;
	temp->ATK += status->ATK;
	temp->DEF += status->DEF;

	pChar->SetStatus(temp);
	pChar->SetAStatus(true);
}
Item* Armor::OffItem(Character* pChar)
{
	if (!pChar->GetAStatus())
	{
		cout << "�������� ���� �����ϴ�." << endl;
		return nullptr;
	}

	Item* tempArmor = pChar->GetArmor();
	STATUS* temp = pChar->GetStatus();
	temp->Hp	-= status->Hp;
	temp->Mp	-= status->Mp;
	temp->ATK	-= status->ATK;
	temp->DEF	-= status->DEF;
	pChar->SetStatus(temp);
	pChar->SetArmor(nullptr);
	pChar->SetAStatus(false);
	return tempArmor;
}