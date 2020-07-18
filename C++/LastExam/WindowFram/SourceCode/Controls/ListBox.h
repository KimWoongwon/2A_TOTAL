#pragma once
#include "../Global.h"

// ListVeiw 구현 클래스
class CListBox
{
	HWND	mHWnd;	// 리스트뷰의 핸들값
public:
	CListBox(int, int, int, int, int);		// 생성자 차례대로 x,y좌표, 너비, 길이, ID값
	~CListBox();			
	
	HWND GetHandle();						// 핸들 읽기 접근자
	void SetPosition(int, int, int, int);	// 위치 및 크기 재설정 함수
	void SetVisable(bool);					// 보이기 여부 설정 함수
};