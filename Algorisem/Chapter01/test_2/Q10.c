#include <stdio.h>

//Q10 �� ���� a,b�� ������ �Է��ϰ� b-a�� ����ϴ� ���α׷��� �ۼ�

void main()
{
	int a, b;

	printf("b-a�� ����մϴ�.\n");
	printf("a �� �� : ");
	scanf_s("%d", &a);

	while(1)
	{
		printf("b �� �� : ");
		scanf_s("%d", &b);
		if (b >= a)
			break;
		printf("a���� ū ���� �Է��ϼ���! \n");
	}

	printf("%d - %d = %d", b, a, b - a);

}