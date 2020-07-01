#include "Weapon.h"
#include "Character.h"

Weapon::Weapon(const char* pName, STATUS* pStatus, int pPrice, int pJobCode) : Item(pName, pStatus, pPrice, pJobCode, CODE_WEAPON)
{

}
Weapon::~Weapon()
{

}

void Weapon::OnItem(Character* pChar)
{
	if (pChar->GetWStatus())
	{
		cout << "�̹� ���⸦ �������Դϴ�." << endl;
		return;
	}
	STATUS* temp = pChar->GetStatus();
	temp->Hp += status->Hp;
	temp->Mp += status->Mp;
	temp->ATK += status->ATK;
	temp->DEF += status->DEF;

	pChar->SetStatus(temp);
	pChar->SetWStatus(true);
}
Item* Weapon::OffItem(Character* pChar)
{
	if (!pChar->GetWStatus())
	{
		cout << "�������� ���Ⱑ �����ϴ�." << endl;
		return nullptr;
	}

	Item* tempWeapon = pChar->GetWeapon();
	STATUS* temp = pChar->GetStatus();
	temp->Hp -= status->Hp;
	temp->Mp -= status->Mp;
	temp->ATK -= status->ATK;
	temp->DEF -= status->DEF;

	pChar->SetStatus(temp);
	pChar->SetWeapon(nullptr);
	pChar->SetWStatus(false);
	return tempWeapon;
}