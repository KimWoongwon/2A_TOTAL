#include <stdio.h>
//Q3. 배열안의 정수들의 최대 공약수를 구하는 함수를 작성하세요
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else 
		return gcd(y, x % y);
}

int gcd_array(const int arr[], int n)
{
	if (n == 1)
		return arr[0];
	else if (n == 2)
		return (gcd(arr[0], arr[1]));
	else
		return (gcd(arr[0], gcd_array(&arr[1], n - 1)));
}

int main(void)
{
	int i, nx;
	int* x;

	puts("배열 안의 최대공약수를 구합니다.");
	printf("배열의 길이 : ");
	scanf_s("%d", &nx);

	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("정수를 입력하세요 : ");
		scanf_s("%d", &x[i]);
	}

	printf("최대 공약수는 %d 입니다. \n", gcd_array(x,nx));

	return 0;
}