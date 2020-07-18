#pragma once
#include "Human.h"
#include "../CharacterFactory.h"
// 캐릭터 팩토리를 상속받는 자식 클래스
class HumanFactory : public CharacterFactory
{
private:
	int count;

	virtual Character* CreateCharacter(const char*, CLASS);	
public:
	HumanFactory();
	~HumanFactory();
};

