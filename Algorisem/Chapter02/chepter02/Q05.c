#include <stdio.h>
#include <stdlib.h>

//Q5 배열을 역순으로 정렬하는 과정을 일일이 출력하는 프로그램 작성

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
		printf("a[%d] 와 a[%d]를 교환합니다.\n", i, n-i-1);
		display_all(a, n);
	}
}

int main(void)
{
	int* Arr;
	int size;

	printf("요소 개수 : ");
	scanf_s("%d", &size);
	Arr = calloc(size, sizeof(int));

	printf("%d개의 정수를 입력하세요. \n", size);
	for (int i = 0; i < size; i++)
	{
		printf("Arr[%d] 숫자 : ", i);
		scanf_s("%d", &Arr[i]);
	}
	display_all(Arr, size);
	ary_reverse(Arr, size);

	printf("배열의 모든 요소를 역순으로 정렬했습니다.\n");
	
	free(Arr);


}