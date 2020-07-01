#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)
//Q05s 버전3를 교환 과정을 자세히 출력하는 프로그램작성
void bubble(int a[], int n)
{
	int ccnt = 0;
	int scnt = 0;
	puts("----------------------------------");
	int k = 0;
	while (k < n - 1)
	{
		int last = n - 1;
		printf("Pass %d : \n", k + 1);
		for (int j = n - 1; j > k; j--)
		{
			for (int m = 0; m < n - 1; m++)
				printf("%3d %c", a[m], (m != j - 1) ? ' ' : (a[j - 1] > a[j]) ? '+' : '-');

			printf("%3d\n", a[n - 1]);
			ccnt++;
			if (a[j - 1] > a[j])
			{
				swap(int, a[j - 1], a[j]);
				scnt++;
				last = j;
			}
			
		}
		k = last;
		printf("Pass %d Result : \n", k + 1);
		for (int m = 0; m < n; m++)
			printf("%3d  ", a[m]);
		putchar('\n');
		puts("----------------------------------");
	}

	printf("Compare : %d\n", ccnt);
	printf("Change : %d\n", scnt);
}

int main(void)
{
	int i, nx;
	int* x;

	puts("버블정렬");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);

	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	bubble(x, nx);
	puts("오름차순으로 정렬했습니다.");

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}