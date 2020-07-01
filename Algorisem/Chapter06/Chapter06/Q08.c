#include <stdio.h>
#include <stdlib.h>
//Q08 단순삽입정렬의 과정을 보여주는 프로그램 작성
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

	puts("단순 삽입 정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	Insertion(x, nx);
	puts("오름차순으로 정렬했습니다.");

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}