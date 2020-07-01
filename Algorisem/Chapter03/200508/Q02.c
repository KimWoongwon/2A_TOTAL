#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Q2 그림과 같이 선형검색의 스캐닝과정을 표시하는 프로그램 작성

int search(const int a[], int n, int key)
{
	int i;
	printf("   |");
	for (i = 0; i < n; i++)
		printf("%3d", i);
	printf("\n---+");
	for (i = 0; i < n; i++)
		printf("---");
	printf("-\n");
	for (i = 0; i < n; i++)
	{
		int j;
		printf("   |");
		printf("%*s", 3 * (i - 1) + 5, "");
		printf("*\n");
		printf("%3d|", i);
		for (j = 0; j < n; j++)
			printf("%3d", a[j]);
		putchar('\n');
		if (a[i] == key)
			return i;
		printf("   |\n");
	}
	return -1;
}
int main(void)
{
	int i, nx, ky, idx, random;
	int* x;
	srand(time(NULL));

	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		x[i] = rand() % 100;
		printf("x[%d] : %d\n", i, x[i]);
	}

	printf("검색 값 : ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	putchar('\n');

	if (idx == -1)
		puts("검색에 실패 했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);

	free(x);
	return 0;

}


