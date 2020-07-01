#include <stdio.h>
//Q3. �迭���� �������� �ִ� ������� ���ϴ� �Լ��� �ۼ��ϼ���
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

	puts("�迭 ���� �ִ������� ���մϴ�.");
	printf("�迭�� ���� : ");
	scanf_s("%d", &nx);

	x = calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("������ �Է��ϼ��� : ");
		scanf_s("%d", &x[i]);
	}

	printf("�ִ� ������� %d �Դϴ�. \n", gcd_array(x,nx));

	return 0;
}