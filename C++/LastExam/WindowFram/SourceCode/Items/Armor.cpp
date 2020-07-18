#include "Armor.h"

Armor::Armor(const char* pName, STATUS* pStatus, int pPrice, CLASS pClassCode ) : Item(pName, pStatus, pPrice, pClassCode, ITEMTYPE::ARMOR)
{
}
Armor::~Armor()
{

}
