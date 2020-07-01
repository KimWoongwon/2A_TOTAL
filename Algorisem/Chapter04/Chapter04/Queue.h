#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* que;
}IntQueue;


int Initialaze(IntQueue* q, int max);	// 큐 초기화
int Enque(IntQueue* q, int x);			// 큐에 데이터를 푸쉬
int Deque(IntQueue* q, int* x);			// 큐에서 데이터를 팝
int Peek(const IntQueue* q, int* x);	// 큐에서 데이터를 피크
void Clear(IntQueue* q);				// 큐 비우기
int Capacity(const IntQueue* q);		// 큐의 최대용량
int Size(const IntQueue* q);			// 큐의 데이터 갯수
int IsEmpty(const IntQueue* q);			// 큐이 비어있는지?
int IsFull(const IntQueue* q);			// 큐이 가득 찼는지?
int Search(const IntQueue* q, int x);	// 큐에서 검색
void Print(const IntQueue* q);			// 큐의 모든데이터 출력
void Teminate(IntQueue* q);				// 큐 종료

#endif // !_QUEUE_H
