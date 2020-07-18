#pragma once
#include "../Global.h"
#include "../State/LoginSystem.h"

#include "WindowFrame.h"

// winmain에서 호출되는 함수 실제 구동을 담당한다.
class CMainFrame
{
	static CMainFrame* mPthis;
	
	CMainFrame() {}
	~CMainFrame() {}
public:
	static CMainFrame* Create(HINSTANCE _hinstance);
	static CMainFrame* GetInstance();
	static void Destroy();	

	void Run();
	void Initialize();	
};
