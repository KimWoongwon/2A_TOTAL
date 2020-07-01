#include <windows.h>
#include <stdio.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Dlg1(HWND, UINT, WPARAM, LPARAM);
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


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	switch (iMessage) 
	{
	case WM_CREATE:
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_40001:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg1);
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

#define ID_R1 100
#define ID_R2 200

BOOL CALLBACK Dlg1(HWND hdlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hList;
	static int Selection;
	static char name[20];
	static char hobby[20];
	static char sex[20];
	static char totalinfo[100];
	switch (iMsg)
	{
	case WM_INITDIALOG:
		hList = GetDlgItem(hdlg, IDC_LIST1);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hdlg, IDC_EDIT1, name, 20);
			GetDlgItemText(hdlg, IDC_EDIT2, hobby, 20);
			if (IsDlgButtonChecked(hdlg, IDC_RADIO1) == BST_CHECKED)
				sprintf_s(sex, "%s", "³²¼º");
			else if(IsDlgButtonChecked(hdlg, IDC_RADIO2) == BST_CHECKED)
				sprintf_s(sex, "%s", "¿©¼º");
			if (strcmp(name, "") && strcmp(hobby, ""))
			{
				sprintf_s(totalinfo, "%s, %s, %s", name, hobby, sex);
				SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)totalinfo);
			}
			break;
		case IDOK2:
			SendMessage(hList, LB_DELETESTRING, Selection, 0);
			break;
		case IDC_LIST1:
			if (HIWORD(wParam) == LBN_SELCHANGE)
			{
				Selection = SendMessage(hList, LB_GETCURSEL, 0, 0);
			}
			
			break;
		case IDCANCEL:
			EndDialog(hdlg, 0);
			break;
		}
	}

	return FALSE;
}
