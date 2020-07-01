#include <stdio.h>
#include <stdlib.h>

//Q1 Ű�� �ּҰ��� ���ϴ� �Լ� ����

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

	printf("��� �� : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���.\n", number);
	for (int i = 0; i < number; i++)
	{
		printf("%d��° ��� : ", i+1);
		scanf_s("%d", &height[i]);
	}
	printf("�ּҰ� : %d\n", minheight(height, number));
	free(height);

	return 0;
}