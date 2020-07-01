#include <stdio.h>

void recur(int n)
{
	if (n > 0)
	{
		recur(n - 1);
		printf("%d\n", n);
		recur(n - 2);
	}
}
int main(void)
{
	int x;
	printf("정수 입력 : ");
	scanf_s("%d", &x);
	recur(x);

	return 0;
}