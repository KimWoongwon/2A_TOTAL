#pragma once
#include "MoveStateInterface.h"
class Character
{
private:
	MoveState* state;

public:
	Character() { state = Idle::GetInstace(); }
	~Character() {}

	void SetState(MoveState* _state)
	{
		state = _state;
	}

	void Move()
	{
		state->CharacterMove(this);
	}
};

