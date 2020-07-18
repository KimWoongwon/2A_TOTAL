#pragma once
#include "../Global.h"

// 라디오 버튼 구현 클래스
class CRadioButton
{
	HWND	mHWnd;		// 라디오 버튼의 핸들값

public:
	CRadioButton(TCHAR*,int, int, int, int, int, bool); // 생성자 차례대로 라디오버튼 캡션, x,y좌표, 너비, 길이, ID값, 그룹여부
	~CRadioButton();

	HWND GetHandle();									// 핸들 읽기 접근자
	bool GetCheckInfo();								// 체크 됬는지 여부 반환 함수
														
	void SetPosition(int, int, int, int);				// 위치 및 크기 재설정 함수
	void SetCaption(TCHAR*);							// 버튼 내부 글씨 재설정 함수
	void SetVisable(bool);								// 보이기 여부 설정 함수
};
