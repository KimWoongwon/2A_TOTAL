#pragma once
#include "Global.h"
#include "WindowFrame.h"
#include "Mouse.h"
#include "LoginSystem.h"

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
