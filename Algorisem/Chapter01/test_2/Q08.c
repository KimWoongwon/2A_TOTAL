#include <stdio.h>

//Q8 ���콺 �������� 1~n������ ���� ���ϱ�

void main()
{
	int n = 0;
	int sum = 0;

	printf("1~n������ ���콺 �����Դϴ�.\n");
	printf("n �� �� : ");
	scanf_s("%d", &n);

	sum = (1 + n) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

	printf("1~%d������ ���� %d �Դϴ�.\n", n, sum);
	
}