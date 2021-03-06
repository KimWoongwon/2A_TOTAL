#include <windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include "resource.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPCTSTR lpszClass = TEXT("김웅원_16032020");

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
	idx = ListView_GetItemCount(hList); // 행번호를 가져오는 함수

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
		// item의 속성중 TEXT 부분만 내가 설정 해주겠다. 라고 미리 선언
		item.iItem = i; // 행 넘버
		item.iSubItem = 0; // 열 번호
		item.pszText = name[i];
		ListView_InsertItem(hList, &item); // 첫번째 열에 데이터를 넣을때는 InsertItem 함수를 이용해서 데이터가 저장될 행을 만들어 준다.
		ListView_SetItemText(hList, i, 1, phone[i]); 
		ListView_SetItemText(hList, i, 2, address[i]); 
		// 행이 만들어 진상태에서 다른 열에 데이터를 추가하고 싶다면 SetItemText함수를 이용한다.
	}*/
}

void MakeColumn(HWND hDlg) // 컬럼 생성 함수
{
	char* name[3] = { (char*)"이름", (char*)"전화번호", (char*)"출생연도" };
	int size[3] = { 60, 90, 90 };
	LVCOLUMN lvCol = { 0, }; // LV = ListView의 약자
	HWND hList;
	int i;
	hList = GetDlgItem(hDlg, IDC_LIST1);
	// LVCF = List View Column Format
	lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; // 컬럼의 항목을 내가 지정해주겠다고 미리 정해주는 부분
	lvCol.fmt = LVCFMT_LEFT; // 각 컬럼의 포멧 (왼쪽 정렬)

	for (i = 0; i < 3; i++)
	{
		lvCol.cx = size[i]; // 각 컬럼의 좌우 크기 (픽셀단위)
		lvCol.pszText = name[i]; // 각 컬럼의 이름 (텍스트)
		lvCol.iSubItem = i; // 각 칼럼의 인덱스값 (열 번호)
		// 셋팅한 lvCol 을 LVM_INSERTCOLUMN을 이용해 넣어주는 부분
		SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
	}
}

LRESULT CALLBACK Dlg1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
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
		case ID_40001: // 메뉴 클릭시 다이얼로그와 연결되게끔
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

