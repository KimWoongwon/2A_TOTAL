#include <stdio.h>
//Q14 입력한 수를 한변으로 하는 정사각형 *기호로 출력
int main(void)
{
	int num;
	printf("사각형을 출력합니다.\n");

	printf("입력할 수 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
