#include <stdio.h>
//Q17 n단의 피라미드를 출력하는 함수 작성

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
		printf("몇단 피라미드 입니까 : ");
		scanf_s("%d", &num);

		spira(num);
	} while (num >= 0);
	

	return 0;
}