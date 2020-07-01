#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Q4 ������ �׸�ó�� ���� �˻��� ������ �ڼ��� ����ϴ� ���α׷� �ۼ�

int bin_search(const int a[], int n, int key)
{
	int i , k = 1;
	int pl = 0;
	int pr = n - 1;
	int pc;
	printf("   |");
	for (i = 0; i < n; i++)
		printf("%4d", i);
	printf("\n---+");
	for (i = 0; i < n; i++)
		printf("---");
	printf("--\n");
	do
	{
		pc = (pl + pr) / 2;
		printf("   |");
		for (int i = 0; i < pl*4; i++)
			printf(" ");
		printf("  <");
		for (int i = 0; i < (pc-pl) * 4; i++)
			printf(" ");
		printf("+");
		for (int i = 0; i < (pr - pc) * 4 - 2; i++)
			printf(" ");
		printf(" >\n");
		
		printf("%3d|", k);
		for (int j = 0; j < n; j++)
		{
			printf("%4d", a[j]);
		}
		putchar('\n');
		
		if (a[pc] == key)
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else
			pr = pc - 1;
		k++;
	} while (pl <= pr);
	return -1;
}

int main(void)
{
	int i, nx, ky, idx, random;
	int* x;	

	puts("���� �˻�");

	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));

	printf("������������ �Է��ϼ���.\n");
	printf("x[0] : ");
	scanf_s("%d", &x[0]);

	for (i = 1; i < nx; i++)
	{
		do
		{
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	printf("�˻� �� : ");
	scanf_s("%d", &ky);
	idx = bin_search(x, nx, ky);

	if (idx == -1)
		puts("�˻��� ���� �߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
	free(x);
	return 0;

}


