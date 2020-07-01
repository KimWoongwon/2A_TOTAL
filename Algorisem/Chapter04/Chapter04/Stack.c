#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int Initialaze(IntStack* p_Stack, int max)
{
	p_Stack->ptr = 0;
	if ((p_Stack->stk = (int*)calloc(max, sizeof(int))) == NULL)
	{
		p_Stack->max = 0;
		return -1;
	}
	p_Stack->max = max;
	return 0;
}

int Push(IntStack* p_Stack, int x)
{
	if (p_Stack->ptr >= p_Stack->max)
		return -1;
	p_Stack->stk[p_Stack->ptr++] = x;
	return 0;
}
int Pop(IntStack* p_Stack, int* x)
{
	if (p_Stack->ptr <= 0)
		return -1;
	*x = p_Stack->stk[--p_Stack->ptr];
	return 0;
}
int Peek(const IntStack* p_Stack, int* x)
{
	if (p_Stack->ptr <= 0)
		return -1;
	*x = p_Stack->stk[p_Stack->ptr - 1];
	return 0;
}
void Clear(IntStack* p_Stack)
{
	p_Stack->ptr = 0;
}
int Capacity(const IntStack* p_Stack)
{
	return p_Stack->max;
}
int Size(const IntStack* p_Stack)
{
	return p_Stack->ptr;
}
int IsEmpty(const IntStack* p_Stack)
{
	return p_Stack->ptr <= 0;
}
int IsFull(const IntStack* p_Stack)
{
	return p_Stack->ptr >= p_Stack->max;
}
int Search(const IntStack* p_Stack, int x)
{
	int i;
	for (i = p_Stack->ptr - 1; i >= 0; i--)
	{
		if (p_Stack->stk[i] == x)
			return i;
	}
	return -1;
}
void Print(const IntStack* p_Stack)
{
	int i;
	for (i = 0; i < p_Stack->ptr; i++)
	{
		printf("%d ", p_Stack->stk[i]);
	}
	putchar('\n');
}
void Teminate(IntStack* p_Stack)
{
	if (p_Stack->stk != NULL)
	{
		free(p_Stack->stk);
	}
	p_Stack->max = p_Stack->ptr = 0;
}