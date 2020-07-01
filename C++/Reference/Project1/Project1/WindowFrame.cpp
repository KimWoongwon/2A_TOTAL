#include "WindowFrame.h"
#include "Mouse.h"
#include "Global.h"
WindowFrame* WindowFrame::Instance = nullptr;

void WindowFrame::Create()
{
	if (Instance == nullptr)
		Instance = new WindowFrame();
	Mouse::Create();
}
void WindowFrame::Destroy()
{
	Mouse::Destory();
	if (Instance != nullptr)
		delete Instance;
}
WindowFrame* WindowFrame::GetInstance()
{
	if (Instance != nullptr)
		return Instance;
}

void WindowFrame::Initalize(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	
	HWND hWnd;
	//MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	Mouse::GetInstance()->Initalize();
}
int WindowFrame::Run()
{
	MSG Message;
	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}


LRESULT CALLBACK WindowFrame::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_LBUTTONDOWN:
		INSTANCE(Mouse)->SetClicked(true);
		INSTANCE(Mouse)->SetMousePos(lParam, hWnd);
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_LBUTTONUP:
		INSTANCE(Mouse)->PosReset();
		INSTANCE(Mouse)->SetClicked(false);
		break;
	case WM_MOUSEMOVE:
		if (INSTANCE(Mouse)->GetClicked())
		{
			INSTANCE(Mouse)->SetMousePos(lParam, hWnd);
			InvalidateRect(hWnd, NULL, FALSE);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		if (INSTANCE(Mouse)->GetClicked())
		{
			MoveToEx(hdc, INSTANCE(Mouse)->GetPrePos().x, INSTANCE(Mouse)->GetPrePos().y, NULL);
			LineTo(hdc, INSTANCE(Mouse)->GetNowPos().x, INSTANCE(Mouse)->GetNowPos().y);
		}
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

