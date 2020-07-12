#include "Global.h"
#include "Bullet.h"
#include "Player.h"

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
// �����ϴ� ����� ���ð����� �����غ��� �; �̹����� ȸ�����ִ� �Լ��� �����Խ��ϴ�.
#pragma region Rotate_Function
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

// �Ѿ� �߻�� ��ǥ ȸ���� ���� �Լ��Դϴ�.
POINT GetRotatedPos(int x, int y, float angle)
{
	angle = angle * (PI / 180);
	POINT temp;

	temp.x = x * cos(angle) + y * sin(angle);
	temp.y = x * sin(angle) - y * cos(angle);

	return temp;
}
// ȭ�� �ٱ����� ������츦 ó���ϴ� �Լ��Դϴ�.
bool isOverClient(POINT pos, RECT rt)
{
	if (pos.x < 0 || pos.x > rt.right)
		return true;
	if (pos.y < 0 || pos.y > rt.bottom)
		return true;
	return false;
}
// ȭ�� �ٱ����� ������츦 ó���ϴ� �Լ��Դϴ�.
bool isOverClient(RECT prt, RECT rt)
{
	if (prt.left < 0 || prt.right > rt.right)
		return true;
	if (prt.top < 0 || prt.bottom > rt.bottom)
		return true;
	return false;
}

// Set HDC for DoubleBuffering
void SettingDC(HDC& offsetDC, HDC& hdc, HBITMAP& backbitmap, HBITMAP& Oldbackbitmap, RECT& rect )
{
	hdc = CreateCompatibleDC(offsetDC);
	backbitmap = CreateCompatibleBitmap(offsetDC, rect.right, rect.bottom);
	Oldbackbitmap = (HBITMAP)SelectObject(hdc, backbitmap);
	PatBlt(hdc, 0, 0, rect.right, rect.bottom, WHITENESS);
}
// Remove HDC for DoubleBuffering
void RemovingDC(HDC& hdc, HBITMAP& backbitmap, HBITMAP& Oldbitmap)
{
	SelectObject(hdc, Oldbitmap);
	DeleteDC(hdc);
	DeleteObject(backbitmap);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

	static HDC hdc, BACKDC, PlayerDC, BulletDC, EnemyDC;
	static PAINTSTRUCT ps;

	static HBITMAP BackGroundBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_GALAGA_MAP));
	static HBITMAP backBitmap, OldBackBitmap;

	static HBITMAP PlayerBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAYER));
	static HBITMAP PlayerbackBitmap, OldPlayerBitmap;

	static HBITMAP PlayerBulletBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_PLAYER));
	static HBITMAP EnemyBulletBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_ENEMY));
	static HBITMAP BulletbackBitmap, OldBulletBitmap;
	
	static HBITMAP Enemy1_1bitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY01_1));
	static HBITMAP Enemy1_2bitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY01_2));
	static HBITMAP Enemy2_1bitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY02_1));
	static HBITMAP Enemy2_2bitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY02_2));
	static HBITMAP EnemybackBitmap, OldEnemyBitmap;


	static RECT rect;

	BITMAP bit;
	int bx, by;

	static Player* player;

	static int MapPos_01;
	static int MapPos_02;
	static const float MapLoopSpeed = 3;

	static Bullet* plBltList[50];		//Player Bullet List
	const POINT BltMvOffset = { 0,5 };	//Bullet Move Offset
	// speed = 5 ��� y����� +- 5 = (0,5), (0,-5)

	switch (iMessage) {
	case WM_CREATE:
		SetRect(&rect, 0, 0, 800, 600);
		player = new Player(rect, PlayerBitmap);
		MapPos_01 = 0;
		MapPos_02 = 0 - rect.bottom;

		for (int i = 0; i < 50; i++)
			plBltList[i] = new Bullet(player->GetPos(), PlayerBulletBitmap);
		
		MoveWindow(hWnd, 800, 200, rect.right, rect.bottom, TRUE);
		SetTimer(hWnd, IDT_MAP_LOOP, 10, NULL);
		SetTimer(hWnd, IDT_PLAYER_MOVE, 10, NULL);
		SetTimer(hWnd, IDT_BULLET_MOVE, 10, NULL);
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
			MapPos_01 += MapLoopSpeed;
			MapPos_02 += MapLoopSpeed;
			if (MapPos_02 >= 0)
			{
				MapPos_01 = 0;
				MapPos_02 = 0 - rect.bottom;
			}
			break;
		case IDT_PLAYER_MOVE:
			player->PlayerMove();
			if (isOverClient(player->GetRect(), rect))
				player->ResetPos();
			break;
		case IDT_BULLET_MOVE:
			for (int i = 0; i < 50; i++)
			{
				plBltList[i]->BulletMove();
				if (isOverClient(plBltList[i]->Position, rect))
					plBltList[i]->isShoot = false;
			}
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
			player->SetXmove(xMove::XLEFT);
			break;
		case VK_RIGHT:
			player->SetXmove(xMove::XRIGHT);
			break;
		case VK_UP:
			player->SetYmove(yMove::YUP);
			break;
		case VK_DOWN:
			player->SetYmove(yMove::YDOWN);
			break;
		case 'A':
			player->SetRotate(Rotate::RLEFT);
			break;
		case 'D':
			player->SetRotate(Rotate::RRIGHT);
			break;
		case 'S':
			int Count = player->GetCount();
			plBltList[Count]->isShoot = true;
			plBltList[Count]->Angle = player->GetAngle();
			plBltList[Count]->Increase = GetRotatedPos(BltMvOffset.x, BltMvOffset.y, plBltList[Count]->Angle);
			plBltList[Count]->Position = player->GetPos();
			player->SetCount(++Count);
			if (player->GetCount() >= 50)
				player->SetCount(0);
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam)
		{
		case 'A':
		case 'D':
			player->SetRotate(Rotate::RNONE);
			break;
		case VK_LEFT:
		case VK_RIGHT:
			player->SetXmove(xMove::XNONE);
			break;
		case VK_UP:
		case VK_DOWN:
			player->SetYmove(yMove::YNONE);
			break;
		}
		break;
	case WM_COMMAND:
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Making DC
		SettingDC(hdc, BACKDC, backBitmap, OldBackBitmap, rect);
		SettingDC(hdc, PlayerDC, PlayerbackBitmap, OldPlayerBitmap, rect);
		SettingDC(hdc, EnemyDC, EnemybackBitmap, OldEnemyBitmap, rect);
		SettingDC(hdc, BulletDC, BulletbackBitmap, OldBulletBitmap, rect);

		DrawBitmap(BACKDC, 0, 0, BackGroundBitmap);

		GetObject(BackGroundBitmap, sizeof(BITMAP), &bit);
		bx = bit.bmWidth;
		by = bit.bmHeight;

		// Draw Map
		StretchBlt(hdc, 0, MapPos_01, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);
		StretchBlt(hdc, 0, MapPos_02, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);

		// Draw Player (Rotate Realize)
		RotateBlt(hdc, PlayerDC, 0, 0, player->GetWidth(), player->GetHeight(), player->GetImage(), 0, 0, SRCAND, player->GetAngle(), RGB(255, 255, 255));
		TransparentBlt(hdc, player->GetPos().x, player->GetPos().y, player->GetWidth() * 1.5f, player->GetHeight() * 1.5f, PlayerDC, 0, 0, player->GetWidth(), player->GetHeight(), RGB(255,255,255));

		// Draw Player Bullet (Rotate Realize)
		for (int i = 0; i < 50; i++)
		{
			if (plBltList[i]->isShoot == true)
			{
				DrawBitmap(BulletDC, 0, 0, plBltList[i]->Img);
				TransparentBlt(hdc, plBltList[i]->Position.x, plBltList[i]->Position.y, plBltList[i]->Width * 1.5f, plBltList[i]->Height * 1.5f,
					BulletDC, 0, 0, plBltList[i]->Width, plBltList[i]->Height, RGB(255, 255, 255));
			}
		}
		
		// Delete DC
		RemovingDC(BulletDC, BulletbackBitmap, OldBulletBitmap);
		RemovingDC(PlayerDC, PlayerbackBitmap, OldPlayerBitmap);
		RemovingDC(PlayerDC, PlayerbackBitmap, OldPlayerBitmap);
		RemovingDC(BACKDC, backBitmap, OldBackBitmap);
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

