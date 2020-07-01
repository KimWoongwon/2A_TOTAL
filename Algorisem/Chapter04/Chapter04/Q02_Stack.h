#ifndef _Q02_STACK_H
#define _Q02_STACK_H

typedef struct {
	int max;
	int fptr;
	int rptr;
	int* stk;
}IntStack;


int Initialaze(IntStack* p_Stack, int max); // 스텍 초기화
int fPush(IntStack* p_Stack, int x);			// 스텍에 데이터를 푸쉬
int fPop(IntStack* p_Stack, int* x);			// 스텍에서 데이터를 팝
int fPeek(const IntStack* p_Stack, int* x);	// 스텍에서 데이터를 피크
int rPush(IntStack* p_Stack, int x);			// 스텍에 데이터를 푸쉬
int rPop(IntStack* p_Stack, int* x);			// 스텍에서 데이터를 팝
int rPeek(const IntStack* p_Stack, int* x);	// 스텍에서 데이터를 피크
void Clear(IntStack* p_Stack);				// 스택 비우기
int Capacity(const IntStack* p_Stack);		// 스택의 최대용량
int Size(const IntStack* p_Stack);			// 스텍의 데이터 갯수
int IsEmpty(const IntStack* p_Stack);		// 스텍이 비어있는지?
int IsFull(const IntStack* p_Stack);		// 스텍이 가득 찼는지?
int fSearch(const IntStack* p_Stack, int x);	// 스텍에서 검색
int rSearch(const IntStack* p_Stack, int x);	// 스텍에서 검색
void Print(const IntStack* p_Stack);		// 스텍의 모든데이터 출력
void Teminate(IntStack* p_Stack);			// 스텍 종료

#endif // !_Q02_STACK_H
