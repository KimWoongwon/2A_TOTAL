#pragma once
#include "GameState.h"

// 캐릭터 생성 스테이트 클래스
class CCreateState :public CGameState
{
public:
	CCreateState(CLoginSystem* _game);	// 생성자
	~CCreateState();

	virtual void InitializeProcess();	// 화면 전환시 초기화를 위한 함수
	virtual void ButtonProcess(WPARAM);	// 어떤 버튼 클릭시 해당 이벤트 처리 함수
};



