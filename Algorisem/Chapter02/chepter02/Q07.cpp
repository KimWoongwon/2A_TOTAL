#include <stdio.h>

//Q7 앞의 프로그램을 기초로 오른쪽처럼 기수 변환 과정을 상세히 출력하는 프로그램 작성.

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

int card_conv(long x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x)
		{
			printf("%d |%13d....%d\n", n, x, x%n);
			d[digits++] = dchar[x % n];
			printf("  +-------------\n");
			x /= n;
		}
	printf("%16d\n", x);
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

	puts("10진수를 기수 변환합니다.");
	do
	{
		printf("변환하는 음이 아닌 정수 : ");
		scanf_s("%u", &no);
		do
		{
			printf("어떤 진수로 변환할까요?(2-36) : ");
			scanf_s("%d", &cd);
		} while (cd < 2 || cd>36);
		dno = card_conv(no, cd, cno);
		printf("%d진수 변환 결과 : ", cd);
		for (i = 0; i < dno;i++)
			printf("%c", cno[i]);
		printf("\n");
		printf("한 번 더 진행하시겠습니까? (1...예/0...아니오) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}