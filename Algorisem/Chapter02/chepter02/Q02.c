#include <stdio.h>
#include <stdlib.h>

//Q2 Ű�� �հ踦 ���ϴ� �Լ� ����

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

	printf("��� �� : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���.\n", number);
	for (int i = 0; i < number; i++)
	{
		printf("%d ��° ��� : ", i + 1);
		scanf_s("%d", &height[i]);
	}
	printf("���� : %d\n", sumof(height, number));
	free(height);

	return 0;
}