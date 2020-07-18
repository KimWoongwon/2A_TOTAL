#pragma once
#include "../Global.h"

// 윈도우 도구인 GroupBox을 구현한 클래스
class CGroupBox
{
	HWND	mHWnd;		// 윈도우 핸들값

public:
	CGroupBox(TCHAR*, int, int, int, int, int);		// 생성자 차례대로 그룹박스의 텍스트, x,y좌표값, 너비, 길이, ID값
	~CGroupBox();

	HWND GetHandle();								// 윈도우 핸들 읽기 접근자
	void SetPosition(int, int, int, int);			// 위치 및 크기 재설정 함수
	void SetVisable(bool);							// 보이기 여부 설정 함수
};

