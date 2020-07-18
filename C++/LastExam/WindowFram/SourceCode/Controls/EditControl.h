#pragma once
#include "../Global.h"

// 윈도우 도구의 EditControl을 구현한 클래스
class CEditControl
{
	HWND	mHWnd;	// 해당 윈도우의 핸들값

public:
	CEditControl(int, int, int, int, int);	// 생성자 차례대로 x좌표, y좌표, 너비, 길이, ID값
	~CEditControl();

	HWND GetHandle();						// 윈도우 핸들 읽기 접근자

	void ResetControl();					// 에디트 컨트롤 내부 텍스트 초기화 함수
	void SetPosition(int, int, int, int);	// 위치 및 크기 재설정 함수
	void GetText(TCHAR*, int);				// 에디트 컨트롤에 입력된 텍스트 가져오는 함수
	void SetVisable(bool);					// 보이기 여부 설정을 위한 함수
};

