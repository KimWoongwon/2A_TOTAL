#include <stdio.h>
//Q14 �Է��� ���� �Ѻ����� �ϴ� ���簢�� *��ȣ�� ���
int main(void)
{
	int num;
	printf("�簢���� ����մϴ�.\n");

	printf("�Է��� �� : ");
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
