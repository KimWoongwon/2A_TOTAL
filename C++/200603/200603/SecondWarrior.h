#pragma once
#include "Base.h"
#include "BaseTwo.h"
class SecondWarrior : public Base, public BaseTwo
{
	void Attck();
	virtual void Move();
	virtual void Jump();
};

