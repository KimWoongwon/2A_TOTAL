#pragma once
#include "Item.h"
// 무기 클래스
class Weapon : public Item
{
private:
public:
	Weapon(const char*,STATUS*, int, CLASS);	// 생성자
	Weapon(Weapon& weapon);						// 복사 생성자
	~Weapon();
};

