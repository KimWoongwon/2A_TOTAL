#include <windows.h>
#include "resource.h"
int Age = 28;

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

BOOL CALLBACK MainDlgProc(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HWND hDlg1 = NULL;
	switch (iMessage) {
	case WM_INITDIALOG:
		hDlgMain = hDlg;
		SetDlgItemInt(hDlg, IDC_EDIT1, Age, FALSE);
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hDlg, Dlg1);
			ShowWindow(hDlg1, SW_SHOW);
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
	switch (iMessage)
	{
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK2:
		case IDCANCEL2:
		case IDCANCEL:
			EndDialog(hDlg1, 0);
			break;
		}
		break;
	}
	return 0;
}
