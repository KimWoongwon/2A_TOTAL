#include <stdio.h>
//Q18 n���� ���Ƕ�̵带 ����ϴ� �Լ� �ۼ�

void nrpira(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i-1; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= (n - i) * 2 + 1; j++)
		{
			printf("%d",i%10);
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

		nrpira(num);
	} while (num >= 0);


	return 0;
}