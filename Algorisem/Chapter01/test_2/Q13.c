#include <stdio.h>
//Q13 µ¡¼ÀÇ¥ ÀÛ¼º
int main(void)
{
	
	//Q13 µ¡¼ÀÇ¥ ÀÛ¼º
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