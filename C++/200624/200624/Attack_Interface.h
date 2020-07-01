#pragma once
#include "Global.h"
class AttackBehavior
{
public:
	virtual void Attack() = 0;
};

class WarHammer :public AttackBehavior
{
public:
	void Attack()
	{
		cout << "WarHammer Attack" << endl;
	}
};

class TwinDagger : public AttackBehavior
{
public:
	void Attack()
	{
		cout << "TwinDagger Attack" << endl;
	}
};

class TwoHandSword : public AttackBehavior
{
public:
	void Attack()
	{
		cout << "TwoHandSword Attack" << endl;
	}
};