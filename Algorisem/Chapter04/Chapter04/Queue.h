#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* que;
}IntQueue;


int Initialaze(IntQueue* q, int max);	// ť �ʱ�ȭ
int Enque(IntQueue* q, int x);			// ť�� �����͸� Ǫ��
int Deque(IntQueue* q, int* x);			// ť���� �����͸� ��
int Peek(const IntQueue* q, int* x);	// ť���� �����͸� ��ũ
void Clear(IntQueue* q);				// ť ����
int Capacity(const IntQueue* q);		// ť�� �ִ�뷮
int Size(const IntQueue* q);			// ť�� ������ ����
int IsEmpty(const IntQueue* q);			// ť�� ����ִ���?
int IsFull(const IntQueue* q);			// ť�� ���� á����?
int Search(const IntQueue* q, int x);	// ť���� �˻�
void Print(const IntQueue* q);			// ť�� ��絥���� ���
void Teminate(IntQueue* q);				// ť ����

#endif // !_QUEUE_H
