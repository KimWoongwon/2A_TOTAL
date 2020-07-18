#pragma once
#include "../Character.h"
// 오크 클래스
class Orc : public Character
{
private:
public:
	Orc(const char*, CLASS, ItemFactory*);
	~Orc();

	virtual void SetHp();	// 가상함수 : 캐릭터의 초기스텟을 종족별로 다르게 설정하기 위한 가상함수
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

