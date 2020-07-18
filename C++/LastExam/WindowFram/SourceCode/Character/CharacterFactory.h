#pragma once
#include "../Global.h"
#include "Character.h"
// 상속될 부모 팩토리 클래스
class CharacterFactory
{
protected:
	virtual Character* CreateCharacter(const char*, CLASS) = 0;
public:
	CharacterFactory();
	virtual ~CharacterFactory();
	// 외부에서 실제로 캐릭터를 생성할경우 호출될 함수
	Character* SettingCharacter(const char*,CLASS);	

};

