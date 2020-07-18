#pragma once
#include "GameState.h"

// 캐릭터 삭제 상태
class CDeleteState :public CGameState
{

public:
	CDeleteState(CLoginSystem* _game);		// 생성자
	~CDeleteState();

	virtual void InitializeProcess();		// 화면 전환시 초기화를 위한 함수
	virtual void ButtonProcess(WPARAM);		// 어떤 버튼 클릭시 해당 이벤트 처리 함수
};

