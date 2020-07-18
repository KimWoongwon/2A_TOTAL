#pragma once
#include "../Character.h"
// 팩토리패턴의 Elf클래스
class Elf : public Character
{
private:
public:
	Elf(const char*, CLASS, ItemFactory*);
	~Elf();

	virtual void SetHp();	// 가상함수 : 캐릭터의 초기스텟을 종족별로 다르게 설정하기 위한 가상함수
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

