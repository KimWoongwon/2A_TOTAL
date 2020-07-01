#include <stdio.h>

// Q3. 네 값의 최소값을 구하는 함수 min4를 작성하세요.
int min4(int a, int b, int c, int d)
{
	int min;
	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
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
	printf("d 값 입력 :");
	scanf_s("%d", &d);

	printf("최소값은 %d 입니다.", min4(a, b, c, d));
}