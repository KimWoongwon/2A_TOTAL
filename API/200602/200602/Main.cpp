#include <windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("�����_16032020");

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
void InsertData(HWND hDlg, char* p_name, char* p_phone, char* p_born)
{
	LVITEM item;
	HWND hList;
	int idx;

	
	hList = GetDlgItem(hDlg, IDC_LIST1);
	idx = ListView_GetItemCount(hList); // ���ȣ�� �������� �Լ�

	item.mask = LVIF_TEXT; 
	item.iItem = idx;
	item.iSubItem = 0; 
	item.pszText = p_name;
	ListView_InsertItem(hList, &item); 
	ListView_SetItemText(hList, idx, 1, p_phone);
	ListView_SetItemText(hList, idx, 2, p_born);

	/*for (i = 0; i < 3; i++)
	{
		item.mask = LVIF_TEXT; // LVIF = List View Item Format
		// item�� �Ӽ��� TEXT �κи� ���� ���� ���ְڴ�. ��� �̸� ����
		item.iItem = i; // �� �ѹ�
		item.iSubItem = 0; // �� ��ȣ
		item.pszText = name[i];
		ListView_InsertItem(hList, &item); // ù��° ���� �����͸� �������� InsertItem �Լ��� �̿��ؼ� �����Ͱ� ����� ���� ����� �ش�.
		ListView_SetItemText(hList, i, 1, phone[i]); 
		ListView_SetItemText(hList, i, 2, address[i]); 
		// ���� ����� �����¿��� �ٸ� ���� �����͸� �߰��ϰ� �ʹٸ� SetItemText�Լ��� �̿��Ѵ�.
	}*/
}

void MakeColumn(HWND hDlg) // �÷� ���� �Լ�
{
	char* name[3] = { (char*)"�̸�", (char*)"��ȭ��ȣ", (char*)"�������" };
	int size[3] = { 60, 90, 90 };
	LVCOLUMN lvCol = { 0, }; // LV = ListView�� ����
	HWND hList;
	int i;
	hList = GetDlgItem(hDlg, IDC_LIST1);
	// LVCF = List View Column Format
	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; // �÷��� �׸��� ���� �������ְڴٰ� �̸� �����ִ� �κ�
	lvCol.fmt = LVCFMT_LEFT; // �� �÷��� ���� (���� ����)

	for (i = 0; i < 3; i++)
	{
		lvCol.cx = size[i]; // �� �÷��� �¿� ũ�� (�ȼ�����)
		lvCol.pszText = name[i]; // �� �÷��� �̸� (�ؽ�Ʈ)
		lvCol.iSubItem = i; // �� Į���� �ε����� (�� ��ȣ)
		// ������ lvCol �� LVM_INSERTCOLUMN�� �̿��� �־��ִ� �κ�
		SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
	}
}

BOOL CALLBACK Dlg1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HWND hCombo;
	static char name[20];
	static char phone[20];
	static char BornYear[5];
	static char tempyear[5];
	switch (iMessage)
	{
	case WM_INITDIALOG:
		hCombo = GetDlgItem(hDlg, IDC_COMBO1);
		MakeColumn(hDlg);
		for (int i = 1970; i < 2010; i++)
		{
			sprintf_s(tempyear, "%d", i);
			SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)tempyear);
		}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
			GetDlgItemText(hDlg, IDC_EDIT1, name, 20);
			GetDlgItemText(hDlg, IDC_EDIT2, phone, 20);
			GetDlgItemText(hDlg, IDC_COMBO1, BornYear, 5);
			if (strcmp(name, "") && strcmp(phone, ""))
			{
				InsertData(hDlg, name, phone, BornYear);
			}
			SetDlgItemText(hDlg, IDC_EDIT1, "");
			SetDlgItemText(hDlg, IDC_EDIT2, "");
			SetDlgItemText(hDlg, IDC_COMBO1, "");
			hDlg = NULL;
			break;
		case IDCANCEL:
			DestroyWindow(hDlg);
			hDlg = NULL;
			break;
		}
		break;
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HWND hDlg = NULL;

	switch (iMessage) 
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_40001: // �޴� Ŭ���� ���̾�α׿� ����ǰԲ�
			if (!IsWindow(hDlg))
			{
				hDlg = CreateDialog(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Dlg1);
				ShowWindow(hDlg, SW_SHOW);
			}
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
