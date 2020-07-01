#ifndef _Q02_STACK_H
#define _Q02_STACK_H

typedef struct {
	int max;
	int fptr;
	int rptr;
	int* stk;
}IntStack;


int Initialaze(IntStack* p_Stack, int max); // ���� �ʱ�ȭ
int fPush(IntStack* p_Stack, int x);			// ���ؿ� �����͸� Ǫ��
int fPop(IntStack* p_Stack, int* x);			// ���ؿ��� �����͸� ��
int fPeek(const IntStack* p_Stack, int* x);	// ���ؿ��� �����͸� ��ũ
int rPush(IntStack* p_Stack, int x);			// ���ؿ� �����͸� Ǫ��
int rPop(IntStack* p_Stack, int* x);			// ���ؿ��� �����͸� ��
int rPeek(const IntStack* p_Stack, int* x);	// ���ؿ��� �����͸� ��ũ
void Clear(IntStack* p_Stack);				// ���� ����
int Capacity(const IntStack* p_Stack);		// ������ �ִ�뷮
int Size(const IntStack* p_Stack);			// ������ ������ ����
int IsEmpty(const IntStack* p_Stack);		// ������ ����ִ���?
int IsFull(const IntStack* p_Stack);		// ������ ���� á����?
int fSearch(const IntStack* p_Stack, int x);	// ���ؿ��� �˻�
int rSearch(const IntStack* p_Stack, int x);	// ���ؿ��� �˻�
void Print(const IntStack* p_Stack);		// ������ ��絥���� ���
void Teminate(IntStack* p_Stack);			// ���� ����

#endif // !_Q02_STACK_H
