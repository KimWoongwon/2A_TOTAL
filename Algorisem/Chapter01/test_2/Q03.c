#include <stdio.h>

// Q3. �� ���� �ּҰ��� ���ϴ� �Լ� min4�� �ۼ��ϼ���.
int min4(int a, int b, int c, int d)
{
	int min;
	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	if (d < min)
		min = d;
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
	printf("d �� �Է� :");
	scanf_s("%d", &d);

	printf("�ּҰ��� %d �Դϴ�.", min4(a, b, c, d));
}