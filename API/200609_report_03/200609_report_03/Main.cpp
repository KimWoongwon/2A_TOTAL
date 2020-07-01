#include <windows.h>
#include "resource.h"

BOOL CALLBACK MainDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam);
HWND hDlgMain;
HINSTANCE hInst;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	hInst = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), HWND_DESKTOP /* ¶Ç´Â 0 */, MainDlgProc);
	return 0;
}
BOOL CALLBACK MainDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HWND hDlg1 = NULL;
	HDC DlgDC, DlgMemDC;
	PAINTSTRUCT ps;
	HBITMAP MyBitmap, OldBitmap;
	static int bx, by;
	BITMAP bit;
	static RECT rect;
	static POINT pos;
	static int flagX,flagY;
	

	switch (iMessage) {
	case WM_INITDIALOG:
		hDlgMain = hDlg;
		GetClientRect(hDlg, &rect);
		flagX = 1;
		flagY = 1;
		pos.x = 0;
		pos.y = 0;
		SetTimer(hDlg, 1, 50, NULL);
		break;
	case WM_PAINT:
		DlgDC = BeginPaint(hDlg, &ps);
		DlgMemDC = CreateCompatibleDC(DlgDC);
		MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		OldBitmap = (HBITMAP)SelectObject(DlgMemDC, MyBitmap);

		GetObject(MyBitmap, sizeof(BITMAP), &bit);
		bx = bit.bmWidth;
		by = bit.bmHeight;
		TransparentBlt(DlgDC, pos.x, pos.y, bx*2, by*2, DlgMemDC, 0, 0, bx, by, RGB(255, 255, 255));

		SelectObject(DlgMemDC, OldBitmap);
		DeleteObject(MyBitmap);
		DeleteDC(DlgMemDC);
		EndPaint(hDlg, &ps);
		break;
	case WM_TIMER:
		pos.x += flagX * 10;
		pos.y += flagY * 10;
		if (pos.x + bx*2 > rect.right)
			flagX = -1;
		else if(pos.x <= rect.left)
			flagX = 1;
		if (pos.y + by*2 > rect.bottom)
			flagY = -1;
		else if (pos.y < rect.top)
			flagY = 1;

		InvalidateRect(hDlg, NULL, TRUE);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

