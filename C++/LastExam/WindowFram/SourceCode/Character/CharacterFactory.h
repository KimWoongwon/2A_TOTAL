#pragma once
#include "../Global.h"
#include "Character.h"
// ��ӵ� �θ� ���丮 Ŭ����
class CharacterFactory
{
protected:
	virtual Character* CreateCharacter(const char*, CLASS) = 0;
public:
	CharacterFactory();
	virtual ~CharacterFactory();
	// �ܺο��� ������ ĳ���͸� �����Ұ�� ȣ��� �Լ�
	Character* SettingCharacter(const char*,CLASS);	

};

