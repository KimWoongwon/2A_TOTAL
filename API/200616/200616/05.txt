#include <windows.h>
#include "resource.h"

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

void DrawBitmap(HDC hdc, int x, int y, HBITMAP hbit)
{
	HDC MemoryDC;
	int BitmapX, BitmapY;
	BITMAP Bitmap_;
	HBITMAP OldBitmap;
	MemoryDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemoryDC, hbit);
	
	GetObject(hbit, sizeof(BITMAP), &Bitmap_);
	BitmapX = Bitmap_.bmWidth;
	BitmapY = Bitmap_.bmHeight;

	TransparentBlt(hdc, x, y, BitmapX, BitmapY, MemoryDC, 0, 0, BitmapX, BitmapY, RGB(255, 255, 255));
	//BitBlt(hdc, x, y, BitmapX, BitmapY, MemoryDC, 0, 0, SRCCOPY);
	SelectObject(MemoryDC, OldBitmap);
	DeleteDC(MemoryDC);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	float speed = 100;
	PAINTSTRUCT pt;
	HBITMAP backBitmap, OldBackBitmap;
	static BOOL isClicked;
	static HDC hdc, BACKDC;
	static float CatPosX, CatPosY, MousePosX, MousePosY, CatSpeedX, CatSpeedY;
	static RECT rect;
	static HBITMAP Bitmap1 = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3)), // Áã
				   Bitmap2 = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4)); // °í¾çÀÌ

	switch (iMessage) {
	case WM_CREATE:
		isClicked = false;
		CatPosX = 100;
		CatPosY = 100;
		GetClientRect(hWnd, &rect);
		SetTimer(hWnd, 1, 10, NULL);
		break;
	case WM_LBUTTONDOWN:
		isClicked = true;
		MousePosX = LOWORD(lParam);
		MousePosY = HIWORD(lParam);
		CatSpeedX = (MousePosX - CatPosX) / speed;
		CatSpeedY = (MousePosY - CatPosY) / speed;
		SetTimer(hWnd, 1, 10, NULL);
		break;
	case WM_MOUSEMOVE:
		if (isClicked)
		{
			MousePosX = LOWORD(lParam);
			MousePosY = HIWORD(lParam);
			CatSpeedX = (MousePosX - CatPosX) / speed;
			CatSpeedY = (MousePosY - CatPosY) / speed;
		}
		break;
	case WM_LBUTTONUP:
		isClicked = false;
		KillTimer(hWnd, 1);
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &pt);

		BACKDC = CreateCompatibleDC(hdc);
		backBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		OldBackBitmap = (HBITMAP)SelectObject(BACKDC, backBitmap);
		PatBlt(BACKDC, 0, 0, rect.right, rect.bottom, WHITENESS);

		if(isClicked)
			DrawBitmap(BACKDC, MousePosX, MousePosY, Bitmap1);
		DrawBitmap(BACKDC, CatPosX, CatPosY, Bitmap2);

		BitBlt(hdc, 0, 0, rect.right, rect.bottom, BACKDC, 0, 0, SRCCOPY);
		if (CatPosX + 20 > MousePosX && CatPosX + 20 < MousePosX + 50 && CatPosY + 20 > MousePosY && CatPosY + 20 < MousePosY + 50)
		{
			KillTimer(hWnd, 1);
			MessageBox(hWnd, TEXT("End!"), TEXT("°í¾çÀÌ°¡ Áã¸¦ Àâ¾Ò½À´Ï´Ù."), NULL);
			isClicked = false;
		}
		SelectObject(BACKDC, OldBackBitmap);
		DeleteDC(BACKDC);
		DeleteObject(backBitmap);
		EndPaint(hWnd, &pt);
		return 0;
	case WM_TIMER:
		CatPosX += CatSpeedX;
		CatPosY += CatSpeedY;
		
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
