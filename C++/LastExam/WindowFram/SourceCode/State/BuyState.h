#pragma once
#include "GameState.h"

// 아이템 구매 state 
class CBuyState :public CGameState
{
public:
	CBuyState(CLoginSystem* _game);		
	~CBuyState();

	virtual void InitializeProcess();		// 화면 전환시 호출될 초기화 함수
	virtual void ButtonProcess(WPARAM);		// 각종 버튼 클릭시 이벤트 메시지 처리 함수
};
