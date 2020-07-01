#pragma once
#include "Character.h"
#include "ItemFactory.h"
class Human : public Character
{
private:
public:
	Human(const char*, const char*, JOB, ItemFactory*);
	~Human();

	virtual void SetHp();
	virtual void SetMp();
	virtual void SetATK();
	virtual void SetDEF();
};

