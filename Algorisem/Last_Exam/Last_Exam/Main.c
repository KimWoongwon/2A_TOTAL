#include "Global.h"
#include "ChainHash.h"

ChainHash hash;

// 해시테이블 초기화 부분
void HashTable()
{
	int result;
	DATA data;
	data = DataSetting(0, ' ');
	result = Add(&hash, &data);

	data = DataSetting(1, '|');
	result = Add(&hash, &data);
	data = DataSetting(2, '_');
	result = Add(&hash, &data);
	data = DataSetting(9, '\n');
	result = Add(&hash, &data);

	data = DataSetting(3, 'A');
	result = Add(&hash, &data);
	data = DataSetting(4, '!');
	result = Add(&hash, &data);

	int Array[7] = { 5,0,3,6,2,4,1 };
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		data = DataSetting(5 + hash.size * i, Array[i] + '1');
		result = Add(&hash, &data);
	}
}

void GotoPrint(const char* message, int x, int y)
{
	gotoxy(x, y);
	printf("%s", message);
}

int main(void)
{
	Initialize(&hash, 10);
	srand(time(NULL));

	HashTable();

	// 0 : empty, 1 : wall, 2 : floor,  9 : \n, 3 : player, 4 : Bullet, 5 : enemy
	int Map[MAPSIZE_Y][MAPSIZE_X] =
	{
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,1,9},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9},
		{1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,9}
	};
	
	int playerPos_x = 11;
	int playerPos_y = 12;
	int DrawXpos = 30;
	int DrawYpos = 1;
	Node* HitObj;
	BOOL HitCheck = FALSE;	// bool 1 = true; 0 = false;
	int HitXpos = 0;
	int HitYpos = 0;
	int HitCount = 0;
	BOOL EndFlag = TRUE;

	// 몬스터 위치 설정
	for (int i = 0; i < 7; i++)
	{
		int Y = rand() % 4 + 1;
		int X = rand() % 20 + 1;
		if (Map[Y][X] == 0)
		{
			Map[Y][X] = 5 + i * hash.size;
		}
		else
		{
			i--;
		}
	}

	printf("Move : ↑ ↓ ← →\n");
	printf("Shoot : Space bar");
	Sleep(3000);
	int key;
	while (EndFlag)
	{
		CursorView(0);
		gotoxy(0, 0);
		// 게임 로직 -> 맵을 계속 바꿔가며 그려주는 형식으로 구현했습니다.
		for (int y = 0; y < MAPSIZE_Y; y++)
		{
			for (int x = 0; x < MAPSIZE_X; x++)
			{
				Node* temp = Search(&hash, Map[y][x]);
				if (Map[y][x] == 4)
				{
					printf("%c", temp->data.ch);
					if (Map[y - 1][x] == 0)
					{
						Swap(Map[y][x], Map[y - 1][x], int);
					}
					else if(Map[y - 1][x] != 0)
					{ 
						Map[y][x] = 0;
						if (y - 1 < 0)
							continue;
						if (Map[y - 1][x] % 5 == 0)
						{
							HitCheck = 1;
							HitObj = temp;
							HitXpos = x;
							HitYpos = y - 1;
						}
					}
				}
				else
					printf("%c", temp->data.ch);
			}
		}

		// 종료시점 체크
		if (HitCount >= ENEMY_COUNT)
		{
			gotoxy(3, 9);
			printf("Congratulation!!");
			gotoxy(7, 10);
			printf("You Win!");
			_getch();
			EndFlag = FALSE;
		}
		
		// 해시 출력
		GotoPrint("Hash table!",DrawXpos, 0);
		gotoxy(DrawXpos, DrawYpos);
		Dump(&hash, DrawXpos, &DrawYpos);
		DrawXpos = 30;
		DrawYpos = 1;

		// 충돌 처리 부분 -> 충돌처리 되면서 잠깐 멈출때 해시정보 확인해보면 사라지는것을 볼수 있습니다.
		if (HitCheck)
		{
			gotoxy(9, 9);
			printf("HIT!!");
			gotoxy(7, 8);
			printf("REMOVE!!!");
			gotoxy(9, 7);
			printf("HIT!!");

			HitObj = Search(&hash, Map[HitYpos][HitXpos]);
			Remove(&hash, &HitObj->data);
			Map[HitYpos][HitXpos] = 0;
			Sleep(500);
			++HitCount;
			HitCheck = FALSE;
		}

		system("cls");

		
#pragma region Input Keys
		int temp;
		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case 72:	//UP
					if (Map[playerPos_y - 1][playerPos_x] == 0)
					{
						Swap(Map[playerPos_y][playerPos_x], Map[playerPos_y - 1][playerPos_x], int);
						--playerPos_y;
					}
					break;
				case 80:	//DOWN
					if (Map[playerPos_y + 1][playerPos_x] == 0)
					{
						Swap(Map[playerPos_y][playerPos_x], Map[playerPos_y + 1][playerPos_x], int);
						++playerPos_y;
					}
					break;
				case 75:	//LEFT
					if (Map[playerPos_y][playerPos_x - 1] == 0)
					{
						Swap(Map[playerPos_y][playerPos_x], Map[playerPos_y][playerPos_x - 1], int);
						--playerPos_x;
					}
					break;
				case 77:	//RIGHT
					if (Map[playerPos_y][playerPos_x + 1] == 0)
					{
						Swap(Map[playerPos_y][playerPos_x], Map[playerPos_y][playerPos_x + 1], int);
						++playerPos_x;
					}
					break;
				}
			}
			else
			{
				if (key == 32)
					Map[playerPos_y - 1][playerPos_x] = 4;
			}

		}
#pragma endregion 방향키 및 스페이스바 입력처리

		
		
	}
	Terminate(&hash);
}