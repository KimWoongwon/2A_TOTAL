#include "WindowFrame.h"
#include "LoginSystem.h" 
#include "BackBit.h"
#include "Mouse.h"


CWindowFrame* CWindowFrame::mPthis=NULL;

CWindowFrame* CWindowFrame::Create(HINSTANCE _hinstance)
{
	if(!mPthis)
	{
		mPthis=new CWindowFrame();
	}

	mPthis->mhInstance=_hinstance;	

	return mPthis;
}

CWindowFrame* CWindowFrame::GetInstance()
{	
	return mPthis;
}

void CWindowFrame::Destroy()
{
	if(mPthis)
	{
		delete mPthis;
		mPthis=NULL;
	}
}

LRESULT CALLBACK CWindowFrame::WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;		

	CLoginSystem* game = CLoginSystem::GetInstance();
	
	switch (iMessage)
	{
	case WM_CREATE:
		MoveWindow(hWnd, 200, 200, 500, 500, TRUE);
		return 0;		
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = 500;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = 500;
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = 500;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = 500;
		return 0;
	case WM_TIMER:
		game->TimerProcess();
		return 0;
	case WM_LBUTTONDOWN:
		CMouse::GetInstance()->SetclickDown(lParam);	
		game->ClickProcess();
		return 0; 
	case WM_LBUTTONUP:			
		CMouse::GetInstance()->SetclickUp();
		return 0;
	case WM_COMMAND:
		game->ButtonProcess(wParam);
		return 0;
	case WM_MOUSEMOVE:		
		CMouse::GetInstance()->SetXY(lParam);			
		return 0;
	case WM_DESTROY:		
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:		
		hdc=BeginPaint(hWnd, &ps);		
		if (mPthis->mBackBit != nullptr)
		{
			mPthis->mBackBit->SCreanDraw(hdc, 0, 0);
		}		
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void CWindowFrame::Run(MSG _Message)
{
	TranslateMessage(&_Message);
	DispatchMessage(&_Message);
}

void CWindowFrame::Initialize()
{
	
	mPthis->BuildWindow();

	mButton[0] = new CPushButton(400, 20, 80, 25, ID_BUTTON1);
	mButton[1] = new CPushButton(400, 50, 80, 25, ID_BUTTON2);
	mButton[2] = new CPushButton(400, 90, 80, 25, ID_BUTTON3);
	mButton[3] = new CPushButton(400,130, 80, 25, ID_BUTTON4);
	mButton[4] = new CPushButton(400,170, 80, 25, ID_BUTTON5);

	Text01 = new CStaticText(190, 20, 50, 25, ID_STATIC1, TEXT("ID : "));
	IdEdit = new CEditControl(240, 20, 150, 25, ID_EDIT1);
	Text02 = new CStaticText(190, 50, 50, 25, ID_STATIC2, TEXT("PW : "));
	PwEdit = new CEditControl(240, 50, 150, 25, ID_EDIT2);

	CharacterList = new CListBox(10, 10, 380, 360, ID_LIST1);

	RECT crt;
	GetClientRect(CWindowFrame::GetInstance()->GethWnd(), &crt);
	mBackBit = new CBackBit(CWindowFrame::GetInstance()->GethWnd(), crt.right, crt.bottom);
}

void CWindowFrame::BuildWindow()
{	
	WNDCLASS WndClass;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=CWindowFrame::GetInstance()->mhInstance;
	WndClass.lpfnWndProc=CWindowFrame::GetInstance()->WndProc;
	WndClass.lpszClassName=TEXT("exam");
	WndClass.lpszMenuName=nullptr;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mhWnd=CreateWindow(TEXT("exam"),TEXT("exam"),WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mhInstance,NULL);

	ShowWindow(mhWnd, SW_SHOW);
}

HWND CWindowFrame::GethWnd()
{
	return mhWnd;
}
HINSTANCE CWindowFrame::GetInstanceHandle()
{
	return mhInstance;
}

void CWindowFrame::ResetText()
{
	Text01->ResetControl();
	Text02->ResetControl();
	IdEdit->ResetControl();
	PwEdit->ResetControl();
}

CBackBit* CWindowFrame::GetBackbit()
{
	return mBackBit;
}

CPushButton* CWindowFrame::GetButton(int ID)
{
	switch (ID)
	{
	case ID_BUTTON1:
		return mButton[0];
	case ID_BUTTON2:
		return mButton[1];
	case ID_BUTTON3:
		return mButton[2];
	case ID_BUTTON4:
		return mButton[3];
	case ID_BUTTON5:
		return mButton[4];
	}
	
}

CEditControl* CWindowFrame::GetEditControl(int ID)
{
	switch (ID)
	{
	case ID_EDIT1:
		return IdEdit;
	case ID_EDIT2:
		return PwEdit;
	}
}
CStaticText* CWindowFrame::GetStaticText(int ID)
{
	switch (ID)
	{
	case ID_STATIC1:
		return Text01;
	case ID_STATIC2:
		return Text02;
	}
}

CListBox* CWindowFrame::GetListBox(int ID)
{
	return CharacterList;
}
