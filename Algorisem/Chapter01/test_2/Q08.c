#include <stdio.h>

//Q8 가우스 덧셈으로 1~n까지의 값을 구하기

void main()
{
	int n = 0;
	int sum = 0;

	printf("1~n까지의 가우스 덧셈입니다.\n");
	printf("n 의 값 : ");
	scanf_s("%d", &n);

	sum = (1 + n) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

	printf("1~%d까지의 합은 %d 입니다.\n", n, sum);
	
}