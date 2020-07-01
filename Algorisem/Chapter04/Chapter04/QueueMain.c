#include <stdio.h>
#include "Queue.h"

int main(void)
{
	IntQueue q;
	if (Initialaze(&q, 64) == -1)
	{
		puts("큐 생성에 실패하였습니다.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("현재 데이터 수 : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)찾기 (6)비우기 (7)큐 상태 (0)종료 : ");
		scanf_s("%d", &menu);

		if (menu == 0)
			break;
		int pos = 0;
		switch (menu)
		{
		case 1:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Enque(&q, x) == -1)
				puts("\a오류 : 인큐에 실패하였습니다.");
			break;
		case 2:
			if (Deque(&q, &x) == -1)
				puts("\a오류 : 디큐에 실패하였습니다.");
			else
				printf("디큐 데이터는 %d입니다.\n", x);
			break;
		case 3:
			if (Peek(&q, &x) == -1)
				puts("\a오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 4:
			Print(&q);
			break;
		case 5:
			printf("데이터 : ");
			scanf_s("%d", &x);
			pos = Search(&q, x);
			if (pos == -1)
				puts("\a오류 : 찾기에 실패하였습니다.");
			else
				printf("찾는 데이터는 %d에 있습니다.\n", pos);
			break;
		case 6:
			Clear(&q);
			break;
		case 7:
			if (IsEmpty(&q))
				puts("큐가 비어있습니다.");
			else if (IsFull(&q))
				puts("큐가 가득 차 있습니다.");
			else
				printf("현재 데이터 수 : %d / %d\n", Size(&q), Capacity(&q));
		default:
			break;
		}
	}
	Teminate(&q);
	return 0;
}