#include "WindowFrame.h"
#include "BackBit.h"
#include "Mouse.h"
#include "DragDrawing.h"

CWindowFrame* CWindowFrame::mPthis=NULL;

CWindowFrame::CWindowFrame()
{	
	mBackbit = nullptr;
	mHinstance = nullptr;
	mMenu = nullptr;
	mHWnd = nullptr;
}

CWindowFrame::~CWindowFrame()
{
	if (mMenu != NULL)
	{
		delete mMenu;
	}
	if (mBackbit != NULL)
	{
		delete mBackbit;
	}
}

CWindowFrame* CWindowFrame::Create(HINSTANCE _hinstance)
{
	if(!mPthis)
	{
		mPthis=new CWindowFrame();
	}

	CWindowFrame::GetInstance()->mHinstance=_hinstance;

	CMouse::Create();
	CDragFreeLineDrawing::Create();
	CDragCircleDrawing::Create();
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
	CDragFreeLineDrawing::Destroy();
	CDragCircleDrawing::Destroy();
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
	

	switch (iMessage) {
	case WM_CREATE:
		//CMouse::GetInstance()->Initialize(hWnd);
		GetClientRect(hWnd, &crt);
	    mPthis->mBackbit=new CBackBit(hWnd, crt.right , crt.bottom );
		mPthis->mMenu=new CMenu();
		mPthis->mMenu->MenuInitialize(IDR_MENU1,hWnd);		
		return 0;
	case WM_LBUTTONDOWN:
		CMouse::GetInstance()->SetclickDown();	
		CMouse::GetInstance()->SetXY(lParam);
		if (CMouse::GetInstance()->IsSelectDraw())
		{
			CMouse::GetInstance()->SetDrawStartPoint((int)LOWORD(lParam), (int)HIWORD(lParam));
		}		
		return 0;
	case WM_LBUTTONUP:	
		if (CMouse::GetInstance()->IsSelectDraw())
		{
			CMouse::GetInstance()->Drawing(mPthis->mBackbit, NORMAL);
		}		
		CMouse::GetInstance()->SetclickUp();
		return 0;
	case WM_COMMAND:
		mPthis->mMenu->ProcessCommandMeg(wParam);	

		return 0;
	case WM_MOUSEMOVE:		
		CMouse::GetInstance()->SetXY(lParam);	
		if (CMouse::GetInstance()->IsSelectDraw())
		{		
			CMouse::GetInstance()->Drawing(mPthis->mBackbit, REVERSE);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);		
		
		return 0;
	case WM_PAINT:		
		hdc=BeginPaint(hWnd, &ps);			
		mPthis->mBackbit->SCreanDraw(hdc, 0,0);
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void CWindowFrame::Run(MSG _msg)
{	
	TranslateMessage(&_msg);
	DispatchMessage(&_msg);	
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
	WndClass.hInstance = mHinstance;
	WndClass.lpfnWndProc=WndProc;
	WndClass.lpszClassName=TEXT("exam");
	WndClass.lpszMenuName=MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mHWnd = CreateWindow(TEXT("exam"), TEXT("exam"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mHinstance,NULL);

	ShowWindow(mHWnd, SW_SHOW);
}
