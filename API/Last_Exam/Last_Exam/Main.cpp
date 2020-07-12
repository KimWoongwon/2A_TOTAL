#include "Global.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"

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

	temp.x = (x * cos(angle) + y * sin(angle));
	temp.y = (x * sin(angle) - y * cos(angle));

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
// EnemyAnimaiton Realize switching Img
void EnemyAnimaition(bool state, Enemy* enemy, HBITMAP TrueImg, HBITMAP FalseImg)
{
	if (state)
		enemy->SetImage(FalseImg);
	else
		enemy->SetImage(TrueImg);
	enemy->SetAnimaitionState(!state);
}

bool CheckHit(POINT pos, RECT rt)
{
	if (pos.x > rt.left && pos.x < rt.right)
	{
		if (pos.y > rt.top && pos.y < rt.bottom)
			return true;
	}
	return false;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	// BACKDC�� �ѹ��� �� �׸��� MemDC�� �Ȱܼ� hdc�� �����ؼ� �׸���� ���߹��۸��� �����߽��ϴ�.
	static HDC hdc, MemDC, BACKDC;
	static PAINTSTRUCT ps;
	// ������۸��� �ʿ��� ��Ʈ���Դϴ�.
	static HBITMAP MembackBitmap, OldMemBitmap;
	static HBITMAP backBitmap, OldBackBitmap;

	// �� ��ü�� �̹��� (���, �÷��̾�, �÷��̾� �Ѿ�, ���� �Ѿ�)�Դϴ�.
	static HBITMAP BackGroundBitmap		= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_GALAGA_MAP));
	static HBITMAP PlayerBitmap			= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAYER));
	static HBITMAP PlayerBulletBitmap	= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_PLAYER));
	static HBITMAP EnemyBulletBitmap	= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_ENEMY));
	
	// ���� �̹��� �Դϴ�.
	static HBITMAP Enemybitmap[4][2] = 
	{
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY01_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY01_2))},
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY02_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY02_2))},
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY03_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY03_2))},
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY04_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY04_2))},
	};

	static RECT rect;							// Ŭ���̾�Ʈ ����� ���ϴ� RECT���� �Դϴ�.
	BITMAP bit;									// ����̹����� ����� ���ϱ� ���� �����Դϴ�.
	int bx, by;

	static int MapPos_01;						// ó�� ����� �׸��� ���� ��� �ϳ� + ������ �Ȱ��� �������� ����ϳ��� �̾� ������
	static int MapPos_02;						// y��ǥ�� ���� �������� ����� ������ �Ʒ��� �������°�ó�� �׷��־����ϴ�.
	const float MapLoopSpeed = 3;				// ���� �����̴� �ӵ� �Դϴ�.

	static Player* player;						// ������ �����ϴ� �÷��̾� ��ü �Դϴ�.

	static Level LevelArray[8];					// ������ �����ϱ����� ����ü�� ����� �������־����ϴ�.	������ ������ 3������ 3���������� ��ü�� ��� �̿��ϴ°����� ó���߽��ϴ�
	const POINT EmyMvOffset = { 0,5 };			//Enemy Move Offset										ex) 3���� = LevelArray[0] + LevelArray[1] + LevelArray[2]

	static Bullet* plBltList[MAX_PLBULLET];		//Player Bullet List
	const POINT BltMvOffset = { 0,5 };			//Bullet Move Offset
	// speed = 5 ��� y����� +- 5 = (0,5), (0,-5)
	
	static int NowLevel = 1;					// ���� �����Դϴ�.
	static POINT LineOffset[8];					// ������ ���� ���� �������� �������Դϴ�.
	static POINT EnemyBulletOffset[8];			// ���� �����ӿ� ���� �Ѿ� �߻簢���Դϴ�.

	static int EnemyGen = 0;					// moveŸ�̸ӿ��� ���Ǵ� �ӵ��� �����ϱ����� �����Դϴ�.
	static bool EndFlag = false;				// ��������� üũ�ϴ� �����Դϴ�.
	switch (iMessage) {
	case WM_CREATE:
		srand(time(NULL));
		SetRect(&rect, 0, 0, 800, 600);
		player = new Player(rect, PlayerBitmap);	// �÷��̾� �����ϴ� �����Դϴ�.
		MapPos_01 = 0;								// ����̹��� 1���� �ʱⰪ�� ȭ�鿡 ������
		MapPos_02 = 0 - rect.bottom;				// ����̹��� 2���� �ʱⰪ�� ȭ������ �Ⱥ��̴� ������ ���� ������� �׷��ֱ����� �ʱⰪ�Դϴ�.

		// ������ ���� ���� �������� ������ǥ���� ������ ������ �ذ��Դϴ�.
		LineOffset[0] = { rect.right - 30, 50 };
		LineOffset[1] = { rect.right / 3, 10 };
		LineOffset[2] = { rect.left + 100, 10 };
		LineOffset[3] = { 10, rect.bottom / 2 };
		LineOffset[4] = { 10, rect.bottom - 100 };
		LineOffset[5] = { rect.right / 2 + 30, rect.bottom - 30 };
		LineOffset[6] = { rect.right - 130, rect.bottom - 30 };
		LineOffset[7] = { rect.right - 30, rect.bottom / 2 };
		// ���� �����ӿ� ���� �߾ӹ������� �Ѿ��� �����°��� �����ϱ� ���ؼ� �������� ������ ������ �ذ��Դϴ�.
		EnemyBulletOffset[0] = { 0, 5 };
		EnemyBulletOffset[1] = { 3, 2 };
		EnemyBulletOffset[2] = { 5, 0 };
		EnemyBulletOffset[3] = { 3,-2 };
		EnemyBulletOffset[4] = { 0,-5 };
		EnemyBulletOffset[5] = { -3,-2 };
		EnemyBulletOffset[6] = { -5,0 };
		EnemyBulletOffset[7] = { -3,2 };

		// ������ ������ level ����ü�� �ʱ�ȭ �ϴ� �����Դϴ�.
		for (int i = 0; i < MAX_LEVEL; i++)
		{
			if (i % 2 == 0)
				LevelArray[i].Initialize(player, Enemybitmap[i % 4],
					EnemyBulletBitmap, EnemyBulletOffset[i], EnemyType::Enemy01, EnemyType::Enemy02);
			else if (i % 2 == 1)
				LevelArray[i].Initialize(player, Enemybitmap[i % 4],
					EnemyBulletBitmap, EnemyBulletOffset[i], EnemyType::Enemy03, EnemyType::Enemy04);
		}
		// �÷��̾ �߻��ϴ� �Ѿ��� ����Ʈ�� �ʱ�ȭ�ϴ� �κ��Դϴ�.
		for (int i = 0; i < MAX_PLBULLET; i++)
			plBltList[i] = new Bullet(player->GetPos(), PlayerBulletBitmap, BltMvOffset);
		// �����찡 ȭ�� �߾�(?)�� ���Բ� �� ���Ƿ� �������־����ϴ�.
		MoveWindow(hWnd, 800, 200, rect.right, rect.bottom, TRUE);
		// Ÿ�̸� �޽��� ȣ���ؼ� ���� ������ ���ư��� �ֵ��� ���ִ� �κ��Դϴ�.
		SetTimer(hWnd, IDT_MAP_LOOP, 10, NULL);
		SetTimer(hWnd, IDT_PLAYER_MOVE, 10, NULL);
		SetTimer(hWnd, IDT_BULLET_MOVE, 10, NULL);
		SetTimer(hWnd, IDT_FIXED_UPDATE, 10, NULL);
		SetTimer(hWnd, IDT_ENEMY_MOVE, 30, NULL);
		SetTimer(hWnd, IDT_ENEMY_ANIMAITION, 500, NULL);
		return 0;
	case WM_GETMINMAXINFO:// �������� ����� �����Ҽ� ������ �����ϴ� �κ��Դϴ�.
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = rect.right;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = rect.right;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = rect.bottom;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = rect.bottom;
		break;
	case WM_TIMER:	// ���� ������ ���ư��� �κ��Դϴ�.
		switch (wParam)
		{
		case IDT_FIXED_UPDATE:	// �浹, ����������� üũ�� ���� �������� ���� �ϴ� Ÿ�̸��Դϴ�.
			// ���� �Ѿ˰� �÷��̾� �浹 üũ
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					if (LevelArray[i].BulletList[j]->isShoot)
					{
						if (CheckHit(LevelArray[i].BulletList[j]->Position, player->GetRect()))
						{
							LevelArray[i].BulletList[j]->isShoot = false;
							player->loseHP();
						}
					}
				}
			}
			// ���Ϳ� �÷��̾��� �����浹 üũ
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					if (LevelArray[i].EnemyList[j]->IsVisable())
					{
						if (CheckHit(player->GetCenterPos(), LevelArray[i].EnemyList[j]->GetRect()))
						{
							LevelArray[i].EnemyList[j]->SetVisable(false);
							LevelArray[i].EnemyList[j]->SetHit(true);
							player->loseHP();
						}
					}
				}
			}
			// �÷��̾��� �Ѿ˰� ������ �浹�� üũ�ϴ� �κ��Դϴ�.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					for (int k = 0; k < MAX_PLBULLET; k++)
					{
						if (LevelArray[i].EnemyList[j]->IsVisable())
						{
							if (CheckHit(plBltList[k]->Position, LevelArray[i].EnemyList[j]->GetRect()))
							{
								plBltList[k]->isShoot = false;
								LevelArray[i].EnemyList[j]->Reset();
								LevelArray[i].EnemyList[j]->SetHit(true);
							}
						}
					}
					
				}
			}
			// �÷��̾��� ü���� 0�̵Ǹ� �ٷ� �����ϰ� ���� �ڵ�κ��� �ǳʶٱ� ���� return �մϴ�.
			if (player->GetHP() <= 0)
			{
				EndFlag = true;
				return 0;
			}
			// ���Ͱ� �¾Ҵ����� ���ο� ���� ��������� üũ�ϴ� �κ��Դϴ�. �ϳ��� �ȸ��� ���Ͱ� �ִٸ� �������� �ʰ� �Ʒ��� ������ �پ�ѽ��ϴ�.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					if (!LevelArray[i].EnemyList[j]->IsHit())
					{
						EndFlag = false;
						return 0;
					}
				}
			}
			// ���� ���ǵ��� �� ���������� ���������� Ŭ���� �ߴٰ� �Ǵ��մϴ�.
			// ���� ���� ������ ���͵��� �ʱⰪ�� �������ݴϴ�.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					LevelArray[i].EnemyList[j]->SetHit(false);
					LevelArray[i].EnemyList[j]->Reset();
				}
			}
			
			EndFlag = true;
			NowLevel++; // �������� Ŭ����� �ܰ踦 �ϳ� ���Դϴ�.
			break;
		case IDT_MAP_LOOP:	// ����̹��� ������ ���� Ÿ�̸��Դϴ�.
			MapPos_01 += MapLoopSpeed;
			MapPos_02 += MapLoopSpeed;
			if (MapPos_02 >= 0)
			{
				MapPos_01 = 0;
				MapPos_02 = 0 - rect.bottom;
			}
			break;
		case IDT_PLAYER_MOVE:	// �÷��̾� �̵��� ���� Ÿ�̸��Դϴ�.
			player->PlayerMove();
			// ȭ�� �ٱ����� ������ ó����ġ�� ���ƿɴϴ�.
			if (isOverClient(player->GetRect(), rect))
			{
				player->ResetPos();
				player->loseHP();
			}
			break;
		case IDT_BULLET_MOVE: // ����, �÷��̾��� �Ѿ��� �̵��� ���� Ÿ�̸��Դϴ�.
			// �÷��̾� �Ѿ� �̵��ϴ� �κ�
			for (int i = 0; i < MAX_PLBULLET; i++)
			{
				plBltList[i]->BulletMove();
				if (isOverClient(plBltList[i]->Position, rect))
					plBltList[i]->isShoot = false;
			}
			// ���� �Ѿ� �̵��ϴ� �κ�
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					LevelArray[i].BulletList[j]->BulletMove();
					if (isOverClient(LevelArray[i].BulletList[j]->Position, rect))
						LevelArray[i].BulletList[j]->isShoot = false;
				}
			}
			break;
		case IDT_ENEMY_MOVE:
			// Enemy generation ���� ���� �κ�
			// 30 * 20 �ؼ� 600���� �ѹ� ȣ��ǰ� �߽��ϴ�.
			// Ÿ�̸Ӹ� �� �����ϰ� �Ǹ� ���α׷��� ��������� �̷��� �����߽��ϴ�.
			if (EnemyGen++ >= 20) 
			{
				for (int i = 0; i < NowLevel; i++)
				{
					if (!LevelArray[i].EnemyList[LevelArray[i].GenCount]->IsVisable())
					{
						// �ʱⰪ�� �������ִ� �κ��Դϴ�. ������ �̹����� ȸ����Ű��, ������ �����ְ�, ���̴� ���α��� �������ݴϴ�.
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->SetPos(LineOffset[i].x, LineOffset[i].y);
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->SetAngle(-90.0f + i * -45.0f);
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->
							SetIncrease(GetRotatedPos(EmyMvOffset.x, EmyMvOffset.y, LevelArray[i].EnemyList[LevelArray[i].GenCount]->GetAngle()));
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->SetVisable(true);
						++LevelArray[i].GenCount;
						// �̺κе� ���������� ������ �̵��� ������ �ʰ� ���� �ϰԲ� �ϴ� �κ��Դϴ�.
						if (LevelArray[i].GenCount >= MAX_ENEMY)
							LevelArray[i].GenCount = 0;
					}
				}
				EnemyGen = 0;
			}
			// Enemy Move ������ �̵� �κ��Դϴ�.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_ENEMY; j++)
				{
					if (LevelArray[i].EnemyList[j]->IsVisable())
					{
						LevelArray[i].EnemyList[j]->Move();
						// �÷��̾�� ���������� ȭ����� �Ѿ�� �������ִ� �κ��Դϴ�.
						if (isOverClient(LevelArray[i].EnemyList[j]->GetPos(), rect))
							LevelArray[i].EnemyList[j]->Reset();
					}
				}
			}
			// Enemy Shoot Bullet
			for (int i = 0; i < NowLevel; i++)
			{
				if (rand() % 100 <= 10 + 5 * NowLevel)	// Ȯ�������� ���Ͱ� �Ѿ��� �߻� �Ҽ� �ְԲ� �������ִ� �κ��Դϴ�. 
				{										// ������ ������ MOVEŸ�̸ӿ��� �Ѿ��� �̵��մϴ�.
					int j;
					j = rand() % MAX_ENEMY;
					if (LevelArray[i].EnemyList[j]->IsVisable() && !LevelArray[i].EnemyList[j]->IsHit())
					{
						LevelArray[i].BulletList[LevelArray[i].ShotCount]->isShoot = true;
						LevelArray[i].BulletList[LevelArray[i].ShotCount]->Position.x = LevelArray[i].EnemyList[j]->GetPos().x;
						LevelArray[i].BulletList[LevelArray[i].ShotCount]->Position.y = LevelArray[i].EnemyList[j]->GetPos().y;
						LevelArray[i].ShotCount++;
						if (LevelArray[i].ShotCount >= MAX_EYBULLET)
							LevelArray[i].ShotCount = 0;
					}
				}
			}
			break;
			
		case IDT_ENEMY_ANIMAITION:	// ������ �ִϸ��̼� ȿ���� �����غ��� �;����ϴ�. �ð����� ������ �̹����� �ٲ��ִ°����� �ذ��߽��ϴ�.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_ENEMY; j++)
				{
					if (LevelArray[i].EnemyList[j]->GetEnemyType() == EnemyType::Enemy01)
						EnemyAnimaition(LevelArray[i].EnemyList[j]->GetAnimaitionState(), LevelArray[i].EnemyList[j], Enemybitmap[0][1], Enemybitmap[0][0]);
					else if (LevelArray[i].EnemyList[j]->GetEnemyType() == EnemyType::Enemy02)
						EnemyAnimaition(LevelArray[i].EnemyList[j]->GetAnimaitionState(), LevelArray[i].EnemyList[j], Enemybitmap[1][0], Enemybitmap[1][1]);
					else if (LevelArray[i].EnemyList[j]->GetEnemyType() == EnemyType::Enemy03)
						EnemyAnimaition(LevelArray[i].EnemyList[j]->GetAnimaitionState(), LevelArray[i].EnemyList[j], Enemybitmap[2][1], Enemybitmap[2][0]);
					else if (LevelArray[i].EnemyList[j]->GetEnemyType() == EnemyType::Enemy04)
						EnemyAnimaition(LevelArray[i].EnemyList[j]->GetAnimaitionState(), LevelArray[i].EnemyList[j], Enemybitmap[3][0], Enemybitmap[3][1]);
				}
			}
			
			break;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_KEYDOWN:
		// Ű���� �κ��Դϴ�.
		// �̺κп��� ������ ����, ȸ��� ���� MoveŸ�̸ӿ��� �۵��մϴ�.
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
		case 'S':	// sŰ�� ������ �Ѿ��� �߻��մϴ�.
			int Count = player->GetCount();
			plBltList[Count]->isShoot = true;
			plBltList[Count]->Angle = player->GetAngle();
			plBltList[Count]->Increase = GetRotatedPos(BltMvOffset.x, BltMvOffset.y, plBltList[Count]->Angle);
			plBltList[Count]->Position.x = player->GetPos().x + player->GetWidth() / 2;
			plBltList[Count]->Position.y = player->GetPos().y + player->GetHeight() /2;
			player->SetCount(++Count);
			if (player->GetCount() >= MAX_PLBULLET)
				player->SetCount(0);
			break;
		}
		break;
	case WM_KEYUP:	// Ÿ�̸ӿ� ���� �����̱⶧���� ŰUP�� �������� �ʱ�ȭ�� ���־�� �̵��� ����ϴ�.
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
	case WM_PAINT:	// ���� �߿��ϴٰ� �����ϴ� PAINT �޽��� �Դϴ�.
		hdc = BeginPaint(hWnd, &ps);
		if (EndFlag)	// ��������� �Ǹ� ȭ�鿡 �޽����� ����մϴ�.
		{
			TCHAR tempString[20];
			if (player->GetHP() <= 0)	// ���� HP�� 0�̶�� ������ �����մϴ�.
				wsprintf(tempString, "You Lose!");
			else
				wsprintf(tempString, "Congratulation!");

			HFONT font = CreateFont(30, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, TEXT("�ü�ü"));	// ��Ʈ�� �������ְ�
			HFONT oldFont = (HFONT)SelectObject(hdc, font);
			SetTextColor(hdc, RGB(255, 255, 255));		// ������ ������ �����ְ�
			SetBkMode(hdc, TRANSPARENT);				// ������ ������ �������� �����Ѵ���
			TextOut(hdc, rect.right/2 - lstrlen(tempString) / 5 * 30, 200, tempString, lstrlen(tempString));// ����մϴ�.
			if (player->GetHP() > 0)	// HP�� 0�� �ƴ϶�� Ŭ���������� ���� ��������� Ŭ�����ߴ��� ������ݴϴ�.
			{
				font = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, TEXT("�ü�ü"));
				oldFont = (HFONT)SelectObject(hdc, font);
				TCHAR temp[20];
				wsprintf(temp, "Stage %d Clear!", NowLevel - 1);
				TextOut(hdc, rect.right / 2 - lstrlen(temp) / 5 * 20, 250, temp, lstrlen(temp));
			}
			SelectObject(hdc, oldFont);
			DeleteObject(font);
			Sleep(1000);	// �ʹ� ������ �������� �ʰ� Sleep�� �ɾ��־����ϴ�.
			if (player->GetHP() > 0)	// Ŭ���������� HP�� �ٽ� �������ְ�
			{
				player->SetHP(10);
				return 0;
			}
			else if (player->GetHP() <= 0)	// Ŭ���� ���� �������� ���α׷��� �����ϱ� ���� WM_DESTROY�޽����� hWnd�� �����ϴ�.
			{
				SendMessage(hWnd, WM_DESTROY, wParam, lParam);
			}
		}
		else		// ���� ������ ���� ȣ��Ǵ� �κ��Դϴ�.
		{
			// Making DC �Լ��� �̿��ؼ� �ڵ带 �ٿ����ҽ��ϴ�. ���� �ڵ尡 ������� ���� ������ ��� �ٿ����ϴ�.
			SettingDC(hdc, MemDC, MembackBitmap, OldMemBitmap, rect);
			SettingDC(MemDC, BACKDC, backBitmap, OldBackBitmap, rect);

			DrawBitmap(BACKDC, 0, 0, BackGroundBitmap);	// BACKDC�� ����̹����� �׸���

			GetObject(BackGroundBitmap, sizeof(BITMAP), &bit);
			bx = bit.bmWidth;
			by = bit.bmHeight;

			// Draw Map	StretchBlt�� �̿��Ͽ� ���� �ϱ����� �̹����� �ΰ� �����ؿɴϴ�.
			StretchBlt(MemDC, 0, MapPos_01, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);
			StretchBlt(MemDC, 0, MapPos_02, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);

			// Draw Player (Rotate Realize)	�ܺο��� ������ ȸ���ؼ� �׷��ִ� �Լ��� �̿��ؼ� �׷��ݴϴ�.
			RotateBlt(hdc, BACKDC, 0, 0, player->GetWidth(), player->GetHeight(), player->GetImage(), 0, 0, SRCCOPY, player->GetAngle(), RGB(255, 255, 255)); // ������۸� ����� �������� �ʱ⶧���� ������۸��� �ϱ����� BACKDC�� �۸��ϴ�.
			TransparentBlt(MemDC, player->GetPos().x, player->GetPos().y, player->GetWidth() * 1.5f, player->GetHeight() * 1.5f, BACKDC, 0, 0, player->GetWidth(), player->GetHeight(), RGB(255, 255, 255));
			// BACKDC�� MemDC�� �׸��ϴ�. �Ŀ� �ٽ� hdc�� �׷��־ ���������� ���߹��۸��� �����մϴ�.

			// Draw Player Bullet �÷��̾��� �Ѿ��� �׷��ݴϴ�. 
			for (int i = 0; i < MAX_PLBULLET; i++)
			{
				if (plBltList[i]->isShoot == true)	// ����Ʈ���θ� �׸��� �ʰ� ������ �ɾ��ݴϴ�.
				{
					DrawBitmap(BACKDC, 0, 0, plBltList[i]->Img);	// ���������� ������۸��� ���� BACKDC�� �׷��ݴϴ�.
					TransparentBlt(MemDC, plBltList[i]->Position.x, plBltList[i]->Position.y, plBltList[i]->Width * 1.5f, plBltList[i]->Height * 1.5f,
						BACKDC, 0, 0, plBltList[i]->Width, plBltList[i]->Height, RGB(255, 255, 255));
				}
			}

			// ���Ͱ� �߻��� �Ѿ��� �׷��ݴϴ�.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					if (LevelArray[i].BulletList[j]->isShoot == true)
					{
						DrawBitmap(BACKDC, 0, 0, LevelArray[i].BulletList[j]->Img);	//.������۸��� ���� BACKDC�� �׸���
						TransparentBlt(MemDC, LevelArray[i].BulletList[j]->Position.x, LevelArray[i].BulletList[j]->Position.y, LevelArray[i].BulletList[j]->Width * 1.5f, LevelArray[i].BulletList[j]->Height * 1.5f,
							BACKDC, 0, 0, LevelArray[i].BulletList[j]->Width, LevelArray[i].BulletList[j]->Height, RGB(255, 255, 255));	// �ٽ��ѹ� ���۸��� �ϱ����� MemDC�� �ȱ�ϴ�
					}
				}
			}

			// Draw Enemy (Rotate Realize) ���͸� �׷��ݴϴ�.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_ENEMY; j++)
				{
					if (LevelArray[i].EnemyList[j]->IsVisable() && !LevelArray[i].EnemyList[j]->IsHit())	// bool������ �̿��� �÷��̾���� � �浹�� ���� ���� ���ʹ� �׸��� �ʰԲ� �����մϴ�.
					{
						// ���������� ���۸��� ���� �׷��ݴϴ�.
						RotateBlt(hdc, BACKDC, 0, 0, LevelArray[i].EnemyList[j]->GetWidth(), LevelArray[i].EnemyList[j]->GetHeight(), LevelArray[i].EnemyList[j]->GetImage(), 0, 0, SRCCOPY, LevelArray[i].EnemyList[j]->GetAngle(), RGB(255, 255, 255));
						TransparentBlt(MemDC, LevelArray[i].EnemyList[j]->GetPos().x, LevelArray[i].EnemyList[j]->GetPos().y, LevelArray[i].EnemyList[j]->GetWidth() * 1.5f, LevelArray[i].EnemyList[j]->GetHeight() * 1.5f, BACKDC, 0, 0, LevelArray[i].EnemyList[j]->GetWidth(), LevelArray[i].EnemyList[j]->GetHeight(), RGB(255, 255, 255));
					}
				}
			}

			// ��� ������ MemDC�� ���� �ߴµ� �̰� �������� �ѹ��� hdc�� ���������ν� ���߹��۸��� �����߽��ϴ�.
			BitBlt(hdc, 0, 0, rect.right, rect.bottom, MemDC, 0, 0, SRCCOPY);

			// Delete DC
			RemovingDC(BACKDC, backBitmap, OldBackBitmap);
			RemovingDC(MemDC, MembackBitmap, OldMemBitmap);
		}
		
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		// ����� �����Ҵ� ������ Ÿ�̸� �����ϴ� �κ��Դϴ�.
		delete player;
		for (int i = 0; i < MAX_PLBULLET; i++)
			delete plBltList[i];

		for (int i = 0; i < MAX_LEVEL; i++)
		{
			for (int j = 0; j < MAX_ENEMY; j++)
			{
				delete LevelArray[i].EnemyList[j];
			}
		}
		
		for (int i = 0; i < MAX_LEVEL; i++)
		{
			for (int j = 0; j < MAX_EYBULLET; j++)
			{
				delete LevelArray[i].BulletList[j];
			}
		}


		KillTimer(hWnd, IDT_MAP_LOOP);
		KillTimer(hWnd, IDT_PLAYER_MOVE);
		KillTimer(hWnd, IDT_BULLET_MOVE);
		KillTimer(hWnd, IDT_FIXED_UPDATE);
		KillTimer(hWnd, IDT_ENEMY_MOVE);
		KillTimer(hWnd, IDT_ENEMY_ANIMAITION);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

