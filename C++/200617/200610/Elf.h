#pragma once
#include "Character.h"
class Elf : public Character
{
private:
public:
	Elf(const char*, const char*, JOB, ItemFactory*);
	~Elf();

	virtual void SetHp();
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

