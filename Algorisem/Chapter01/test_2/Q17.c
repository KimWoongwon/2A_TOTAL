#include <stdio.h>
//Q17 n���� �Ƕ�̵带 ����ϴ� �Լ� �ۼ�

void spira(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= (i - 1) * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main(void)
{
	int num;
	do 
	{
		printf("��� �Ƕ�̵� �Դϱ� : ");
		scanf_s("%d", &num);

		spira(num);
	} while (num >= 0);
	

	return 0;
}