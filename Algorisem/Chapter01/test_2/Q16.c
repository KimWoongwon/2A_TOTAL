#include <stdio.h>
//Q16 직각이등변삼각형을 출력하는 함수 만들기

void triangleLB(int n) // 왼쪽 아래
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
void triangleLU(int n) // 왼쪽 위
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
void triangleRB(int n) // 오른쪽 아래
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
void triangleRU(int n) // 오른쪽 위
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
	printf("몇단 삼각형 입니까 : ");
	scanf_s("%d", &num);

	//triangleLB(num);
	//triangleLU(num);
	//triangleRB(num);
	triangleRU(num);

	return 0;
}
