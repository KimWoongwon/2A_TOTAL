#include <stdio.h>

void main()
{
	int max;
	int a, b, c, d;
	printf("a �� �Է� :"); 
	scanf_s("%d", &a);
	printf("b �� �Է� :");
	scanf_s("%d", &b);
	printf("c �� �Է� :");
	scanf_s("%d", &c);

	max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;

	printf("�ִ� ���� %d �Դϴ�.", max);
}