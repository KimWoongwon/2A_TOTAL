#pragma once

#include "../Global.h"
#include "../LinkedList.h"
#include "../Management/UserManager.h"
#include "../Character/CharacterFactory.h"
#include "../Items/ItemDataBase.h"
#include "TitleState.h"
#include "SignupState.h"
#include "UserMenuState.h"
#include "StoreState.h"
#include "CreateState.h"
#include "DeleteState.h"
#include "BuyState.h"
#include "SellState.h"
#include "ShowState.h"

// 스테이트 패턴 메인 클래스
class CLoginSystem
{	
	// 싱글톤패턴 구현
	static CLoginSystem*	mPthis;

	CGameState*		mNowState;	// 현재 화면
	
	CTitleState*		mTitleState;		// 타이틀 화면
	CSignupState*		mSignupState;		// 회원가입 화면
	CUserMenuState*		mUserMenuState;		// 유저메뉴 화면
	CStoreState*		mStoreState;		// 상정메뉴 화면
	CCreateState*		mCreateState;		// 캐릭터생성 화면
	CDeleteState*		mDeleteState;		// 캐릭터삭제 화면
	CBuyState*			mBuyState;			// 아이템구매 화면
	CSellState*			mSellState;			// 아이탬판매 화면
	CShowState*			mShowState;			// 인벤토리 화면

	CUser*				mNowUser;			// 로그인한 현재 유저
	Character*			mNowCharacter;		// 각 메뉴에서 선택한 현재 캐릭터

	CLoginSystem();
	~CLoginSystem();

public:

	static CLoginSystem* Create();			// 싱글톤 객체 생성함수
	static CLoginSystem* GetInstance();		// 싱글톤 객체 인스턴스 반환 함수
	static void Destroy();					// 싱글톤 객체 삭제 함수

	void InitializeProcess();				// 윈도우에서 호출될 초기화 함수
	void ButtonProcess(WPARAM);				// 버튼 클릭시 윈도우에서부터 호출될 함수

	CGameState* GetState(STATE);			// 현재 화면 반환함수

	void SetNowState(CGameState*);			// 화면 변경을 위한 함수

	int Login(const char*, const char*);	// 로그인처리  함수
	bool Logout();							// 로그아웃처리 함수

	bool CharacterSetting(char*);			// 매개변수로 받아서 현재 유저의 리스트를 뒤져 캐릭터 셋팅해주는 함수 
	Character* GetNowCharacter();			// 외부에서 캐릭터에 접근할수 있게끔 접근자 함수
	
	int GetUserMoney();						// 현재 유저의 돈 읽기 접근자
	void SetUserMoney(int);					// 현재 유저의 돈 쓰기 접근자

	bool Signup(const char*, const char*);	// 유저 생성 함수
	bool CreateCharacter(const char*, CharacterFactory*, CLASS);	// 캐릭터 생성 함수
	bool RemoveCharacter(char*);			// 캐릭터 삭제 함수
	void ShowAllCharacter();				// 리스트뷰에 캐릭터 뿌려주는 함수

	bool SellItemToStore(char*);			// 상점에 아이템 파는 함수
	bool BuyItemFromStore(char*);			// 상점에서 아이템을 구입하는 함수

	int ChangeItem(char*);					// 인벤토리 화면에서 캐릭터의 아이템을 변경하는 함수
	bool OnItem(char*);						// 캐릭터가 아이템을 장착하기 위해 호출되는 함수
	int OffItem(char*);						// 캐릭터가 아이템을 장착 해제 하기위해 호출되는 함수
	
};

