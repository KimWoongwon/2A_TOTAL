#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Q3 ��� ���� Ű�� ������ �������� �ִ밪�� ���ϴ� ���α׷�

int maxof(const int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int main(void)
{
	int* height;
	int number;

	srand(time(NULL));

	number = 5 + rand() % 16;
	printf("��� �� : %d\n", number);

	height = calloc(number, sizeof(int));
	for (int i = 0; i < number; i++)
	{
		height[i] = 100 + rand() % 90;
		printf("height[%d] : %d\n", i, height[i]);
	}
	printf("�ִ밪 : %d\n", maxof(height, number));
	free(height);

	return 0;
}