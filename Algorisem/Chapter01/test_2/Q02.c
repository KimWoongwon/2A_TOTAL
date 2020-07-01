#include <stdio.h>

// Q2. 세 값의 최소값을 구하는 함수 min3를 작성하세요.
int min3(int a, int b, int c)
{
	int min;
	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	
	return min;
}

void main()
{
	int a, b, c, d;
	printf("a 값 입력 :");
	scanf_s("%d", &a);
	printf("b 값 입력 :");
	scanf_s("%d", &b);
	printf("c 값 입력 :");
	scanf_s("%d", &c);

	printf("최소값은 %d 입니다.", min3(a, b, c));
}