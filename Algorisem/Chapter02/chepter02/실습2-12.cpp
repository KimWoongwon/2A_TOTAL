#include<stdio.h>

int mdays[][12] = { {31,28,31,30,31,30,31,31,30,31,30,31}, {31,29,31,30,31,30,31,31,30,31,30,31} };

int isleep(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int dayofyear(int y, int m, int d)
{
	int i;
	int days = d;
	for (i = 1; i < m;i++)
	{
		days += mdays[isleep(y)][i - 1];
	}
	return days;
}
int main(void)
{
	int year, month, day;
	int retry;
	do {
		printf("년 : "); scanf_s("%d", &year);
		printf("월 : "); scanf_s("%d", &month);
		printf("일 : "); scanf_s("%d", &day);
		if (isleep(year) == 1)
			printf("%d년은 윤년입니다.\n", year);
		else
			printf("%d년은 윤년이 아닙니다.\n", year);
		printf("%d년의 %d일째 입니다. \n", year, dayofyear(year, month, day));
		printf("다시할까요..?(1...yes/0...no)");
		scanf_s("%d", &retry);
	} while (retry == 1);

	return 0;
}