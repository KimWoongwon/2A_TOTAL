#include <stdio.h>
//Q4 세값의 대소관계 13종류의 모든조합에 대해 중앙값을 구하여 출력하는 프로그램 작성
int med3(int a, int b, int c)
{
	if (a >= b)
	{
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else
			return c;
	}
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else 
		return b;
}
void main()
{
	printf("med3 (%d, %d, %d) = %d입니다\n", 3, 2, 1, med3(3, 2, 1));		
	printf("med3 (%d, %d, %d) = %d입니다\n", 4, 8, 12, med3(4, 8, 12));		
	printf("med3 (%d, %d, %d) = %d입니다\n", 5, 20, 4, med3(5, 20, 4));		
	printf("med3 (%d, %d, %d) = %d입니다\n", 8, 8, 63, med3(8, 8, 63));		
	printf("med3 (%d, %d, %d) = %d입니다\n", 81, 32, 57, med3(81, 32, 57)); 
	printf("med3 (%d, %d, %d) = %d입니다\n", 78, 15, 17, med3(78, 15, 17)); 
	printf("med3 (%d, %d, %d) = %d입니다\n", 13, 7, 1, med3(13, 7, 1));
	printf("med3 (%d, %d, %d) = %d입니다\n", 6, 9, 3, med3(6, 9, 3));
	printf("med3 (%d, %d, %d) = %d입니다\n", 13, 26, 31, med3(13, 26, 31));
	printf("med3 (%d, %d, %d) = %d입니다\n", 16, 9, 31, med3(16, 9, 31));
	printf("med3 (%d, %d, %d) = %d입니다\n", 11, 38, 21, med3(11, 38, 21));
	printf("med3 (%d, %d, %d) = %d입니다\n", 83, 92, 61, med3(83, 92, 61));
	printf("med3 (%d, %d, %d) = %d입니다\n", 43, 22, 61, med3(43, 22, 61));



}