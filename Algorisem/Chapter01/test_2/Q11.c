#include <stdio.h>

//Q11 ���� ������ �Է��ϰ� �ڸ����� ����ϴ� ���α׷��� �ۼ�

void main()
{
	int a, temp;
	int count = 0;

	printf("a�� �ڸ����� ����մϴ�.\n");
	do
	{
		printf("a �� �� : ");
		scanf_s("%d", &a);
	} while (a < 0);
	
	temp = a;

	while (temp>0)
	{
		temp /= 10;
		count++;
	}

	printf("%d�� �ڸ����� %d�Դϴ�", a, count);

}