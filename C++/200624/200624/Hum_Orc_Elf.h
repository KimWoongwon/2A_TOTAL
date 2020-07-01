#pragma once
#include "Global.h"
#include "Character.h"

class Hum : public Character
{
public:
	Hum()
	{
		SetAttackBehavior(new TwoHandSword());
		SetDefenceBehavior(new Dodge());
	}
};

class Orc : public Character
{
public:
	Orc()
	{
		SetAttackBehavior(new WarHammer());
		SetDefenceBehavior(new Block());
	}
};

class Elf : public Character
{
public:
	Elf()
	{
		SetAttackBehavior(new TwinDagger());
		SetDefenceBehavior(new Parrying());
	}
};