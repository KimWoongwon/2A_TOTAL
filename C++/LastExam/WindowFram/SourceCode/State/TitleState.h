#pragma once
#include "GameState.h"

// 타이틀 화면 객체
class CTitleState :	public CGameState
{

public:
	CTitleState(CLoginSystem* _game);	// 생성자
	~CTitleState();

	virtual void InitializeProcess();	// 화면 전환시 초기화를 위한 함수
	virtual void ButtonProcess(WPARAM);	// 어떤 버튼 클릭시 해당 이벤트 처리 함수
};

