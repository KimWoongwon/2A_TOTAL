#include <stdio.h>
//Q4 ������ ��Ұ��� 13������ ������տ� ���� �߾Ӱ��� ���Ͽ� ����ϴ� ���α׷� �ۼ�
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
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 3, 2, 1, med3(3, 2, 1));		
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 4, 8, 12, med3(4, 8, 12));		
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 5, 20, 4, med3(5, 20, 4));		
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 8, 8, 63, med3(8, 8, 63));		
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 81, 32, 57, med3(81, 32, 57)); 
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 78, 15, 17, med3(78, 15, 17)); 
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 13, 7, 1, med3(13, 7, 1));
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 6, 9, 3, med3(6, 9, 3));
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 13, 26, 31, med3(13, 26, 31));
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 16, 9, 31, med3(16, 9, 31));
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 11, 38, 21, med3(11, 38, 21));
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 83, 92, 61, med3(83, 92, 61));
	printf("med3 (%d, %d, %d) = %d�Դϴ�\n", 43, 22, 61, med3(43, 22, 61));



}