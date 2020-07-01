#include <windows.h>
#include "resource.h"

BOOL CALLBACK MainDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg1(HWND hDlg1, UINT iMessage, WPARAM wParam, LPARAM lParam);
HWND hDlgMain;
HINSTANCE hInst;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	hInst = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), HWND_DESKTOP /* ¶Ç´Â 0 */, MainDlgProc);
	return 0;
}
static int flag = 0;
BOOL CALLBACK MainDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HWND hDlg1 = NULL;
	
	switch (iMessage) {
	case WM_INITDIALOG:
		hDlgMain = hDlg;
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) 
		{
		case IDC_RADIO1:
			flag = 1;
			break;
		case IDC_RADIO2:
			flag = 2;
			break;
		case IDOK:
			/*if (IsDlgButtonChecked(hDlg, IDC_RADIO1) == BST_CHECKED)
				flag = 1;
			if (IsDlgButtonChecked(hDlg, IDC_RADIO2) == BST_CHECKED)
				flag = 2;*/
			if (flag != 0)
			{
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hDlg, Dlg1);
				ShowWindow(hDlg1, SW_SHOW);
			}
			break;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}


BOOL CALLBACK Dlg1(HWND hDlg1, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC DlgDC, DlgMemDC;
	PAINTSTRUCT ps;
	static HBITMAP MyBitmap, OldBitmap;
	int bx, by;
	BITMAP bit;
	static RECT rect;

	switch (iMessage)
	{
	case WM_INITDIALOG:
		GetClientRect(hDlg1, &rect);
		break;
	case WM_PAINT:
		DlgDC = BeginPaint(hDlg1, &ps);
		DlgMemDC = CreateCompatibleDC(DlgDC);
		switch (flag)
		{
		case 1:
			MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
			break;
		case 2:
			MyBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
			break;
		}
		OldBitmap = (HBITMAP)SelectObject(DlgMemDC, MyBitmap);

		GetObject(MyBitmap, sizeof(BITMAP), &bit);
		bx = bit.bmWidth;
		by = bit.bmHeight;

		TransparentBlt(DlgDC, 0, 0, rect.right, rect.bottom - 40, DlgMemDC, 0, 0, bx, by, RGB(255, 0, 0));

		SelectObject(DlgMemDC, OldBitmap);
		DeleteObject(MyBitmap);
		DeleteDC(DlgMemDC);
		EndPaint(hDlg1, &ps);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg1, 0);
			break;
		}
		break;
	}
	return 0;
}
