#include <stdio.h>
//Q15 ���� ���̸� �޾� *��ȣ�� ���簢�� ����ϱ�
int main(void)
{
	int w,h;
	printf("�簢���� ����մϴ�.\n");

	printf("���� : ");
	scanf_s("%d", &h);
	printf("���� : ");
	scanf_s("%d", &w);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
