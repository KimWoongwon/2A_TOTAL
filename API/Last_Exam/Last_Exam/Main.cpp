#include <windows.h>
#include <time.h>
#include <math.h>
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

// ������۸��� ���� �׸��� �Լ��Դϴ�.
#pragma region DoubleBuffering
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

	StretchBlt(hdc, x, y, BitmapX, BitmapY, MemoryDC, 0, 0, BitmapX, BitmapY, SRCCOPY);
	SelectObject(MemoryDC, OldBitmap);
	DeleteDC(MemoryDC);
}
#pragma endregion

// �����ϴ� ����� ���ð����� �����غ��� �; �̹����� ȸ�����ִ� �Լ��� �����Խ��ϴ�.
#define PI 3.141592654
#pragma region RotateFunction
HBITMAP GetRotatedBitmap(HDC hdc, HBITMAP hBitmap, int source_x, int source_y, int dest_width, int dest_height, float angle, COLORREF bkColor)
{
	HDC sourceDC = CreateCompatibleDC(hdc); // ȸ���� ��Ʈ�� ������ ������ DC
	HDC destDC = CreateCompatibleDC(hdc); // ȸ���� ��Ʈ���� ��¹��� DC
	HBITMAP hbmResult = CreateCompatibleBitmap(hdc, dest_width, dest_height); // ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� �ڵ�

	HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, hBitmap); // ȸ���� ��Ʈ�� ������ DC�� ����
	HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult); // ȸ���� ��Ʈ���� ��¹��� DC��, ȸ���� ��Ʈ���� ��¹��� �޸𸮺�Ʈ�� ����

	HBRUSH hbrBack = CreateSolidBrush(bkColor); // ȸ������ ����, ���鿵���� ĥ�� �귯���ڵ� ����
	HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack); // �귯���ڵ� ����
	PatBlt(destDC, 0, 0, dest_width, dest_height, PATCOPY); // ���õ� �귯�÷�, ȸ���� ��Ʈ���� ��¹��� DC��, �̸� ������ ä�� ����
	DeleteObject(SelectObject(destDC, hbrOld)); // �귯�� ����

	angle = (float)(angle * PI / 180); // ȸ���� ����(360�й�)��, ���ȴ����� ������ ����
	float cosine = (float)cos(angle); // ȸ���̵���ȯ ��Ŀ� �� cos��Ÿ ���� ����
	float sine = (float)sin(angle); // ȸ���̵���ȯ ��Ŀ� �� sin��Ÿ ���� ����

	SetGraphicsMode(destDC, GM_ADVANCED); // ������ ��ǥ���� ȸ���� ���Ͽ�, �׷��ȸ�带 Ȯ����� �����մϴ�.(�䱸����:��98,NT�̻�)

	XFORM xform; // �������� ǥ���ϴ� 3��3���� ��� ����
	xform.eM11 = cosine; // 1�� 1�� ���� ���� (ȸ������)
	xform.eM12 = sine; // 1�� 2�� ���� ���� (ȸ������)
	xform.eM21 = -sine; // 2�� 1�� ���� ���� (ȸ������)
	xform.eM22 = cosine; // 2�� 2�� ���� ���� (ȸ������)
	xform.eDx = (FLOAT)dest_width / 2.0f; // 3�� 1�� ���� ���� (X�� �̵� ����)
	xform.eDy = (FLOAT)dest_height / 2.0f; // 3�� 2�� ���� ���� (Y�� �̵� ����)

	// ������ ��ķ�, �μ�DC�� �������� ��ǥ�踦 ��ȯ.
	// �μ�DC�� ��´������ �޸𸮺�Ʈ���� �����Ƿ�,
	// �����ϰ� �ִ� �޸𸮺�Ʈ���� ��ǥü�谡 ȸ���ȴ�.

	SetWorldTransform(destDC, &xform);

	// ȸ���� �޸�DC��, ȸ���� �̹����� ���

	BitBlt(destDC, -(dest_width / 2), -(dest_height / 2), dest_width, dest_height, sourceDC, source_x, source_y, SRCCOPY);

	// ���� �ڿ� ����

	SelectObject(sourceDC, hbmOldSource);
	SelectObject(destDC, hbmOldDest);
	DeleteObject(sourceDC);
	DeleteObject(destDC);

	// ȸ���� ��Ʈ�� �ڵ� ����

	return hbmResult;
}

void RotateBlt(HDC hdc, HDC hOffScreen, int dest_x, int dest_y, int dest_width, int dest_height, HBITMAP hBit, int source_x, int source_y, DWORD dFlag, float angle, COLORREF bkColor)
{
	static HDC hTempMemDC; // ȸ���� ��Ʈ���� ������ �޸�DC
	HBITMAP hTempBitmap, hOldBitmap; // ȸ���� ��Ʈ���� ������, ��Ʈ�� �ڵ�

	// ���� �ѹ��� ��Ʈ��DC�� �����մϴ�.

	if (!hTempMemDC) hTempMemDC = CreateCompatibleDC(hdc);

	// ��Ʈ���� ȸ���ϴ� �Լ��� ȣ���Ͽ�, ���ϵǴ� ȸ���� ��Ʈ�� �ڵ��� ����

	hTempBitmap = GetRotatedBitmap(hdc, hBit, source_x, source_y, dest_width, dest_height, angle, bkColor);

	// ȸ���� ��Ʈ�� �ڵ��� �����ϰ�,

	hOldBitmap = (HBITMAP)SelectObject(hTempMemDC, hTempBitmap);

	// ������ũ��DC��, ȸ���� ��Ʈ�� �ڵ��� ������, �޸�DC�� �̹����� ����մϴ�.
	// ���� �ּ��� �����ϸ�, �����ǥ�� �߽����� �ϴ� ȸ���̹����� �˴ϴ�.

	BitBlt(hOffScreen, dest_x/* - dest_width/2*/, dest_y/* - dest_height/2*/, dest_width, dest_height,
		hTempMemDC, 0, 0, dFlag);

	SelectObject(hTempMemDC, hOldBitmap);
	DeleteObject(hTempBitmap);
}
#pragma endregion ��ó : https://ldh-room.tistory.com/entry/API�̹���-ȸ����Ű�� [��ǰ������]

#define IDT_MAP_LOOP 1000
#define IDT_PLAYER_MOVE 1001

class Bullet
{
public:
	POINT Position;
	HBITMAP Img;
	int Width;
	int Height;
	float Angle;
	bool isShoot;

	Bullet(POINT pos, int image_id)
	{
		Position = pos;
		Img = LoadBitmap(g_hInst, MAKEINTRESOURCE(image_id));
		isShoot = false;
		Angle = 0.0f;

		BITMAP bit;
		GetObject(Img, sizeof(BITMAP), &bit);
		Width = bit.bmWidth;
		Height = bit.bmHeight;
	}
};

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	static HDC hdc, BACKDC, PlayerDC, BulletDC;
	static PAINTSTRUCT ps;

	static HBITMAP BackGroundBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_GALAGA_MAP));
	static HBITMAP PlayerBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAYER));
	static HBITMAP PlayerBulletBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_PLAYER));
	static HBITMAP backBitmap,  OldBackBitmap, PlayerbackBitmap, OldPlayerBitmap, BulletbackBitmap, OldBulletBitmap;
	static RECT rect;

	BITMAP bit;
	static int pImgSizeX, pImgSizeY;
	int bx, by;

	static POINT playerPos;
	static float PlayerMoveSpeed = 5.0f;
	static float PlayerRotateSpeed = 5.0f;
	static int playerXmove = 0;		// -1 : Left /  0 : Stop / 1 : Right
	static int playerYmove = 0;		// -1 : Up /  0 : Stop / 1 : Down
	static int playerRotate = 0;	// -1 : LeftRotate /  0 : Stop / 1 : RightRotate
	static int playerShootCount = 0;

	static int MapPos_01;
	static int MapPos_02;
	static float PlayerAngle = 0.0f;

	static Bullet* PlayerBulletList[50];

	switch (iMessage) {
	case WM_CREATE:
		
		GetObject(PlayerBitmap, sizeof(BITMAP), &bit);
		pImgSizeX = bit.bmWidth;
		pImgSizeY = bit.bmHeight;

		SetRect(&rect, 0, 0, 800, 600);
		playerPos.x = (rect.right - pImgSizeX * 1.5f) / 2;
		playerPos.y = rect.bottom - 100;
		MapPos_01 = 0;
		MapPos_02 = 0 - rect.bottom;

		for (int i = 0; i < 50; i++)
			PlayerBulletList[i] = new Bullet(playerPos, IDB_BULLET_PLAYER);
		
		MoveWindow(hWnd, 800, 200, rect.right, rect.bottom, TRUE);
		SetTimer(hWnd, IDT_MAP_LOOP, 10, NULL);
		SetTimer(hWnd, IDT_PLAYER_MOVE, 10, NULL);
		return 0;
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = rect.right;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = rect.right;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = rect.bottom;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = rect.bottom;
		break;
	case WM_TIMER:
		switch (wParam)
		{
		case IDT_MAP_LOOP:
			MapPos_01 += 3;
			MapPos_02 += 3;
			if (MapPos_02 >= 0)
			{
				MapPos_01 = 0;
				MapPos_02 = 0 - rect.bottom;
			}
			break;
		case IDT_PLAYER_MOVE:
			playerPos.x += PlayerMoveSpeed * playerXmove;
			playerPos.y += PlayerMoveSpeed * playerYmove;

			PlayerAngle += PlayerRotateSpeed * playerRotate;
			if (abs((int)PlayerAngle) >= 360)
				PlayerAngle = 5.0f;

			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			playerXmove = -1;
			break;
		case VK_RIGHT:
			playerXmove = 1;
			break;
		case VK_UP:
			playerYmove = -1;
			break;
		case VK_DOWN:
			playerYmove = 1;
			break;
		case 'A':
			playerRotate = -1;
			break;
		case 'D':
			playerRotate = 1;
			break;
		case 'S':
			PlayerBulletList[playerShootCount]->isShoot = true;
			PlayerBulletList[playerShootCount]->Angle = PlayerAngle;
			PlayerBulletList[playerShootCount++]->Position = playerPos;
			if (playerShootCount >= 50)
				playerShootCount = 0;
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam)
		{
		case 'A':
		case 'D':
			playerRotate = 0;
			break;
		case VK_LEFT:
		case VK_RIGHT:
			playerXmove = 0;
			break;
		case VK_UP:
		case VK_DOWN:
			playerYmove = 0;
			break;
		}
		break;
	case WM_COMMAND:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		BACKDC = CreateCompatibleDC(hdc);
		backBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		OldBackBitmap = (HBITMAP)SelectObject(BACKDC, backBitmap);
		PatBlt(BACKDC, 0, 0, rect.right, rect.bottom, WHITENESS);

		PlayerDC = CreateCompatibleDC(hdc);
		PlayerbackBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		OldPlayerBitmap = (HBITMAP)SelectObject(PlayerDC, PlayerbackBitmap);
		PatBlt(PlayerDC, 0, 0, rect.right, rect.bottom, WHITENESS);

		BulletDC = CreateCompatibleDC(hdc);
		BulletbackBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
		OldBulletBitmap = (HBITMAP)SelectObject(BulletDC, BulletbackBitmap);
		PatBlt(BulletDC, 0, 0, rect.right, rect.bottom, WHITENESS);


		DrawBitmap(BACKDC, 0, 0, BackGroundBitmap);

		GetObject(BackGroundBitmap, sizeof(BITMAP), &bit);
		bx = bit.bmWidth;
		by = bit.bmHeight;

		// Draw Map
		StretchBlt(hdc, 0, MapPos_01, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);
		StretchBlt(hdc, 0, MapPos_02, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);

		// Draw Player (Rotate Realize)
		RotateBlt(hdc, PlayerDC, 0, 0, pImgSizeX, pImgSizeY, PlayerBitmap, 0, 0, SRCAND, PlayerAngle, RGB(255, 255, 255));
		TransparentBlt(hdc, playerPos.x, playerPos.y, pImgSizeX * 1.5f, pImgSizeY * 1.5f, PlayerDC, 0, 0, pImgSizeX, pImgSizeY, RGB(255,255,255));

		// Draw Player Bullet (Rotate Realize)
		for (int i = 0; i < 50; i++)
		{
			if (PlayerBulletList[i]->isShoot == true)
			{
				DrawBitmap(BulletDC, 0, 0, PlayerBulletList[i]->Img);
				TransparentBlt(hdc, PlayerBulletList[i]->Position.x, PlayerBulletList[i]->Position.y, PlayerBulletList[i]->Width * 1.5f, PlayerBulletList[i]->Height * 1.5f,
					BulletDC, 0, 0, PlayerBulletList[i]->Width, PlayerBulletList[i]->Height, RGB(255, 255, 255));
			}
			
		}
		

		SelectObject(BulletDC, OldBulletBitmap);
		DeleteDC(BulletDC);
		DeleteObject(BulletbackBitmap);
		SelectObject(PlayerDC, OldPlayerBitmap);
		DeleteDC(PlayerDC);
		DeleteObject(PlayerbackBitmap);
		SelectObject(BACKDC, OldBackBitmap);
		DeleteDC(BACKDC);
		DeleteObject(backBitmap);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, IDT_MAP_LOOP);
		KillTimer(hWnd, IDT_PLAYER_MOVE);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

