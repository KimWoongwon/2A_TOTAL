#include <stdio.h>
#include "Queue.h"

int main(void)
{
	IntQueue q;
	if (Initialaze(&q, 64) == -1)
	{
		puts("ť ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("���� ������ �� : %d / %d\n", Size(&q), Capacity(&q));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)ã�� (6)���� (7)ť ���� (0)���� : ");
		scanf_s("%d", &menu);

		if (menu == 0)
			break;
		int pos = 0;
		switch (menu)
		{
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Enque(&q, x) == -1)
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			break;
		case 2:
			if (Deque(&q, &x) == -1)
				puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			else
				printf("��ť �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 3:
			if (Peek(&q, &x) == -1)
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4:
			Print(&q);
			break;
		case 5:
			printf("������ : ");
			scanf_s("%d", &x);
			pos = Search(&q, x);
			if (pos == -1)
				puts("\a���� : ã�⿡ �����Ͽ����ϴ�.");
			else
				printf("ã�� �����ʹ� %d�� �ֽ��ϴ�.\n", pos);
			break;
		case 6:
			Clear(&q);
			break;
		case 7:
			if (IsEmpty(&q))
				puts("ť�� ����ֽ��ϴ�.");
			else if (IsFull(&q))
				puts("ť�� ���� �� �ֽ��ϴ�.");
			else
				printf("���� ������ �� : %d / %d\n", Size(&q), Capacity(&q));
		default:
			break;
		}
	}
	Teminate(&q);
	return 0;
}