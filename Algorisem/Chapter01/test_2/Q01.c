#include <stdio.h>

// Q1. 네 값의 최댓값을 구하는 함수 max4를 작성하세요.
int max4(int a, int b, int c, int d)
{
	int max;
	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	if (d > max)
		max = d;
	return max;
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
	printf("d 값 입력 :"); // 연습문제 Q1에서 추가됨
	scanf_s("%d", &d);

	printf("최대 값은 %d 입니다.", max4(a, b, c, d));
}