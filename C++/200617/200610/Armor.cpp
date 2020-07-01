#include "Armor.h"

Armor::Armor(const char* pName, STATUS* pStatus, int pPrice, int pJobCode ) : Item(pName, pStatus, pPrice, pJobCode, CODE_ARMOR)
{
}
Armor::~Armor()
{

}

void Armor::OnItem(Character*)
{

}
void Armor::OffItem(Character*)
{

}