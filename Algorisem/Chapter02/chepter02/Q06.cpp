#include <stdio.h>

//Q6 card_convr�Լ��� �����Ͽ� �迭�� ���ʿ� �Ʒ��ڸ��� �ƴ� ���ڸ��� ����ǰ� �ۼ�

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

int card_conv(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x)
		{
			d[digits++] = dchar[x % n];
			x /= n;
		}
	for (int i = 0; i < digits / 2; i++)
		swap(int, d[i], d[digits - i - 1]);
	return digits;
}
int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x)
		{
			d[digits++] = dchar[x % n];
			x /= n;
		}
	return digits;
}

int main(void)
{
	int i, cd, dno, retry; 
	unsigned no;
	char cno[512];

	puts("10������ ��� ��ȯ�մϴ�.");
	do
	{
		printf("��ȯ�ϴ� ���� �ƴ� ���� : ");
		scanf_s("%u", &no);
		do
		{
			printf("� ������ ��ȯ�ұ��?(2-36) : ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd>36);
		dno = card_conv(no, cd, cno);
		printf("%d���� ��ȯ ��� : ", cd);
		for (i = 0; i<dno  ;i++)
			printf("%c", cno[i]);
		printf("\n");
		printf("�� �� �� �����Ͻðڽ��ϱ�? (1...��/0...�ƴϿ�) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}