#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Q3 �迭 a���� key�� ��ġ�ϴ� ������� �ε����� �迭 idx�� �����ϰ� ����� ������ ��ȯ�ϴ� �Լ� �ۼ�

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

	puts("���� �˻�");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	idx = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		x[i] = rand() % 10;
		printf("x[%d] : %d\n", i, x[i]);
	}

	printf("�˻� �� : ");
	scanf_s("%d", &ky);
	
	count = search_index(x, nx, ky, idx);

	putchar('\n');

	if (count == 0)
		puts("�˻��� ���� �߽��ϴ�.");
	else
	{
		printf("��ġ�ϴ� ��Ҵ� %d�� �Դϴ�.\n", count);
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


