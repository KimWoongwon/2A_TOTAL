#pragma once

#include "../Global.h"

// 푸쉬버튼 구현 클래스
class CPushButton
{
	HWND	mHWnd;	// 푸쉬버튼의 핸들값

public:
	CPushButton(int, int, int, int, int);	// 생성자 차례대로 x,y좌표, 너비, 길이, ID값
	~CPushButton();

	HWND GetHandle();						// 핸들 읽기 접근자
	void SetPosition(int, int, int, int);	// 위치 및 크기 재설정 함수
	void SetCaption(TCHAR*);				// 버튼 내부 글씨 재설정 함수
	void SetVisable(bool);					// 보이기 여부 설정 함수
};

