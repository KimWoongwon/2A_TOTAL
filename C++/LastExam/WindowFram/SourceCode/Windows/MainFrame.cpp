#include "MainFrame.h"

CMainFrame* CMainFrame::mPthis = NULL;

CMainFrame* CMainFrame::Create(HINSTANCE _hinstance)
{
	if (!mPthis)
	{
		mPthis = new CMainFrame();
	}

	CWindowFrame::Create(_hinstance);
	
	CLoginSystem::Create();

	CMouse::Create();

	

	return mPthis;
}

CMainFrame* CMainFrame::GetInstance()
{
	return mPthis;
}

void CMainFrame::Destroy()
{
	CLoginSystem::Destroy();
	CWindowFrame::Destroy();
	CMouse::Destroy();
	

	if (mPthis)
	{
		delete mPthis;
		mPthis = NULL;
	}

	
}

void CMainFrame::Run()
{
	MSG Message;

	while (GetMessage(&Message, NULL, 0, 0))
	{
		CWindowFrame::GetInstance()->Run(Message);
	}
}

void CMainFrame::Initialize()
{
	CWindowFrame::GetInstance()->Initialize();
	CMouse::GetInstance()->Initialize(CWindowFrame::GetInstance()->GethWnd());
	CLoginSystem::GetInstance()->InitializeProcess();
}