#include "Character.h"

bool Character::Delete_Attack()
{
	if (attack_behavior == NULL)
		return false;

	delete attack_behavior;
	return true;
}
bool Character::Delete_Defence()
{
	if (defence_behavior == NULL)
		return false;

	delete defence_behavior;
	return true;
}
Character::Character()
{
	attack_behavior = NULL;
	defence_behavior = NULL;
}
Character::~Character()
{
	Delete_Attack();
	Delete_Defence();
}

void Character::Attack()
{
	attack_behavior->Attack();
}
void Character::Defence()
{
	defence_behavior->Defence();
}

bool Character::SetAttackBehavior(AttackBehavior* p_behavior)
{
	Delete_Attack();
	attack_behavior = p_behavior;
	return true;
}
bool Character::SetDefenceBehavior(DefenceBehavior* p_behavior)
{
	Delete_Defence();
	defence_behavior = p_behavior;
	return true;
}