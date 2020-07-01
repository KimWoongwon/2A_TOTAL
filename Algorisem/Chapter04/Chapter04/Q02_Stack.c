#include <stdio.h>
#include <stdlib.h>
#include "Q02_Stack.h"

int Initialaze(IntStack* p_Stack, int max)
{
	p_Stack->fptr = 0;
	
	if ((p_Stack->stk = calloc(max, sizeof(int))) == NULL)
	{
		p_Stack->max = 0;
		return -1;
	}
	p_Stack->max = max;
	p_Stack->rptr = p_Stack->max;
	return 0;
}

int fPush(IntStack* p_Stack, int x)
{
	if (p_Stack->fptr >= p_Stack->max)
		return -1;
	p_Stack->stk[p_Stack->fptr++] = x;
	return 0;
}
int fPop(IntStack* p_Stack, int* x)
{
	if (p_Stack->fptr <= 0)
		return -1;
	*x = p_Stack->stk[--p_Stack->fptr];
	return 0;
}
int fPeek(const IntStack* p_Stack, int* x)
{
	if (p_Stack->fptr <= 0)
		return -1;
	*x = p_Stack->stk[p_Stack->fptr - 1];
	return 0;
}
int rPush(IntStack* p_Stack, int x)
{
	if (p_Stack->rptr <= p_Stack->fptr || p_Stack->rptr <= 0)
		return -1;
	p_Stack->stk[--p_Stack->rptr] = x;
	return 0;
}
int rPop(IntStack* p_Stack, int* x)
{
	if (p_Stack->rptr >= p_Stack->max)
		return -1;
	*x = p_Stack->stk[p_Stack->rptr++];
	return 0;
}
int rPeek(const IntStack* p_Stack, int* x)
{
	if (p_Stack->rptr >= p_Stack->max)
		return -1;
	*x = p_Stack->stk[p_Stack->rptr + 1];
	return 0;
}
void Clear(IntStack* p_Stack)
{
	p_Stack->fptr = 0;
	p_Stack->rptr = p_Stack->max;
}
int Capacity(const IntStack* p_Stack)
{
	return p_Stack->max;
}
int Size(const IntStack* p_Stack)
{
	return p_Stack->fptr + (p_Stack->max - p_Stack->rptr);
}
int IsEmpty(const IntStack* p_Stack)
{
	if (p_Stack->fptr <= 0 && p_Stack->rptr >= p_Stack->max)
		return 1;
	else
		return 0;
}
int IsFull(const IntStack* p_Stack)
{
	if (p_Stack->fptr + 1 >= p_Stack->rptr)
		return 1;
	else
		return 0;
}
int fSearch(const IntStack* p_Stack, int x)
{
	int i;
	for (i = p_Stack->fptr - 1; i >= 0; i--)
	{
		if (p_Stack->stk[i] == x)
			return i;
	}
	return -1;
}
int rSearch(const IntStack* p_Stack, int x)
{
	int i;
	for (i = p_Stack->rptr; i <= p_Stack->max; i++)
	{
		if (p_Stack->stk[i] == x)
			return i;
	}
	return -1;
}
void Print(const IntStack* p_Stack)
{
	puts("------------------------");
	for (int i = 0; i < p_Stack->fptr; i++)
	{
		printf("%3d", p_Stack->stk[i]);
	}
	for (int i = p_Stack->fptr + 1; i < p_Stack->rptr; i++)
	{
		printf("   ");
	}
	for (int i = p_Stack->rptr; i < p_Stack->max; i++)
	{
		printf("%3d", p_Stack->stk[i]);
	}
	putchar('\n');
	puts("------------------------");
}
void Teminate(IntStack* p_Stack)
{
	if (p_Stack->stk != NULL)
	{
		free(p_Stack->stk);
	}
	p_Stack->rptr = p_Stack->max;
	p_Stack->max = p_Stack->fptr = 0;

}