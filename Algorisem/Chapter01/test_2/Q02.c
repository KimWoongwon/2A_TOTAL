#include <stdio.h>

// Q2. �� ���� �ּҰ��� ���ϴ� �Լ� min3�� �ۼ��ϼ���.
int min3(int a, int b, int c)
{
	int min;
	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	
	return min;
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

	printf("�ּҰ��� %d �Դϴ�.", min3(a, b, c));
}