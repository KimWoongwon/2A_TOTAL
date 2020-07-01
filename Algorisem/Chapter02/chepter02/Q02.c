#include <stdio.h>
#include <stdlib.h>

//Q2 키의 합계를 구하는 함수 정의

int sumof(const int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}

int main(void)
{
	int* height;
	int number;

	printf("사람 수 : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	printf("%d 사람의 키를 입력하세요.\n", number);
	for (int i = 0; i < number; i++)
	{
		printf("%d 번째 사람 : ", i + 1);
		scanf_s("%d", &height[i]);
	}
	printf("총합 : %d\n", sumof(height, number));
	free(height);

	return 0;
}