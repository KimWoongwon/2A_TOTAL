#include <windows.h>
#include <time.h>
#include <math.h>
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

// 더블버퍼링을 위한 그리기 함수입니다.
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

// 생각하던 방식의 슈팅게임을 구현해보고 싶어서 이미지를 회전해주는 함수를 가져왔습니다.
#define PI 3.141592654
#pragma region RotateFunction
HBITMAP GetRotatedBitmap(HDC hdc, HBITMAP hBitmap, int source_x, int source_y, int dest_width, int dest_height, float angle, COLORREF bkColor)
{
	HDC sourceDC = CreateCompatibleDC(hdc); // 회전할 비트맵 원본을 선택할 DC
	HDC destDC = CreateCompatibleDC(hdc); // 회전할 비트맵을 출력받을 DC
	HBITMAP hbmResult = CreateCompatibleBitmap(hdc, dest_width, dest_height); // 회전할 비트맵을 출력받을 메모리비트맵 핸들

	HBITMAP hbmOldSource = (HBITMAP)SelectObject(sourceDC, hBitmap); // 회전할 비트맵 원본을 DC에 선택
	HBITMAP hbmOldDest = (HBITMAP)SelectObject(destDC, hbmResult); // 회전할 비트맵을 출력받을 DC에, 회전할 비트맵을 출력받을 메모리비트맵 선택

	HBRUSH hbrBack = CreateSolidBrush(bkColor); // 회전으로 인한, 공백영역을 칠할 브러시핸들 생성
	HBRUSH hbrOld = (HBRUSH)SelectObject(destDC, hbrBack); // 브러시핸들 선택
	PatBlt(destDC, 0, 0, dest_width, dest_height, PATCOPY); // 선택된 브러시로, 회전할 비트맵을 출력받을 DC에, 미리 색상을 채워 지움
	DeleteObject(SelectObject(destDC, hbrOld)); // 브러시 해제

	angle = (float)(angle * PI / 180); // 회전할 각도(360분법)를, 라디안단위의 각도로 변경
	float cosine = (float)cos(angle); // 회전이동변환 행렬에 들어갈 cos세타 값을 구함
	float sine = (float)sin(angle); // 회전이동변환 행렬에 들어갈 sin세타 값을 구함

	SetGraphicsMode(destDC, GM_ADVANCED); // 윈도우 좌표계의 회전을 위하여, 그래픽모드를 확장모드로 변경합니다.(요구사항:윈98,NT이상)

	XFORM xform; // 방정식을 표현하는 3행3열의 행렬 선언
	xform.eM11 = cosine; // 1행 1열 성분 설정 (회전성분)
	xform.eM12 = sine; // 1행 2열 성분 설정 (회전성분)
	xform.eM21 = -sine; // 2행 1열 성분 설정 (회전성분)
	xform.eM22 = cosine; // 2행 2열 성분 설정 (회전성분)
	xform.eDx = (FLOAT)dest_width / 2.0f; // 3행 1열 성분 설정 (X축 이동 성분)
	xform.eDy = (FLOAT)dest_height / 2.0f; // 3행 2열 성분 설정 (Y축 이동 성분)

	// 설정한 행렬로, 인수DC의 윈도우즈 좌표계를 변환.
	// 인수DC는 출력대상으로 메모리비트맵을 가지므로,
	// 선택하고 있는 메모리비트맵의 좌표체계가 회전된다.

	SetWorldTransform(destDC, &xform);

	// 회전된 메모리DC에, 회전할 이미지를 출력

	BitBlt(destDC, -(dest_width / 2), -(dest_height / 2), dest_width, dest_height, sourceDC, source_x, source_y, SRCCOPY);

	// 사용된 자원 해제

	SelectObject(sourceDC, hbmOldSource);
	SelectObject(destDC, hbmOldDest);
	DeleteObject(sourceDC);
	DeleteObject(destDC);

	// 회전된 비트맵 핸들 리턴

	return hbmResult;
}

void RotateBlt(HDC hdc, HDC hOffScreen, int dest_x, int dest_y, int dest_width, int dest_height, HBITMAP hBit, int source_x, int source_y, DWORD dFlag, float angle, COLORREF bkColor)
{
	static HDC hTempMemDC; // 회전한 비트맵을 선택할 메모리DC
	HBITMAP hTempBitmap, hOldBitmap; // 회전한 비트맵을 저장할, 비트맵 핸들

	// 최초 한번만 비트맵DC를 생성합니다.

	if (!hTempMemDC) hTempMemDC = CreateCompatibleDC(hdc);

	// 비트맵을 회전하는 함수를 호출하여, 리턴되는 회전된 비트맵 핸들을 저장

	hTempBitmap = GetRotatedBitmap(hdc, hBit, source_x, source_y, dest_width, dest_height, angle, bkColor);

	// 회전된 비트맵 핸들을 선택하고,

	hOldBitmap = (HBITMAP)SelectObject(hTempMemDC, hTempBitmap);

	// 오프스크린DC에, 회전된 비트맵 핸들을 선택한, 메모리DC의 이미지를 출력합니다.
	// 안의 주석을 해제하면, 출력좌표를 중심으로 하는 회전이미지가 됩니다.

	BitBlt(hOffScreen, dest_x/* - dest_width/2*/, dest_y/* - dest_height/2*/, dest_width, dest_height,
		hTempMemDC, 0, 0, dFlag);

	SelectObject(hTempMemDC, hOldBitmap);
	DeleteObject(hTempBitmap);
}
#pragma endregion 출처 : https://ldh-room.tistory.com/entry/API이미지-회전시키기 [골동품수납함]

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

