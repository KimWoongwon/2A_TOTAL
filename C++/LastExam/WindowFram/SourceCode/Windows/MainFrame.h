#pragma once
#include "../Global.h"
#include "../State/LoginSystem.h"

#include "WindowFrame.h"
#include "Mouse.h"


class CMainFrame
{
	static CMainFrame* mPthis;
	

	CMainFrame()
	{		
	}

	~CMainFrame()
	{	
	}

public:
	static CMainFrame* Create(HINSTANCE _hinstance);
	static CMainFrame* GetInstance();
	static void Destroy();	

	void Run();
	void Initialize();	
};
