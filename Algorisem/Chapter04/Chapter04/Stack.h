#ifndef _STACK_H
#define _STACK_H

typedef struct {
	int max;
	int ptr;
	int* stk;
}IntStack;


int Initialaze(IntStack* p_Stack, int max); // 스텍 초기화
int Push(IntStack* p_Stack, int x);			// 스텍에 데이터를 푸쉬
int Pop(IntStack* p_Stack, int* x);			// 스텍에서 데이터를 팝
int Peek(const IntStack* p_Stack, int* x);	// 스텍에서 데이터를 피크
void Clear(IntStack* p_Stack);				// 스택 비우기
int Capacity(const IntStack* p_Stack);		// 스택의 최대용량
int Size(const IntStack* p_Stack);			// 스텍의 데이터 갯수
int IsEmpty(const IntStack* p_Stack);		// 스텍이 비어있는지?
int IsFull(const IntStack* p_Stack);		// 스텍이 가득 찼는지?
int Search(const IntStack* p_Stack, int x);	// 스텍에서 검색
void Print(const IntStack* p_Stack);		// 스텍의 모든데이터 출력
void Teminate(IntStack* p_Stack);			// 스텍 종료

#endif // !_STACK_H
