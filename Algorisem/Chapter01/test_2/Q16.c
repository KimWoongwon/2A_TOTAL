#include <stdio.h>
//Q16 �����̵�ﰢ���� ����ϴ� �Լ� �����

void triangleLB(int n) // ���� �Ʒ�
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void triangleLU(int n) // ���� ��
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j >= i; j--)
		{
			printf("*");
		}
		printf("\n");
	}
}
void triangleRB(int n) // ������ �Ʒ�
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(j > n - i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void triangleRU(int n) // ������ ��
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j > n - i +1)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}
int main(void)
{
	int num;
	printf("��� �ﰢ�� �Դϱ� : ");
	scanf_s("%d", &num);

	//triangleLB(num);
	//triangleLU(num);
	//triangleRB(num);
	triangleRU(num);

	return 0;
}
