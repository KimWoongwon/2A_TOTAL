#include <stdio.h>

//Q9 정수 a,b를 포함하여 그사이의 모든 정수의 합을 구하는 함수 작성하세요

int sumof(int a, int b)
{
	int sum = 0;
	if (a >= b)
	{
		while (b <= a)
		{
			sum += b;	
			b++;
		}
			
	}
	else
	{
		while (a <= b)
		{
			sum += a;
			a++;
		}
	}
	
	return sum;
}

void main()
{
	int a, b;

	printf("a~b까지의 덧셈입니다.\n");
	printf("a 의 값 : ");
	scanf_s("%d", &a);
	printf("b 의 값 : ");
	scanf_s("%d", &b);

	if (a >= b)
		printf("%d ~ %d까지의 합은 %d 입니다.\n", b, a, sumof(a, b));
	else
		printf("%d ~ %d까지의 합은 %d 입니다.\n", a, b, sumof(a, b));

}