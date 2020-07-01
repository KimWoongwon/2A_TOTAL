#include <stdio.h>
//Q08 전각문자로 출력하기
int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];


void print(void)
{
	int map[8][8] = {
	   {0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0},
	   {0,0,0,0,0,0,0,0}
	};
	for (int i = 0; i < 8; i++)
	{
		map[i][pos[i]] = 1;
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (map[i][j] == 0)
				printf("□");
			else if (map[i][j] == 1)
				printf("■");
		}
		putchar('\n');
	}
}
void set(int i)
{
	
	for (int j = 0; j < 8; j++)
	{
		if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7])
		{
			pos[i] = j;
			if (i == 7)
			{
				print();
				putchar('\n');
			}
			else
			{
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
				set(i + 1);
				flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
			}
		}
	}
}
int main(void)
{
	int i;
	for (i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (i = 0; i < 15; i++)
		flag_b[i] = flag_c[i] = 0;
	set(0);

	return 0;
}