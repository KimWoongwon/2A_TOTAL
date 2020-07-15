#pragma once
#include "../Global.h"
#include "../Windows/BackBit.h"

class CLoginSystem;

class CGameState
{
private:
	CLoginSystem*    mSystem;
public:
	CGameState(CLoginSystem* );
	~CGameState();

	CLoginSystem* GetSystem();
	virtual void TimerProcess() = 0;
	virtual void ClickProcess() = 0;
	virtual void InitializeProcess() = 0;
	virtual void ButtonProcess(WPARAM) = 0;

};

