#include <stdio.h>
//Q18 n단의 역피라미드를 출력하는 함수 작성

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
		printf("몇단 피라미드 입니까 : ");
		scanf_s("%d", &num);

		nrpira(num);
	} while (num >= 0);


	return 0;
}