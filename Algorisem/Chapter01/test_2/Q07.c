#include <stdio.h>
// Q7 1~n���� ���� �޾� 1+2+3+4.. �̷������� ����϶�
void main()
{
	int n = 0;
	int sum = 0;

	printf("1~n������ ���� ���մϴ�.\n");
	printf("n �� �� : ");
	scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
		sum += i;
	for (int i = 1; i < n; i++)
		printf("%d + ", i);
	printf("%d = %d\n", n, sum);
	



}