#ifndef _STACK_H
#define _STACK_H

typedef struct {
	int max;
	int ptr;
	int* stk;
}IntStack;


int Initialaze(IntStack* p_Stack, int max); // ���� �ʱ�ȭ
int Push(IntStack* p_Stack, int x);			// ���ؿ� �����͸� Ǫ��
int Pop(IntStack* p_Stack, int* x);			// ���ؿ��� �����͸� ��
int Peek(const IntStack* p_Stack, int* x);	// ���ؿ��� �����͸� ��ũ
void Clear(IntStack* p_Stack);				// ���� ����
int Capacity(const IntStack* p_Stack);		// ������ �ִ�뷮
int Size(const IntStack* p_Stack);			// ������ ������ ����
int IsEmpty(const IntStack* p_Stack);		// ������ ����ִ���?
int IsFull(const IntStack* p_Stack);		// ������ ���� á����?
int Search(const IntStack* p_Stack, int x);	// ���ؿ��� �˻�
void Print(const IntStack* p_Stack);		// ������ ��絥���� ���
void Teminate(IntStack* p_Stack);			// ���� ����

#endif // !_STACK_H
