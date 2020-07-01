#include <stdio.h>
#include "Stack.h"

int main(void)
{
	IntStack s;
	if (Initialaze(&s, 10) == -1)
	{
		puts("스텍 생성에 실패하였습니다.");
		return 1;
	}
	int player;
	printf("플레이어 선택 ( 1 or 2 ) : ");
	scanf_s("%d", &player);
	while (1)
	{
		int menu, x;
		
		printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)찾기 (6)비우기 (7)스택 상태 (9)플레이어 변경 (0)종료 : ");
		scanf_s("%d", &menu);

		if (menu == 0)
			break;
		int pos = 0;
		switch (menu)
		{
		case 1:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (player == 1)
			{
				if (fPush(&s, x) == -1)
					puts("\a오류 : 푸시에 실패하였습니다.");
			}
			else if(player == 2)
			{
				if (rPush(&s, x) == -1)
					puts("\a오류 : 푸시에 실패하였습니다.");
			}
			
			break;
		case 2:
			if (player == 1)
			{
				if (fPop(&s, &x) == -1)
					puts("\a오류 : 팝에 실패하였습니다.");
				else
					printf("팝 데이터는 %d입니다.\n", x);
			}
			else if (player == 2)
			{
				if (rPop(&s, &x) == -1)
					puts("\a오류 : 팝에 실패하였습니다.");
				else
					printf("팝 데이터는 %d입니다.\n", x);
			}
			
			break;
		case 3:
			if (player == 1)
			{
				if (fPeek(&s, &x) == -1)
					puts("\a오류 : 피크에 실패하였습니다.");
				else
					printf("피크 데이터는 %d입니다.\n", x);
			}
			else if (player == 2)
			{
				if (rPeek(&s, &x) == -1)
					puts("\a오류 : 피크에 실패하였습니다.");
				else
					printf("피크 데이터는 %d입니다.\n", x);
			}
			
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (player == 1)
			{
				pos = fSearch(&s, x);
				if (pos == -1)
					puts("\a오류 : 찾기에 실패하였습니다.");
				else
					printf("찾는 데이터는 %d에 있습니다.\n", pos);
			}
			else if (player == 2)
			{
				pos = rSearch(&s, x);
				if (pos == -1)
					puts("\a오류 : 찾기에 실패하였습니다.");
				else
					printf("찾는 데이터는 %d에 있습니다.\n", pos);
			}
			
			break;
		case 6:
			Clear(&s);
			break;
		case 7:
			if (IsEmpty(&s))
				puts("스택이 비어있습니다.");
			else if (IsFull(&s))
				puts("스택이 가득 차 있습니다.");
			else
				printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
			break;
		case 9:
			printf("플레이어 선택 ( 1 or 2 ) : ");
			scanf_s("%d", &player);
			break;
		default:
			break;
		}
	}
	Teminate(&s);
	return 0;
}