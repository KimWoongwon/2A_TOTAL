#include <stdio.h>

//Q10 두 변수 a,b에 정수를 입력하고 b-a를 출력하는 프로그램을 작성

void main()
{
	int a, b;

	printf("b-a를 계산합니다.\n");
	printf("a 의 값 : ");
	scanf_s("%d", &a);

	while(1)
	{
		printf("b 의 값 : ");
		scanf_s("%d", &b);
		if (b >= a)
			break;
		printf("a보다 큰 값을 입력하세요! \n");
	}

	printf("%d - %d = %d", b, a, b - a);

}