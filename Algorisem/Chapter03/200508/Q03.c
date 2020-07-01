#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Q3 배열 a에서 key와 일치하는 모든요소의 인덱스를 배열 idx에 저장하고 요소의 개수를 반환하는 함수 작성

int search_index(const int a[], int n, int key, int idx[])
{
	int i;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == key)
			idx[j++] = i;
	}
	return j;
}
int main(void)
{
	int i, nx, ky;
	int count = 0;
	int* x;
	int* idx;
	srand(time(NULL));

	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	idx = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		x[i] = rand() % 10;
		printf("x[%d] : %d\n", i, x[i]);
	}

	printf("검색 값 : ");
	scanf_s("%d", &ky);
	
	count = search_index(x, nx, ky, idx);

	putchar('\n');

	if (count == 0)
		puts("검색에 실패 했습니다.");
	else
	{
		printf("일치하는 요소는 %d개 입니다.\n", count);
		for (int i = 0; i < count; i++)
		{
			printf("  x[%d]", idx[i]);
		}
		putchar('\n');

	}

	free(idx);
	free(x);
	return 0;

}


