#include "IntStack.h"
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void quick(int a[], int left, int right)
{
	IntStack lstack;
	IntStack rstack;

	Initialize(&lstack, right - left + 1);
	Initialize(&rstack, right - left + 1);

	
	Push(&lstack, left);
	Push(&rstack, right);
	/*puts("--------------------------------------------------------");
	printf("���ÿ��� ���� �迭�� ������ a[%d] ~ a[%d] �Դϴ�.\n", left, right);
	puts("--------------------------------------------------------");*/
	printf("\na[%d] ~ a[%d]�� ���ÿ� Ǫ�� �մϴ�.\n", left, right);
	printf("LStack : "); Print(&lstack);
	printf("RStack : "); Print(&rstack);

	while (!IsEmpty(&lstack))
	{

		int pl = (Pop(&lstack, &left), left);
		int pr = (Pop(&rstack, &right), right);
		int x = a[(left + right) / 2];
		puts("--------------------------------------------------------");
		printf("���ÿ��� ���� �迭�� ������ a[%d] ~ a[%d] �Դϴ�.\n", left, right);
		puts("--------------------------------------------------------");
		
		do
		{
			while (a[pl] < x) pl++;
			while (a[pr] > x) pr--;
			if (pl <= pr)
			{
				swap(int, a[pl], a[pr]);
				pl++;
				pr--;
			}
		} while (pl<=pr);
		
		if (left < pr)
		{
			Push(&lstack, left);
			Push(&rstack, pr);
			printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ�� �մϴ�.\n", left, pr);
			printf("LStack : "); Print(&lstack);
			printf("RStack : "); Print(&rstack);
		}
		if (pl < right)
		{
			Push(&lstack, pl);
			Push(&rstack, right);
			printf("a[%d] ~ a[%d]�� ���ÿ� Ǫ�� �մϴ�.\n", pl, right);
			printf("LStack : "); Print(&lstack);
			printf("RStack : "); Print(&rstack);
		}
	
		
	}
	Terminate(&lstack);
	Terminate(&rstack);
	
}
int main(void)
{
	int i, nx;
	int* x;

	puts("�迭�� �����ϴ�.");
	printf("��� ���� : ");
	scanf_s("%d", &nx);

	x = (int*)calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	quick(x, 0, nx-1);

	printf("\n������������ �����߽��ϴ�.\n");
	for (int i = 0; i < nx; i++)
	{
		printf("x[%d] = %d\n", i, x[i]);
	}

	free(x);

	return 0;
}