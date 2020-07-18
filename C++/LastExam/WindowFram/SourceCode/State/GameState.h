#pragma once
#include "../Global.h"

//헤더파일 충돌을 위해 임시 선언한 클래스
class CLoginSystem;

// 스테이트 패턴의 구현을 위해 정의한 클래스
class CGameState
{
private:
	CLoginSystem*    mSystem;	// STATE 패턴의 주가될 메인 클래스
public:
	CGameState(CLoginSystem* );
	~CGameState();

	CLoginSystem* GetSystem();	// 각 스테이트에서도 접근할수 있도록 접근자 구현
	virtual void InitializeProcess() = 0;	// 초기화 가상함수
	virtual void ButtonProcess(WPARAM) = 0;	// 버튼클릭시 호출될 가상함수

};

