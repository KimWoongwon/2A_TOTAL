#include <windows.h>
#include <stdio.h>
#include "resource.h"

BOOL CALLBACK MainDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dlg1(HWND hDlg1, UINT iMessage, WPARAM wParam, LPARAM lParam);
HWND hDlgMain;
HINSTANCE hInst;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, MainDlgProc);
	return 0;
}

static char name[20];
static char phone[20];
BOOL CALLBACK MainDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	
	HWND hDlg1 = NULL;
	
	switch (iMessage) {
	case WM_INITDIALOG:
		hDlgMain = hDlg;
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_LOG:
			GetDlgItemText(hDlg, IDC_EDIT1, name, 20);
			GetDlgItemText(hDlg, IDC_EDIT2, phone, 20);
			if (strcmp(name, "") && strcmp(phone, ""))
			{
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hDlg, Dlg1);
				ShowWindow(hDlg1, SW_SHOW);
			}
			SetDlgItemText(hDlg, IDC_EDIT1, "");
			SetDlgItemText(hDlg, IDC_EDIT2, "");
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
	HDC hdc;
	PAINTSTRUCT ps;
	static char temp[50];
	switch (iMessage)
	{
	case WM_INITDIALOG:
		sprintf_s(temp, "%s¥‘≤≤º≠ ∞°¿‘«œºÃΩ¿¥œ¥Ÿ.", name);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hDlg1, &ps);
		
		TextOut(hdc, 10, 10, temp, strlen(temp));

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
