#include <stdio.h>

//Q9 ���� a,b�� �����Ͽ� �׻����� ��� ������ ���� ���ϴ� �Լ� �ۼ��ϼ���

int sumof(int a, int b)
{
	int sum = 0;
	if (a >= b)
	{
		while (b <= a)
		{
			sum += b;	
			b++;
		}
			
	}
	else
	{
		while (a <= b)
		{
			sum += a;
			a++;
		}
	}
	
	return sum;
}

void main()
{
	int a, b;

	printf("a~b������ �����Դϴ�.\n");
	printf("a �� �� : ");
	scanf_s("%d", &a);
	printf("b �� �� : ");
	scanf_s("%d", &b);

	if (a >= b)
		printf("%d ~ %d������ ���� %d �Դϴ�.\n", b, a, sumof(a, b));
	else
		printf("%d ~ %d������ ���� %d �Դϴ�.\n", a, b, sumof(a, b));

}