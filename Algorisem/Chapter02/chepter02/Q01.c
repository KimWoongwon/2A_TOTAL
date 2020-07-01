#include <stdio.h>
#include <stdlib.h>

//Q1 키의 최소값을 구하는 함수 정의

int minheight(const int a[], int n)
{
	int min = a[0];
	for(int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
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
		printf("%d번째 사람 : ", i+1);
		scanf_s("%d", &height[i]);
	}
	printf("최소값 : %d\n", minheight(height, number));
	free(height);

	return 0;
}