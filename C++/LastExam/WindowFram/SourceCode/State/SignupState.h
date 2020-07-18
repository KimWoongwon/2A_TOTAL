#pragma once
#include "GameState.h"

// 회원가입 화면 객체
class CSignupState : public CGameState
{

public:
	CSignupState(CLoginSystem* _game);		// 생성자
	~CSignupState();

	virtual void InitializeProcess();		// 화면 전환시 초기화를 위한 함수
	virtual void ButtonProcess(WPARAM);		// 어떤 버튼 클릭시 해당 이벤트 처리 함수
};

