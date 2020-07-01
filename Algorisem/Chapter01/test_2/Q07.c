#include <stdio.h>
// Q7 1~n까지 값을 받아 1+2+3+4.. 이런식으로 출력하라
void main()
{
	int n = 0;
	int sum = 0;

	printf("1~n까지의 합을 구합니다.\n");
	printf("n 의 값 : ");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
		sum += i;
	for (int i = 1; i < n; i++)
		printf("%d + ", i);
	printf("%d = %d\n", n, sum);
	



}