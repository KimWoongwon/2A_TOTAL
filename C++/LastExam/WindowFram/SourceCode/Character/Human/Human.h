#pragma once
#include "../Character.h"

// �ΰ� Ŭ����
class Human : public Character
{
private:
public:
	Human(const char*, CLASS, ItemFactory*);
	~Human();

	virtual void SetHp();	// �����Լ� : ĳ������ �ʱ⽺���� �������� �ٸ��� �����ϱ� ���� �����Լ�
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

