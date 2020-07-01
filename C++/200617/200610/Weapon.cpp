#include "Weapon.h"


Weapon::Weapon(const char* pName, STATUS* pStatus, int pPrice, int pJobCode) : Item(pName, pStatus, pPrice, pJobCode, CODE_WEAPON)
{

}
Weapon::~Weapon()
{

}

void Weapon::OnItem(Character*)
{

}
void Weapon::OffItem(Character*)
{

}