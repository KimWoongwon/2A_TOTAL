#include <stdio.h>
//Q12 ����ǥ �ۼ�
int main(void)
{
	//Q12 ����ǥ �ۼ�
	printf("\n   |");
	for (int i = 1; i <= 9; i++)
	{
		printf("%3d", i);
	}
	printf("\n---+-----------------------------\n");
	for (int i = 1; i <= 9; i++)
	{
		printf("%2d |", i);
		for (int j = 1; j <= 9; j++)
		{
			//printf("%2d |", i);
			printf("% 3d", i * j);
		}
		printf("\n");
	}

	//Q13 ����ǥ �ۼ�
	printf("\n   |");
	for (int i = 1; i <= 9; i++)
	{
		printf("%3d", i);
	}
	printf("\n---+-----------------------------\n");
	for (int i = 1; i <= 9; i++)
	{
		printf("%2d |", i);
		for (int j = 1; j <= 9; j++)
		{
			//printf("%2d |", i);
			printf("% 3d", i + j);
		}
		printf("\n");
	}

	return 0;
}