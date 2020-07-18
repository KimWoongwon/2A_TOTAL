#pragma once
#include "../Global.h"

// 스테틱 텍스트 구현 클래스

class CStaticText
{
	HWND	mHWnd;			// 스테틱 텍스트의 핸들값

public:
	CStaticText(int, int, int, int, int, TCHAR*);	// 생성자 차례대로 x,y좌표, 너비, 길이, ID값, 
	~CStaticText();

	HWND GetHandle();								// 핸들 읽기 접근자
	void ResetControl();							// 내부 글씨 초기화 함수
	void SetText(TCHAR*);							// 내부 글씨 재설정 함수
	void SetAlignment(Alignment);					// 정렬 기준 재설정 함수
	void SetPosition(int, int, int, int);			// 위치 및 크기 재설정 함수
	void SetVisable(bool);							// 보이기 여부 설정 함수
};

