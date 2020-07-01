#include <stdio.h>
#include "Stack.h"

int main(void)
{
	IntStack s;
	if (Initialaze(&s, 64) == -1)
	{
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)ã�� (6)���� (7)���� ���� (0)���� : ");
		scanf_s("%d", &menu);

		if (menu == 0)
			break;
		int pos = 0;
		switch (menu)
		{
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			break;
		case 2:
			if (Pop(&s, &x) == -1)
				puts("\a���� : �˿� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 3:
			if(Peek(&s, &x) == -1)
				puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			printf("������ : ");
			scanf_s("%d", &x);
			pos = Search(&s, x);
			if (pos == -1)
				puts("\a���� : ã�⿡ �����Ͽ����ϴ�.");
			else
				printf("ã�� �����ʹ� %d�� �ֽ��ϴ�.\n", pos);
			break;
		case 6:
			Clear(&s);
			break;
		case 7:
			if(IsEmpty(&s))
				puts("������ ����ֽ��ϴ�.");
			else if(IsFull(&s))
				puts("������ ���� �� �ֽ��ϴ�.");
			else
				printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		default:
			break;
		}
	}
	Teminate(&s);
	return 0;
}