#pragma once
#include "GameState.h"

// 유저메뉴 선택 화면 객체
class CUserMenuState :	public CGameState
{
public:
	CUserMenuState(CLoginSystem*);			// 생성자
	~CUserMenuState();

	virtual void InitializeProcess();		// 화면 전환시 초기화를 위한 함수
	virtual void ButtonProcess(WPARAM);		// 어떤 버튼 클릭시 해당 이벤트 처리 함수
};

