#include <stdio.h>

//Q11 양의 정수를 입력하고 자릿수를 출력하는 프로그램을 작성

void main()
{
	int a, temp;
	int count = 0;

	printf("a의 자릿수를 계산합니다.\n");
	do
	{
		printf("a 의 값 : ");
		scanf_s("%d", &a);
	} while (a < 0);
	
	temp = a;

	while (temp>0)
	{
		temp /= 10;
		count++;
	}

	printf("%d의 자릿수는 %d입니다", a, count);

}