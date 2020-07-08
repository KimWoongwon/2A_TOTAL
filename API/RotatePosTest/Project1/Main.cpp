#include <windows.h>
#include <math.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("±è¿õ¿ø_16032020");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
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

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

#define PI 3.141592654
POINT GetRotatedPos(int x, int y, float angle)
{
	angle = angle * (PI / 180);
	POINT temp;
	
	temp.x = x * cos(angle) + y * sin(angle);
	temp.y = x * sin(angle) - y * cos(angle);

	return temp;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static POINT Speed;
	static POINT pos;
	static HDC hdc;
	static PAINTSTRUCT ps;
	static float angle = 0.0f;

	switch (iMessage) {
	case WM_CREATE:
		Speed.x = 0;
		Speed.y = 50;
		SetTimer(hWnd, 1, 10, NULL);
		break;
	case WM_TIMER:
		angle += 1.0f;
		pos = GetRotatedPos(Speed.x, Speed.y, angle);
		

		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		MoveToEx(hdc, 100, 100, NULL);
		LineTo(hdc, 100 + pos.x, 100 + pos.y);

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
