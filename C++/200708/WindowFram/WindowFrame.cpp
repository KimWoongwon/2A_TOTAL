#include "WindowFrame.h"
#include "BackBit.h"
#include "Mouse.h"
#include "MINI_GAME.h"

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
double LengthPts(int x1, int y1, int x2, int y2)//두 점의 거리를 구하는 함수
{
	return(sqrt((float)((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))));            //두 점 사이의 거리를 구함
}

BOOL InCircle(int x, int y, int mx, int my, int radius)
{
	if (LengthPts(x, y, mx, my) < radius) return TRUE;           //두 점 사이의 거리가 반지름 이하일 경우 트루 리턴
	else return FALSE;
}
LRESULT CALLBACK CWindowFrame::WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	static HDC hdc;
	PAINTSTRUCT ps;	
	static RECT crt;
	bool flag = false;
	HBITMAP BackGround = LoadBitmap(mPthis->mhInstance, MAKEINTRESOURCE(IDB_BITMAP1));
	static MINI_GAME* game = nullptr;
	//static CBackBit* BackBit

	switch (iMessage) 
	{
	case WM_CREATE:	
		mPthis->mhWnd = hWnd;
		GetClientRect(hWnd, &crt);
		CreateWindow(TEXT("button"), "", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			crt.right - 200, crt.top + 100, 100, 50, hWnd, (HMENU)0, mPthis->mhInstance, NULL);
		SetTimer(mPthis->mhWnd, 1, 100, NULL);
		return 0;
	case WM_TIMER:
		if (game == nullptr)
		{
			game = new MINI_GAME(mPthis->mhWnd, mPthis->mhInstance, BackGround, mPthis->mBackbit);
			
		}
		
		game->OnTimer();
		InvalidateRect(mPthis->mhWnd, NULL, game->GetInval());
		break;
	case WM_LBUTTONDOWN:
		CMouse::GetInstance()->SetclickDown();	
		CMouse::GetInstance()->SetXY(lParam);
		if (InCircle(CMouse::GetInstance()->GetX(), CMouse::GetInstance()->Gety(), GameStart::GetInstance()->CirclePos.x, GameStart::GetInstance()->CirclePos.y, GameStart::GetInstance()->radius))
			game->Score += 1;
		return 0; 
	case WM_LBUTTONUP:	
		CMouse::GetInstance()->SetclickUp();
		return 0;
	case WM_COMMAND:		
		switch (LOWORD(wParam))
		{
		case 0:
			game->PushedButton(hWnd);
			break;
		}
		InvalidateRect(mPthis->mhWnd, NULL, TRUE);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:		
		hdc=BeginPaint(hWnd, &ps);		
		if (mPthis->mBackbit != nullptr)
		{
			
			game->OnPaint(hdc);
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