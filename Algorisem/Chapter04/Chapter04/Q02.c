#include <stdio.h>
#include "Stack.h"

int main(void)
{
	IntStack s;
	if (Initialaze(&s, 10) == -1)
	{
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}
	int player;
	printf("�÷��̾� ���� ( 1 or 2 ) : ");
	scanf_s("%d", &player);
	while (1)
	{
		int menu, x;
		
		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)ã�� (6)���� (7)���� ���� (9)�÷��̾� ���� (0)���� : ");
		scanf_s("%d", &menu);

		if (menu == 0)
			break;
		int pos = 0;
		switch (menu)
		{
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (player == 1)
			{
				if (fPush(&s, x) == -1)
					puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			}
			else if(player == 2)
			{
				if (rPush(&s, x) == -1)
					puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			}
			
			break;
		case 2:
			if (player == 1)
			{
				if (fPop(&s, &x) == -1)
					puts("\a���� : �˿� �����Ͽ����ϴ�.");
				else
					printf("�� �����ʹ� %d�Դϴ�.\n", x);
			}
			else if (player == 2)
			{
				if (rPop(&s, &x) == -1)
					puts("\a���� : �˿� �����Ͽ����ϴ�.");
				else
					printf("�� �����ʹ� %d�Դϴ�.\n", x);
			}
			
			break;
		case 3:
			if (player == 1)
			{
				if (fPeek(&s, &x) == -1)
					puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
				else
					printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			}
			else if (player == 2)
			{
				if (rPeek(&s, &x) == -1)
					puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
				else
					printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			}
			
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			printf("������ : ");
			scanf_s("%d", &x);
			if (player == 1)
			{
				pos = fSearch(&s, x);
				if (pos == -1)
					puts("\a���� : ã�⿡ �����Ͽ����ϴ�.");
				else
					printf("ã�� �����ʹ� %d�� �ֽ��ϴ�.\n", pos);
			}
			else if (player == 2)
			{
				pos = rSearch(&s, x);
				if (pos == -1)
					puts("\a���� : ã�⿡ �����Ͽ����ϴ�.");
				else
					printf("ã�� �����ʹ� %d�� �ֽ��ϴ�.\n", pos);
			}
			
			break;
		case 6:
			Clear(&s);
			break;
		case 7:
			if (IsEmpty(&s))
				puts("������ ����ֽ��ϴ�.");
			else if (IsFull(&s))
				puts("������ ���� �� �ֽ��ϴ�.");
			else
				printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
			break;
		case 9:
			printf("�÷��̾� ���� ( 1 or 2 ) : ");
			scanf_s("%d", &player);
			break;
		default:
			break;
		}
	}
	Teminate(&s);
	return 0;
}