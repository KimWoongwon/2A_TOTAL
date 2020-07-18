#include "Weapon.h"


Weapon::Weapon(const char* pName, STATUS* pStatus, int pPrice, CLASS pClassCode) : Item(pName, pStatus, pPrice, pClassCode, ITEMTYPE::WEAPONE)
{

}
Weapon::Weapon(Weapon& weapon) : Item(weapon)
{
}

Weapon::~Weapon()
{

}

