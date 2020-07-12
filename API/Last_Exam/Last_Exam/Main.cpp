#include "Global.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"

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
// 생각하던 방식의 슈팅게임을 구현해보고 싶어서 이미지를 회전해주는 함수를 가져왔습니다.
#pragma region Rotate_Function
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

// 총알 발사시 좌표 회전을 위한 함수입니다.
POINT GetRotatedPos(int x, int y, float angle)
{
	angle = angle * (PI / 180);
	POINT temp;

	temp.x = (x * cos(angle) + y * sin(angle));
	temp.y = (x * sin(angle) - y * cos(angle));

	return temp;
}
// 화면 바깥으로 나간경우를 처리하는 함수입니다.
bool isOverClient(POINT pos, RECT rt)
{
	if (pos.x < 0 || pos.x > rt.right)
		return true;
	if (pos.y < 0 || pos.y > rt.bottom)
		return true;
	return false;
}
// 화면 바깥으로 나간경우를 처리하는 함수입니다.
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
	// BACKDC에 한번에 다 그린후 MemDC에 옴겨서 hdc에 복사해서 그리기로 다중버퍼링을 구현했습니다.
	static HDC hdc, MemDC, BACKDC;
	static PAINTSTRUCT ps;
	// 더블버퍼링시 필요한 비트맵입니다.
	static HBITMAP MembackBitmap, OldMemBitmap;
	static HBITMAP backBitmap, OldBackBitmap;

	// 각 객체의 이미지 (배경, 플레이어, 플레이어 총알, 몬스터 총알)입니다.
	static HBITMAP BackGroundBitmap		= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_GALAGA_MAP));
	static HBITMAP PlayerBitmap			= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_PLAYER));
	static HBITMAP PlayerBulletBitmap	= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_PLAYER));
	static HBITMAP EnemyBulletBitmap	= LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BULLET_ENEMY));
	
	// 몬스터 이미지 입니다.
	static HBITMAP Enemybitmap[4][2] = 
	{
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY01_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY01_2))},
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY02_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY02_2))},
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY03_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY03_2))},
		{LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY04_1)),LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_ENEMY04_2))},
	};

	static RECT rect;							// 클라이언트 사이즈를 구하는 RECT변수 입니다.
	BITMAP bit;									// 배경이미지의 사이즈를 구하기 위한 변수입니다.
	int bx, by;

	static int MapPos_01;						// 처음 배경을 그릴때 꽉찬 배경 하나 + 그위로 똑같은 사이즈의 배경하나를 이어 붙혀서
	static int MapPos_02;						// y좌표를 같이 움직여서 배경이 위에서 아래로 지나가는것처럼 그려주었습니다.
	const float MapLoopSpeed = 3;				// 맵을 움직이는 속도 입니다.

	static Player* player;						// 유저가 조종하는 플레이어 객체 입니다.

	static Level LevelArray[8];					// 레벨을 구현하기위해 구조체를 만들어 선언해주었습니다.	레벨의 구현은 3레벨시 3레벨까지의 객체를 모두 이용하는것으로 처리했습니다
	const POINT EmyMvOffset = { 0,5 };			//Enemy Move Offset										ex) 3레벨 = LevelArray[0] + LevelArray[1] + LevelArray[2]

	static Bullet* plBltList[MAX_PLBULLET];		//Player Bullet List
	const POINT BltMvOffset = { 0,5 };			//Bullet Move Offset
	// speed = 5 라면 y축기준 +- 5 = (0,5), (0,-5)
	
	static int NowLevel = 1;					// 현재 레벨입니다.
	static POINT LineOffset[8];					// 레벨에 따른 몬스터 움직임의 시작점입니다.
	static POINT EnemyBulletOffset[8];			// 몬스터 움직임에 따른 총알 발사각도입니다.

	static int EnemyGen = 0;					// move타이머에서 젠되는 속도를 제한하기위한 변수입니다.
	static bool EndFlag = false;				// 종료시점을 체크하는 변수입니다.
	switch (iMessage) {
	case WM_CREATE:
		srand(time(NULL));
		SetRect(&rect, 0, 0, 800, 600);
		player = new Player(rect, PlayerBitmap);	// 플레이어 생성하는 구문입니다.
		MapPos_01 = 0;								// 배경이미지 1번은 초기값을 화면에 꽉차게
		MapPos_02 = 0 - rect.bottom;				// 배경이미지 2번은 초기값을 화면위쪽 안보이는 공간에 같은 사이즈로 그려주기위한 초기값입니다.

		// 레벨에 따라서 몬스터 움직임의 시작좌표값을 일일히 설정해 준것입니다.
		LineOffset[0] = { rect.right - 30, 50 };
		LineOffset[1] = { rect.right / 3, 10 };
		LineOffset[2] = { rect.left + 100, 10 };
		LineOffset[3] = { 10, rect.bottom / 2 };
		LineOffset[4] = { 10, rect.bottom - 100 };
		LineOffset[5] = { rect.right / 2 + 30, rect.bottom - 30 };
		LineOffset[6] = { rect.right - 130, rect.bottom - 30 };
		LineOffset[7] = { rect.right - 30, rect.bottom / 2 };
		// 몬스터 움직임에 따라 중앙방향으로 총알이 나가는것을 구현하기 위해서 증가값을 일일히 설정해 준것입니다.
		EnemyBulletOffset[0] = { 0, 5 };
		EnemyBulletOffset[1] = { 3, 2 };
		EnemyBulletOffset[2] = { 5, 0 };
		EnemyBulletOffset[3] = { 3,-2 };
		EnemyBulletOffset[4] = { 0,-5 };
		EnemyBulletOffset[5] = { -3,-2 };
		EnemyBulletOffset[6] = { -5,0 };
		EnemyBulletOffset[7] = { -3,2 };

		// 위에서 선언한 level 구조체의 초기화 하는 과정입니다.
		for (int i = 0; i < MAX_LEVEL; i++)
		{
			if (i % 2 == 0)
				LevelArray[i].Initialize(player, Enemybitmap[i % 4],
					EnemyBulletBitmap, EnemyBulletOffset[i], EnemyType::Enemy01, EnemyType::Enemy02);
			else if (i % 2 == 1)
				LevelArray[i].Initialize(player, Enemybitmap[i % 4],
					EnemyBulletBitmap, EnemyBulletOffset[i], EnemyType::Enemy03, EnemyType::Enemy04);
		}
		// 플레이어가 발사하는 총알의 리스트를 초기화하는 부분입니다.
		for (int i = 0; i < MAX_PLBULLET; i++)
			plBltList[i] = new Bullet(player->GetPos(), PlayerBulletBitmap, BltMvOffset);
		// 윈도우가 화면 중앙(?)에 오게끔 제 임의로 설정해주었습니다.
		MoveWindow(hWnd, 800, 200, rect.right, rect.bottom, TRUE);
		// 타이머 메시지 호출해서 게임 로직이 돌아갈수 있도록 해주는 부분입니다.
		SetTimer(hWnd, IDT_MAP_LOOP, 10, NULL);
		SetTimer(hWnd, IDT_PLAYER_MOVE, 10, NULL);
		SetTimer(hWnd, IDT_BULLET_MOVE, 10, NULL);
		SetTimer(hWnd, IDT_FIXED_UPDATE, 10, NULL);
		SetTimer(hWnd, IDT_ENEMY_MOVE, 30, NULL);
		SetTimer(hWnd, IDT_ENEMY_ANIMAITION, 500, NULL);
		return 0;
	case WM_GETMINMAXINFO:// 윈도우의 사이즈를 조정할수 없도록 제한하는 부분입니다.
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = rect.right;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = rect.right;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = rect.bottom;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = rect.bottom;
		break;
	case WM_TIMER:	// 게임 로직이 돌아가는 부분입니다.
		switch (wParam)
		{
		case IDT_FIXED_UPDATE:	// 충돌, 게임종료시점 체크와 같은 물리적인 일을 하는 타이머입니다.
			// 몬스터 총알과 플레이어 충돌 체크
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
			// 몬스터와 플레이어의 직접충돌 체크
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
			// 플레이어의 총알과 몬스터의 충돌을 체크하는 부분입니다.
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
			// 플레이어의 체력이 0이되면 바로 종료하고 뒤의 코드부분을 건너뛰기 위해 return 합니다.
			if (player->GetHP() <= 0)
			{
				EndFlag = true;
				return 0;
			}
			// 몬스터가 맞았는지의 여부에 따라 종료시점을 체크하는 부분입니다. 하나라도 안맞은 몬스터가 있다면 종료하지 않고 아래의 구문을 뛰어넘습니다.
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
			// 위의 조건들을 다 충족했을시 스테이지를 클리어 했다고 판단합니다.
			// 따라서 기존 레벨의 몬스터들의 초기값을 셋팅해줍니다.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					LevelArray[i].EnemyList[j]->SetHit(false);
					LevelArray[i].EnemyList[j]->Reset();
				}
			}
			
			EndFlag = true;
			NowLevel++; // 스테이지 클리어시 단계를 하나 높입니다.
			break;
		case IDT_MAP_LOOP:	// 배경이미지 루프를 위한 타이머입니다.
			MapPos_01 += MapLoopSpeed;
			MapPos_02 += MapLoopSpeed;
			if (MapPos_02 >= 0)
			{
				MapPos_01 = 0;
				MapPos_02 = 0 - rect.bottom;
			}
			break;
		case IDT_PLAYER_MOVE:	// 플레이어 이동을 위한 타이머입니다.
			player->PlayerMove();
			// 화면 바깥으로 나갈시 처음위치로 돌아옵니다.
			if (isOverClient(player->GetRect(), rect))
			{
				player->ResetPos();
				player->loseHP();
			}
			break;
		case IDT_BULLET_MOVE: // 몬스터, 플레이어의 총알의 이동을 위한 타이머입니다.
			// 플레이어 총알 이동하는 부분
			for (int i = 0; i < MAX_PLBULLET; i++)
			{
				plBltList[i]->BulletMove();
				if (isOverClient(plBltList[i]->Position, rect))
					plBltList[i]->isShoot = false;
			}
			// 몬스터 총알 이동하는 부분
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
			// Enemy generation 몬스터 생성 부분
			// 30 * 20 해서 600마다 한번 호출되게 했습니다.
			// 타이머를 더 생성하게 되면 프로그램이 멈춰버려서 이렇게 셋팅했습니다.
			if (EnemyGen++ >= 20) 
			{
				for (int i = 0; i < NowLevel; i++)
				{
					if (!LevelArray[i].EnemyList[LevelArray[i].GenCount]->IsVisable())
					{
						// 초기값을 설정해주는 부분입니다. 몬스터의 이미지를 회전시키고, 방향을 정해주고, 보이는 여부까지 셋팅해줍니다.
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->SetPos(LineOffset[i].x, LineOffset[i].y);
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->SetAngle(-90.0f + i * -45.0f);
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->
							SetIncrease(GetRotatedPos(EmyMvOffset.x, EmyMvOffset.y, LevelArray[i].EnemyList[LevelArray[i].GenCount]->GetAngle()));
						LevelArray[i].EnemyList[LevelArray[i].GenCount]->SetVisable(true);
						++LevelArray[i].GenCount;
						// 이부분도 마찬가지로 몬스터의 이동이 끝나지 않고 루프 하게끔 하는 부분입니다.
						if (LevelArray[i].GenCount >= MAX_ENEMY)
							LevelArray[i].GenCount = 0;
					}
				}
				EnemyGen = 0;
			}
			// Enemy Move 몬스터의 이동 부분입니다.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_ENEMY; j++)
				{
					if (LevelArray[i].EnemyList[j]->IsVisable())
					{
						LevelArray[i].EnemyList[j]->Move();
						// 플레이어와 마찬가지로 화면밖을 넘어갈시 셋팅해주는 부분입니다.
						if (isOverClient(LevelArray[i].EnemyList[j]->GetPos(), rect))
							LevelArray[i].EnemyList[j]->Reset();
					}
				}
			}
			// Enemy Shoot Bullet
			for (int i = 0; i < NowLevel; i++)
			{
				if (rand() % 100 <= 10 + 5 * NowLevel)	// 확률적으로 몬스터가 총알을 발사 할수 있게끔 셋팅해주는 부분입니다. 
				{										// 셋팅이 끝나면 MOVE타이머에서 총알이 이동합니다.
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
			
		case IDT_ENEMY_ANIMAITION:	// 몬스터의 애니메이션 효과를 구현해보고 싶었습니다. 시간마다 몬스터의 이미지를 바꿔주는것으로 해결했습니다.
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
		// 키설정 부분입니다.
		// 이부분에서 설정된 방향, 회전등에 의해 Move타이머에서 작동합니다.
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
		case 'S':	// s키를 누르면 총알을 발사합니다.
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
	case WM_KEYUP:	// 타이머에 의해 움직이기때문에 키UP을 했을때도 초기화를 해주어야 이동이 멈춤니다.
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
	case WM_PAINT:	// 가장 중요하다고 생각하는 PAINT 메시지 입니다.
		hdc = BeginPaint(hWnd, &ps);
		if (EndFlag)	// 종료시점이 되면 화면에 메시지를 출력합니다.
		{
			TCHAR tempString[20];
			if (player->GetHP() <= 0)	// 만약 HP가 0이라면 게임을 종료합니다.
				wsprintf(tempString, "You Lose!");
			else
				wsprintf(tempString, "Congratulation!");

			HFONT font = CreateFont(30, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, TEXT("궁서체"));	// 폰트를 설정해주고
			HFONT oldFont = (HFONT)SelectObject(hdc, font);
			SetTextColor(hdc, RGB(255, 255, 255));		// 글자의 색깔을 정해주고
			SetBkMode(hdc, TRANSPARENT);				// 글자의 배경색을 투명으로 설정한다음
			TextOut(hdc, rect.right/2 - lstrlen(tempString) / 5 * 30, 200, tempString, lstrlen(tempString));// 출력합니다.
			if (player->GetHP() > 0)	// HP가 0이 아니라면 클리어함으로 인해 몇스테이지를 클리어했는지 출력해줍니다.
			{
				font = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, TEXT("궁서체"));
				oldFont = (HFONT)SelectObject(hdc, font);
				TCHAR temp[20];
				wsprintf(temp, "Stage %d Clear!", NowLevel - 1);
				TextOut(hdc, rect.right / 2 - lstrlen(temp) / 5 * 20, 250, temp, lstrlen(temp));
			}
			SelectObject(hdc, oldFont);
			DeleteObject(font);
			Sleep(1000);	// 너무 빠르게 지나가지 않게 Sleep을 걸어주었습니다.
			if (player->GetHP() > 0)	// 클리어했을시 HP를 다시 셋팅해주고
			{
				player->SetHP(10);
				return 0;
			}
			else if (player->GetHP() <= 0)	// 클리어 하지 못했을시 프로그램을 종료하기 위헤 WM_DESTROY메시지를 hWnd에 보냅니다.
			{
				SendMessage(hWnd, WM_DESTROY, wParam, lParam);
			}
		}
		else		// 게임 로직에 의해 호출되는 부분입니다.
		{
			// Making DC 함수를 이용해서 코드를 줄여보았습니다. 워낙 코드가 길어지다 보니 정신이 없어서 줄였습니다.
			SettingDC(hdc, MemDC, MembackBitmap, OldMemBitmap, rect);
			SettingDC(MemDC, BACKDC, backBitmap, OldBackBitmap, rect);

			DrawBitmap(BACKDC, 0, 0, BackGroundBitmap);	// BACKDC에 배경이미지를 그리고

			GetObject(BackGroundBitmap, sizeof(BITMAP), &bit);
			bx = bit.bmWidth;
			by = bit.bmHeight;

			// Draw Map	StretchBlt를 이용하여 루프 하기위한 이미지를 두개 복사해옵니다.
			StretchBlt(MemDC, 0, MapPos_01, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);
			StretchBlt(MemDC, 0, MapPos_02, rect.right, rect.bottom, BACKDC, 0, 0, bx, by, SRCCOPY);

			// Draw Player (Rotate Realize)	외부에서 가져온 회전해서 그려주는 함수를 이용해서 그려줍니다.
			RotateBlt(hdc, BACKDC, 0, 0, player->GetWidth(), player->GetHeight(), player->GetImage(), 0, 0, SRCCOPY, player->GetAngle(), RGB(255, 255, 255)); // 더블버퍼링 기능을 제공하지 않기때문에 더블버퍼링을 하기위해 BACKDC에 글립니다.
			TransparentBlt(MemDC, player->GetPos().x, player->GetPos().y, player->GetWidth() * 1.5f, player->GetHeight() * 1.5f, BACKDC, 0, 0, player->GetWidth(), player->GetHeight(), RGB(255, 255, 255));
			// BACKDC를 MemDC에 그립니다. 후에 다시 hdc에 그려주어서 최종적으로 다중버퍼링을 구현합니다.

			// Draw Player Bullet 플레이어의 총알을 그려줍니다. 
			for (int i = 0; i < MAX_PLBULLET; i++)
			{
				if (plBltList[i]->isShoot == true)	// 리스트전부를 그리지 않게 제한을 걸어줍니다.
				{
					DrawBitmap(BACKDC, 0, 0, plBltList[i]->Img);	// 마찬가지로 더블버퍼링을 위해 BACKDC에 그려줍니다.
					TransparentBlt(MemDC, plBltList[i]->Position.x, plBltList[i]->Position.y, plBltList[i]->Width * 1.5f, plBltList[i]->Height * 1.5f,
						BACKDC, 0, 0, plBltList[i]->Width, plBltList[i]->Height, RGB(255, 255, 255));
				}
			}

			// 몬스터가 발사한 총알을 그려줍니다.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_EYBULLET; j++)
				{
					if (LevelArray[i].BulletList[j]->isShoot == true)
					{
						DrawBitmap(BACKDC, 0, 0, LevelArray[i].BulletList[j]->Img);	//.더블버퍼링을 위해 BACKDC에 그리고
						TransparentBlt(MemDC, LevelArray[i].BulletList[j]->Position.x, LevelArray[i].BulletList[j]->Position.y, LevelArray[i].BulletList[j]->Width * 1.5f, LevelArray[i].BulletList[j]->Height * 1.5f,
							BACKDC, 0, 0, LevelArray[i].BulletList[j]->Width, LevelArray[i].BulletList[j]->Height, RGB(255, 255, 255));	// 다시한번 버퍼링을 하기위해 MemDC에 옴김니다
					}
				}
			}

			// Draw Enemy (Rotate Realize) 몬스터를 그려줍니다.
			for (int i = 0; i < NowLevel; i++)
			{
				for (int j = 0; j < MAX_ENEMY; j++)
				{
					if (LevelArray[i].EnemyList[j]->IsVisable() && !LevelArray[i].EnemyList[j]->IsHit())	// bool변수를 이용해 플레이어와의 어떤 충돌로 인해 맞은 몬스터는 그리지 않게끔 설정합니다.
					{
						// 마찬가지로 버퍼링을 위해 그려줍니다.
						RotateBlt(hdc, BACKDC, 0, 0, LevelArray[i].EnemyList[j]->GetWidth(), LevelArray[i].EnemyList[j]->GetHeight(), LevelArray[i].EnemyList[j]->GetImage(), 0, 0, SRCCOPY, LevelArray[i].EnemyList[j]->GetAngle(), RGB(255, 255, 255));
						TransparentBlt(MemDC, LevelArray[i].EnemyList[j]->GetPos().x, LevelArray[i].EnemyList[j]->GetPos().y, LevelArray[i].EnemyList[j]->GetWidth() * 1.5f, LevelArray[i].EnemyList[j]->GetHeight() * 1.5f, BACKDC, 0, 0, LevelArray[i].EnemyList[j]->GetWidth(), LevelArray[i].EnemyList[j]->GetHeight(), RGB(255, 255, 255));
					}
				}
			}

			// 모든 내용을 MemDC에 복사 했는데 이걸 마지막에 한번에 hdc에 복사함으로써 다중버퍼링을 구현했습니다.
			BitBlt(hdc, 0, 0, rect.right, rect.bottom, MemDC, 0, 0, SRCCOPY);

			// Delete DC
			RemovingDC(BACKDC, backBitmap, OldBackBitmap);
			RemovingDC(MemDC, MembackBitmap, OldMemBitmap);
		}
		
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		// 종료시 동적할당 해제및 타이머 해제하는 부분입니다.
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

