#pragma once
#include "Human.h"
#include "../CharacterFactory.h"
// ĳ���� ���丮�� ��ӹ޴� �ڽ� Ŭ����
class HumanFactory : public CharacterFactory
{
private:
	int count;

	virtual Character* CreateCharacter(const char*, CLASS);	
public:
	HumanFactory();
	~HumanFactory();
};

