#include <stdio.h>
//Q15 높이 넓이를 받아 *기호로 직사각형 출력하기
int main(void)
{
	int w,h;
	printf("사각형을 출력합니다.\n");

	printf("높이 : ");
	scanf_s("%d", &h);
	printf("넓이 : ");
	scanf_s("%d", &w);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
