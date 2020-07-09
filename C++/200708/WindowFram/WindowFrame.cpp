#include "WindowFrame.h"
#include "BackBit.h"
#include "Mouse.h"

CWindowFrame* CWindowFrame::mPthis=NULL;

CWindowFrame* CWindowFrame::Create(HINSTANCE _hinstance)
{
	if(!mPthis)
	{
		mPthis=new CWindowFrame(_hinstance);
	}	

	CMouse::Create();

	return mPthis;
}

CWindowFrame* CWindowFrame::GetInstance()
{	
	return mPthis;
}

void CWindowFrame::Destroy()
{
	CMouse::Destroy();

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
	RECT crt;
	bool flag = false;
	

	switch (iMessage) 
	{
	case WM_CREATE:	
		mPthis->mhWnd = hWnd;
		GetClientRect(hWnd, &crt);
		BGposX = -crt.right;
		SetTimer(mPthis->mhWnd, 1, 100, NULL);
		return 0;
	case WM_TIMER:
		BGposX += BGmoveSpeed;
		if (BGposX >= 100)
			BGmoveSpeed = 0;
		InvalidateRect(mPthis->mhWnd, NULL, FALSE);
		break;
	case WM_LBUTTONDOWN:
		CMouse::GetInstance()->SetclickDown();	
		CMouse::GetInstance()->SetXY(lParam);
		return 0; 
	case WM_LBUTTONUP:	
		CMouse::GetInstance()->SetclickUp();
		return 0;
	case WM_MOUSEMOVE:		
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:		
		hdc=BeginPaint(hWnd, &ps);		
		if (mPthis->mBackbit != nullptr)
		{
			
		}		
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void CWindowFrame::Run()
{
	MSG Message;

	while (GetMessage(&Message,NULL,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
}

void CWindowFrame::Initialize()
{
	CWindowFrame::GetInstance()->BuildWindow();

	RECT crt;
	GetClientRect(mhWnd, &crt);
	mBackbit = new CBackBit(mhWnd, crt.right, crt.bottom);	

	CMouse::GetInstance()->Initialize(mhWnd);
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
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mhWnd=CreateWindow(TEXT("exam"),TEXT("exam"),WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mhInstance,NULL);

	ShowWindow(mhWnd, SW_SHOW);
}