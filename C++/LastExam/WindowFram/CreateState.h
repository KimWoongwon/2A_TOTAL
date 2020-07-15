#pragma once
#include "GameState.h"
#include "WindowFrame.h"


class CCreateState :public CGameState
{

public:
	CCreateState(CLoginSystem* _game);
	~CCreateState();

	virtual void TimerProcess();
	virtual void ClickProcess();
	virtual void InitializeProcess();
	virtual void ButtonProcess(WPARAM);
};



