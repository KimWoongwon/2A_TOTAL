#include "GameState.h"


CGameState::CGameState(CLoginSystem* _system)
{
	mSystem = _system;
}

CLoginSystem* CGameState::GetSystem()
{
	return mSystem;
}

CGameState::~CGameState()
{
}
