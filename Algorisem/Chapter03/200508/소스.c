#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//chapter 03

int bin_search(const int a[], int n, int key)
{
	int pl = 0;
	int pr = n - 1;
	int pc;
	do
	{
		pc = (pl + pr) / 2;
		if (a[pc] == key)
			return pc;
		else if (a[pc] < key)
			pl = pc + 1;
		else 
			pr = pc - 1;
	} while (pl <= pr);
	return -1;
}

int search(int a[], int n, int key)
{
	int i = 0;
	a[n] = key;
	while (1)
	{
		if (a[i] == key)
			break;
		i++;
	}
	return i == n ? -1 : i;
}
int main(void)
{
	int i, nx, ky, idx, random;
	int* x;

	puts("���� �˻�");
	//puts("���� �˻�");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = calloc(nx, sizeof(int));
	//x = calloc(nx + 1, sizeof(int));
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
	//idx = search(x, nx, ky);
	if (idx == -1)
		puts("�˻��� ���� �߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
	free(x);
	return 0;

}


