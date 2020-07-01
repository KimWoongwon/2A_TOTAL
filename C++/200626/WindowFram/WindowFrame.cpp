#include "WindowFrame.h"
#include "DragDrawing.h"
#include "Menu.h"
#include "resource.h"
CWindowFrame* CWindowFrame::mPthis=NULL;

CWindowFrame* CWindowFrame::Create(HINSTANCE _hinstance)
{
	if(!mPthis)
	{
		mPthis=new CWindowFrame();
	}

	CWindowFrame::GetInstance()->mhInstance=_hinstance;

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

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hBit)
{
	HDC MemDC;
	HBITMAP OldBitmap;
	int bx, by;
	BITMAP bit;

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, hBit);

	GetObject(hBit, sizeof(BITMAP), &bit);
	bx = bit.bmWidth;
	by = bit.bmHeight;

	BitBlt(hdc, x, y, bx, by, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);
}

LRESULT CALLBACK CWindowFrame::WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR str[128]=TEXT("윈도우 클래스화");
	CMouse* mouse = CMouse::GetInstance();
	Menu* menu = Menu::GetInstance();
	DragDrawing* drawing = DragDrawing::GetInstance();
	static LPARAM templparam;
	
	switch (iMessage) 
	{
	case WM_CREATE:
		return 0;
	case WM_LBUTTONDOWN:
		mouse->SetclickDown();
		if(menu->GetSelectID() != ID_FREE)
			drawing->SetOldPos(lParam);
		mouse->SetXY(lParam);
		return 0;
	case WM_LBUTTONUP:
		mouse->SetclickUp();
		InvalidateRect(hWnd, NULL, FALSE);
		return 0;
	case WM_MOUSEMOVE:
		if (mouse->GetClick())
		{
			mouse->SetXY(lParam);
			InvalidateRect(hWnd, NULL, FALSE);
		}
		return 0;
	case WM_COMMAND:
		menu->SetSelectID(wParam);
		drawing->SetID(menu->GetSelectID());
		return 0;
	case WM_PAINT: 
		hdc = BeginPaint(hWnd, &ps);
		drawing->DrawObject(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

int CWindowFrame::Run(MSG _msg)
{
	TranslateMessage(&_msg);
	DispatchMessage(&_msg);

	return _msg.wParam;
}

void CWindowFrame::Initialize()
{
	this->BuildWindow();
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
	WndClass.lpszMenuName=MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mhWnd=CreateWindow(TEXT("exam"),TEXT("exam"),WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mhInstance,NULL);

	ShowWindow(mhWnd, SW_SHOW);
}