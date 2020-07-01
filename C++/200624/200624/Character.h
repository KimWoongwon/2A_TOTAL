#pragma once
#include "Attack_Interface.h"
#include "Defence_Interface.h"
class Character
{
private:
	AttackBehavior* attack_behavior;
	DefenceBehavior* defence_behavior;

	bool Delete_Attack();
	bool Delete_Defence();
public:
	Character();
	~Character();

	void Attack();
	void Defence();

	bool SetAttackBehavior(AttackBehavior*);
	bool SetDefenceBehavior(DefenceBehavior*);
};

