#include "WindowFrame.h"
#include "BackBit.h"
#include "Mouse.h"
#include "DragDrawing.h"
#include "RectMenu.h"
#include "CircleMenu.h"
#include "FreeLineMenu.h"
#include "LineMenu.h"

CWindowFrame* CWindowFrame::mPthis=NULL;

CWindowFrame* CWindowFrame::Create(HINSTANCE _hinstance)
{
	if(!mPthis)
	{
		mPthis=new CWindowFrame(_hinstance);
	}	

	CMouse::Create();
	CDragCircleDrawing::Create();
	CDragFreeLineDrawing::Create();
	CDragLineDrawing::Create();
	CDragRectangleDrawing::Create();

	return mPthis;
}

CWindowFrame* CWindowFrame::GetInstance()
{	
	return mPthis;
}

void CWindowFrame::Destroy()
{
	CMouse::Destroy();
	CDragCircleDrawing::Destroy();
	CDragFreeLineDrawing::Destroy();
	CDragLineDrawing::Destroy();
	CDragRectangleDrawing::Destroy();

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

	static CMenu* menu=NULL;	

	switch (iMessage) 
	{
	case WM_CREATE:	
		mPthis->mhWnd = hWnd;
		return 0;
	case WM_INITMENU:
		if (!flag)
		{
			for (int i = 0; i < 4; i++)
			{
				mPthis->mMenu[i]->SetMenuHandle((HMENU)wParam);
			}
			flag = true;
		}
		return 0;
	case WM_LBUTTONDOWN:
		CMouse::GetInstance()->SetclickDown();	

		if(CMouse::GetInstance()->IsSelectDraw())
		{
			CMouse::GetInstance()->SetDrawStartPoint((int)LOWORD(lParam), (int)HIWORD(lParam));			
		}
		return 0; 
	case WM_LBUTTONUP:	
		if(CMouse::GetInstance()->IsSelectDraw())
		{
			CMouse::GetInstance()->Drawing(mPthis->mBackbit,  NORMAL);
		}
		CMouse::GetInstance()->SetclickUp();
		return 0;
	case WM_COMMAND:
	
		for(int i=0; i<4; i++)
		{
			if(mPthis->mMenu[i]->SelectMenuHandle(wParam)!=NULL)
			{
				menu= mPthis->mMenu[i];
				break;
			}
		}
		menu->ProcessCommandMeg(wParam);		
		return 0;
	case WM_MOUSEMOVE:		
		CMouse::GetInstance()->SetXY(lParam);	
		if(CMouse::GetInstance()->IsSelectDraw())
		{
			CMouse::GetInstance()->Drawing(mPthis->mBackbit, REVERSE);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:		
		hdc=BeginPaint(hWnd, &ps);		
		if (mPthis->mBackbit != nullptr)
		{
			mPthis->mBackbit->SCreanDraw(hdc, 0, 0);
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


	mPthis->mMenu[0] = new CRectMenu();
	mPthis->mMenu[1] = new CCircleMenu();
	mPthis->mMenu[2] = new CLineMenu();
	mPthis->mMenu[3] = new CFreeLineMenu();


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
	WndClass.lpszMenuName=MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mhWnd=CreateWindow(TEXT("exam"),TEXT("exam"),WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mhInstance,NULL);

	ShowWindow(mhWnd, SW_SHOW);
}