#pragma once
#include "Item.h"
// ���� Ŭ����
class Weapon : public Item
{
private:
public:
	Weapon(const char*,STATUS*, int, CLASS);	// ������
	Weapon(Weapon& weapon);						// ���� ������
	~Weapon();
};

