#include <windows.h>
#include <time.h>
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

#define SIZE 40
#define EASYSIZE 7
#define NOMALSIZE 9
#define HARDSIZE 11

void MapSeting(int (*p_map)[EASYSIZE], int p_size)
{
	int count = 0;
	for (int i = 0; i < p_size; i++)
	{
		for (int j = 0; j < p_size; j++)
		{
			if (i == 0 || i == p_size - 1 || j == 0 || j == p_size - 1)
				p_map[i][j] = 4;
			else if (i % 2 == 0 && j % 2 == 0)
				p_map[i][j] = 1;
			else
				p_map[i][j] = 0;
		}
	}
	p_map[1][0] = 0;
	p_map[p_size - 2][p_size - 1] = 0;
	p_map[p_size - 2][p_size - 2] = 0;

	srand(time(NULL));

	int temp = rand() % 4; // 0 1 2 3

	for (int i = 0; i < p_size; i++)
	{
		for (int j = 0; j < p_size; j++)
		{
			temp = rand() % 4;
			if (p_map[i][j] == 1 && i % 2 == 0 && j % 2 == 0)
			{
				if (p_map[i + 1][j] == 4 || p_map[i - 1][j] == 4 || p_map[i][j + 1] == 4 || p_map[i][j - 1] == 4)
					break;
				switch (temp)
				{
				case 0:
					p_map[i - 1][j] = 1;
					break;
				case 1:
					p_map[i][j - 1] = 1;
					break;
				case 2:
					p_map[i + 1][j] = 1;
					break;
				case 3:
					p_map[i][j + 1] = 1;
					break;
				}

			}
		}
	}

}
void MapSeting(int(*p_map)[NOMALSIZE], int p_size)
{
	int count = 0;
	for (int i = 0; i < p_size; i++)
	{
		for (int j = 0; j < p_size; j++)
		{
			if (i == 0 || i == p_size - 1 || j == 0 || j == p_size - 1)
				p_map[i][j] = 4;
			else if (i % 2 == 0 && j % 2 == 0)
				p_map[i][j] = 1;
			else
				p_map[i][j] = 0;
		}
	}
	p_map[1][0] = 0;
	p_map[p_size - 2][p_size - 1] = 0;
	p_map[p_size - 2][p_size - 2] = 0;

	srand(time(NULL));

	int temp = rand() % 4; // 0 1 2 3

	for (int i = 0; i < p_size; i++)
	{
		for (int j = 0; j < p_size; j++)
		{
			temp = rand() % 4;
			if (p_map[i][j] == 1 && i % 2 == 0 && j % 2 == 0)
			{
				if (p_map[i + 1][j] == 4 || p_map[i - 1][j] == 4 || p_map[i][j + 1] == 4 || p_map[i][j - 1] == 4)
					break;
				switch (temp)
				{
				case 0:
					p_map[i - 1][j] = 1;
					break;
				case 1:
					p_map[i][j - 1] = 1;
					break;
				case 2:
					p_map[i + 1][j] = 1;
					break;
				case 3:
					p_map[i][j + 1] = 1;
					break;
				}

			}
		}
	}
}
void MapSeting(int(*p_map)[HARDSIZE], int p_size)
{
	int count = 0;
	for (int i = 0; i < p_size; i++)
	{
		for (int j = 0; j < p_size; j++)
		{
			if (i == 0 || i == p_size - 1 || j == 0 || j == p_size - 1)
				p_map[i][j] = 4;
			else if (i % 2 == 0 && j % 2 == 0)
				p_map[i][j] = 1;
			else
				p_map[i][j] = 0;
		}
	}
	p_map[1][0] = 0;
	p_map[p_size - 2][p_size - 1] = 0;
	p_map[p_size - 2][p_size - 2] = 0;

	srand(time(NULL));

	int temp = rand() % 4; // 0 1 2 3

	for (int i = 0; i < p_size; i++)
	{
		for (int j = 0; j < p_size; j++)
		{
			temp = rand() % 4;
			if (p_map[i][j] == 1 && i % 2 == 0 && j % 2 == 0)
			{
				if (p_map[i + 1][j] == 4 || p_map[i - 1][j] == 4 || p_map[i][j + 1] == 4 || p_map[i][j - 1] == 4)
					break;
				switch (temp)
				{
				case 0:
					p_map[i - 1][j] = 1;
					break;
				case 1:
					p_map[i][j - 1] = 1;
					break;
				case 2:
					p_map[i + 1][j] = 1;
					break;
				case 3:
					p_map[i][j + 1] = 1;
					break;
				}
				
			}
		}
	}
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	HBRUSH newBrush;
	HBRUSH oldBrush;
	
	static int EasyMap[EASYSIZE][EASYSIZE];
	static int NomalMap[NOMALSIZE][NOMALSIZE];
	static int HardMap[HARDSIZE][HARDSIZE];
	static int arrsize = 0;
	static RECT wRect;
	static POINT Player;
	static BOOL StageSelect = FALSE;

	switch (iMessage) {

	case WM_CREATE:
		GetClientRect(hWnd, &wRect);
		Player.x = 20;
		Player.y = 60;
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_EASY:
			arrsize = EASYSIZE;
			MapSeting(EasyMap, arrsize);
			break;
		case ID_NOMAL:
			arrsize = NOMALSIZE;
			MapSeting(NomalMap, arrsize);
			break;
		case ID_HARD:
			arrsize = HARDSIZE;
			MapSeting(HardMap, arrsize);
			break;
		}
		Player.x = 20;
		Player.y = 60;
		StageSelect = TRUE;
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_KEYDOWN:
		if (StageSelect != TRUE)
			break;
		switch (wParam)
		{
		case 'W':
		case VK_UP:
			if (Player.y - SIZE <= wRect.top)
				break;
			if (arrsize == EASYSIZE && (EasyMap[(Player.y - SIZE) / SIZE][Player.x / SIZE] == 1 || EasyMap[(Player.y - SIZE) / SIZE][Player.x / SIZE] == 4))
				break;
			if (arrsize == NOMALSIZE && (NomalMap[(Player.y - SIZE) / SIZE][Player.x / SIZE] == 1 || NomalMap[(Player.y - SIZE) / SIZE][Player.x / SIZE] == 4))
				break;
			if (arrsize == HARDSIZE && (HardMap[(Player.y - SIZE) / SIZE][Player.x / SIZE] == 1 || HardMap[(Player.y - SIZE) / SIZE][Player.x / SIZE] == 4))
				break;
			Player.y -= SIZE;
			break;
		case 'S':
		case VK_DOWN:
			if (Player.y + SIZE >= wRect.bottom)
				break;
			if (arrsize == EASYSIZE && (EasyMap[(Player.y + SIZE) / SIZE][Player.x / SIZE] == 1 || EasyMap[(Player.y + SIZE) / SIZE][Player.x / SIZE] == 4))
				break;
			if (arrsize == NOMALSIZE && (NomalMap[(Player.y + SIZE) / SIZE][Player.x / SIZE] == 1 || NomalMap[(Player.y + SIZE) / SIZE][Player.x / SIZE] == 4))
				break;
			if (arrsize == HARDSIZE && (HardMap[(Player.y + SIZE) / SIZE][Player.x / SIZE] == 1 || HardMap[(Player.y + SIZE) / SIZE][Player.x / SIZE] == 4))
				break;
			Player.y += SIZE;
			break;
		case 'A':
		case VK_LEFT:
			if (Player.x - SIZE <= wRect.left)
				break;
			if (arrsize == EASYSIZE && (EasyMap[Player.y / SIZE][(Player.x - SIZE) / SIZE] == 1 || EasyMap[Player.y / SIZE][(Player.x - SIZE) / SIZE] == 4))
				break;
			if (arrsize == NOMALSIZE && (NomalMap[Player.y / SIZE][(Player.x - SIZE) / SIZE] == 1 || NomalMap[Player.y / SIZE][(Player.x - SIZE) / SIZE] == 4))
				break;
			if (arrsize == HARDSIZE && (HardMap[Player.y / SIZE][(Player.x - SIZE) / SIZE] == 1 || HardMap[Player.y / SIZE][(Player.x - SIZE) / SIZE] == 4))
				break;
			Player.x -= SIZE;
			break;
		case 'D':
		case VK_RIGHT:
			
			if (Player.x + SIZE >= wRect.right)
				break;
			if (arrsize == EASYSIZE && (EasyMap[Player.y / SIZE][(Player.x + SIZE) / SIZE] == 1 || EasyMap[Player.y / SIZE][(Player.x + SIZE) / SIZE] == 4))
				break;
			if (arrsize == NOMALSIZE && (NomalMap[Player.y / SIZE][(Player.x + SIZE) / SIZE] == 1 || NomalMap[Player.y / SIZE][(Player.x + SIZE) / SIZE] == 4))
				break;
			if (arrsize == HARDSIZE && (HardMap[Player.y / SIZE][(Player.x + SIZE) / SIZE] == 1 || HardMap[Player.y / SIZE][(Player.x + SIZE) / SIZE] == 4))
				break;
			Player.x += SIZE;
			
			break;
			
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		newBrush = CreateSolidBrush(RGB(0, 255, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
		Ellipse(hdc, Player.x - SIZE / 2, Player.y - SIZE / 2, Player.x + SIZE / 2, Player.y + SIZE / 2);

		newBrush = CreateSolidBrush(RGB(255, 0, 0));
		oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		if (StageSelect == TRUE)
		{
			for (int i = 0; i < arrsize; i++)
			{
				for (int j = 0; j < arrsize; j++)
				{
					if (arrsize == EASYSIZE)
					{
						if (EasyMap[i][j] == 1 || EasyMap[i][j] == 4)
							Rectangle(hdc, j * SIZE, i * SIZE, j * SIZE + SIZE, i * SIZE + SIZE);
					}
					else if (arrsize == NOMALSIZE)
					{
						if (NomalMap[i][j] == 1 || NomalMap[i][j] == 4)
							Rectangle(hdc, j * SIZE, i * SIZE, j * SIZE + SIZE, i * SIZE + SIZE);
					}
					else
					{
						if (HardMap[i][j] == 1 || HardMap[i][j] == 4)
							Rectangle(hdc, j * SIZE, i * SIZE, j * SIZE + SIZE, i * SIZE + SIZE);
					}
					if (i == arrsize - 2 && j == arrsize - 1)
						TextOut(hdc, (arrsize - 1) * SIZE + 5, (arrsize - 2) * SIZE + 10, TEXT("End"), 3);
					if (i == 1 && j == 0)
						TextOut(hdc, j * SIZE + 5, i * SIZE + 10, TEXT("Start"), 5);
				}
			}
			if (Player.x >= (arrsize - 1) * SIZE)
			{
				MessageBox(hWnd, TEXT("Finish!"), TEXT("End"), MB_OKCANCEL);
				switch (arrsize)
				{
				case EASYSIZE:
					MapSeting(EasyMap, arrsize);
					break;
				case NOMALSIZE:
					MapSeting(NomalMap, arrsize);
					break;
				case HARDSIZE:
					MapSeting(HardMap, arrsize);
					break;
				}
				Player.x = 20;
				Player.y = 60;
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}

		SelectObject(hdc, oldBrush);
		DeleteObject(newBrush);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
