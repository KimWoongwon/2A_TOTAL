#include <windows.h>
#include <time.h>
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
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
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

	BitBlt(hdc, x, y, BitmapX, BitmapY, MemoryDC, 0, 0, SRCCOPY);
	SelectObject(MemoryDC, OldBitmap);
	DeleteDC(MemoryDC);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    
    static HDC hdc, BACKDC;
    static PAINTSTRUCT ps;

	static HBITMAP BitMap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	static HBITMAP backBitmap, OldBackBitmap;
	BITMAP bit;
	int bx, by;
	static RECT rect;

	int flag = 0;
    switch (iMessage) {
    case WM_CREATE:
		GetClientRect(hWnd, &rect);
        return 0;
	case WM_SIZE:
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_COMMAND:
		switch (wParam)
		{
		case ID_3BY3:
			flag = 1;
			break;
		case ID_4BY4:
			flag = 2;
			break;
		case ID_5BY5:
			flag = 3;
			break;
		}
		break;
    case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		BACKDC = CreateCompatibleDC(hdc);
		backBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		OldBackBitmap = (HBITMAP)SelectObject(BACKDC, backBitmap);
		PatBlt(BACKDC, 0, 0, rect.right, rect.bottom, WHITENESS);

		DrawBitmap(BACKDC, 0, 0, BitMap);

		GetObject(BitMap, sizeof(BITMAP), &bit);
		bx = bit.bmWidth;
		by = bit.bmHeight;


		StretchBlt(hdc, 0, 0, 900, 900, BACKDC, 0, 0, bx, by, SRCCOPY);

		SelectObject(BACKDC, OldBackBitmap);
		DeleteDC(BACKDC);
		DeleteObject(backBitmap);
		EndPaint(hWnd, &ps);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
