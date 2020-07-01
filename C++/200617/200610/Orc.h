#pragma once
#include "Character.h"
class Orc : public Character
{
private:
public:
	Orc(const char*, const char*, JOB, ItemFactory*);;
	~Orc();

	virtual void SetHp();
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

