#pragma once
#include "GameState.h"
#include "WindowFrame.h"


class CStoreState :public CGameState
{	

public:
	CStoreState(CLoginSystem* _game);
	~CStoreState();

	virtual void TimerProcess();
	virtual void ClickProcess();
	virtual void InitializeProcess();
	virtual void ButtonProcess(WPARAM);
};

