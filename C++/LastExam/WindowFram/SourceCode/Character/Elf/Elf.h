#pragma once
#include "../Character.h"
// ���丮������ ElfŬ����
class Elf : public Character
{
private:
public:
	Elf(const char*, CLASS, ItemFactory*);
	~Elf();

	virtual void SetHp();	// �����Լ� : ĳ������ �ʱ⽺���� �������� �ٸ��� �����ϱ� ���� �����Լ�
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

