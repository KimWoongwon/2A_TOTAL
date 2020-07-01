#include <stdio.h>
#include <stdlib.h>

//Q3 키의 평균을 구하는 함수 정의

double aveof(const int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	
	return sum / n;
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
	printf("평균값 : %.2f\n", aveof(height, number));
	free(height);

	return 0;
}