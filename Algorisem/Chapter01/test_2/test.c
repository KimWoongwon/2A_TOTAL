#include <stdio.h>

void main()
{
	int max;
	int a, b, c, d;
	printf("a 값 입력 :"); 
	scanf_s("%d", &a);
	printf("b 값 입력 :");
	scanf_s("%d", &b);
	printf("c 값 입력 :");
	scanf_s("%d", &c);

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;

	printf("최대 값은 %d 입니다.", max);
}