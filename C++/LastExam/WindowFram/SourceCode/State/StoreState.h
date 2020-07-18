#pragma once
#include "GameState.h"

// 아이템 상점 메뉴 화면 객체
class CStoreState :public CGameState
{	

public:
	CStoreState(CLoginSystem* _game);		// 생성자
	~CStoreState();

	virtual void InitializeProcess();		// 화면 전환시 초기화를 위한 함수
	virtual void ButtonProcess(WPARAM);		// 어떤 버튼 클릭시 해당 이벤트 처리 함수
		
};

