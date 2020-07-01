#include <stdio.h>
#include <stdlib.h>

//Q3 Ű�� ����� ���ϴ� �Լ� ����

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

	printf("��� �� : ");
	scanf_s("%d", &number);
	height = calloc(number, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���.\n", number);
	for (int i = 0; i < number; i++)
	{
		printf("%d ��° ��� : ", i + 1);
		scanf_s("%d", &height[i]);
	}
	printf("��հ� : %.2f\n", aveof(height, number));
	free(height);

	return 0;
}