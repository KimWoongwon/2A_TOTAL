#pragma once
#include "../Character.h"
// ��ũ Ŭ����
class Orc : public Character
{
private:
public:
	Orc(const char*, CLASS, ItemFactory*);
	~Orc();

	virtual void SetHp();	// �����Լ� : ĳ������ �ʱ⽺���� �������� �ٸ��� �����ϱ� ���� �����Լ�
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

