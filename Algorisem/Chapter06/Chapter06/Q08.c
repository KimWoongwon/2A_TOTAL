#include <stdio.h>
#include <stdlib.h>
//Q08 �ܼ����������� ������ �����ִ� ���α׷� �ۼ�
void Insertion(int a[], int n)
{
	int j;
	for (int i = 1; i < n; i++)
	{

		int temp = a[i];
		for (int m = 0; m < n; m++)
			printf("%3d  ", a[m]);
		putchar('\n');
		
		for (j = i; j > 0 && a[j - 1] > temp; j--)
			a[j] = a[j - 1];
		for (int m = 0; m < n; m++)
		{
			if (m == j)
				printf("  ^");
			else if (m == i)
				printf("----+");
			else if (m > j && m < i)
				printf("-----");
			else
				printf("     ");
		}
		putchar('\n');
		a[j] = temp;
		
	}
	printf("Result : \n");
	for (int m = 0; m < n; m++)
		printf("%3d  ", a[m]);
	putchar('\n');
	putchar('\n');
}

int main(void)
{
	int i, nx;
	int* x;

	puts("�ܼ� ���� ����");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	Insertion(x, nx);
	puts("������������ �����߽��ϴ�.");

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}