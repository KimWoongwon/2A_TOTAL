#pragma once
#include "../Character.h"

// 인간 클래스
class Human : public Character
{
private:
public:
	Human(const char*, CLASS, ItemFactory*);
	~Human();

	virtual void SetHp();	// 가상함수 : 캐릭터의 초기스텟을 종족별로 다르게 설정하기 위한 가상함수
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

