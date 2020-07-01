#include <stdio.h>
#include <stdlib.h>

//Q5 �迭�� �������� �����ϴ� ������ ������ ����ϴ� ���α׷� �ۼ�

void display_all(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
	putchar('\n');
	putchar('\n');
}

void ary_reverse(int a[], int n)
{
	int temp;

	for (int i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
		printf("a[%d] �� a[%d]�� ��ȯ�մϴ�.\n", i, n-i-1);
		display_all(a, n);
	}
}

int main(void)
{
	int* Arr;
	int size;

	printf("��� ���� : ");
	scanf_s("%d", &size);
	Arr = calloc(size, sizeof(int));

	printf("%d���� ������ �Է��ϼ���. \n", size);
	for (int i = 0; i < size; i++)
	{
		printf("Arr[%d] ���� : ", i);
		scanf_s("%d", &Arr[i]);
	}
	display_all(Arr, size);
	ary_reverse(Arr, size);

	printf("�迭�� ��� ��Ҹ� �������� �����߽��ϴ�.\n");
	
	free(Arr);


}