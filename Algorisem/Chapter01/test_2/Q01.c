#include <stdio.h>

// Q1. �� ���� �ִ��� ���ϴ� �Լ� max4�� �ۼ��ϼ���.
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
	printf("a �� �Է� :");
	scanf_s("%d", &a);
	printf("b �� �Է� :");
	scanf_s("%d", &b);
	printf("c �� �Է� :");
	scanf_s("%d", &c);
	printf("d �� �Է� :"); // �������� Q1���� �߰���
	scanf_s("%d", &d);

	printf("�ִ� ���� %d �Դϴ�.", max4(a, b, c, d));
}