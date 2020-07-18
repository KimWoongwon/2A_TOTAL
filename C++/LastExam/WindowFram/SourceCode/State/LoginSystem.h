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

// ������Ʈ ���� ���� Ŭ����
class CLoginSystem
{	
	// �̱������� ����
	static CLoginSystem*	mPthis;

	CGameState*		mNowState;	// ���� ȭ��
	
	CTitleState*		mTitleState;		// Ÿ��Ʋ ȭ��
	CSignupState*		mSignupState;		// ȸ������ ȭ��
	CUserMenuState*		mUserMenuState;		// �����޴� ȭ��
	CStoreState*		mStoreState;		// �����޴� ȭ��
	CCreateState*		mCreateState;		// ĳ���ͻ��� ȭ��
	CDeleteState*		mDeleteState;		// ĳ���ͻ��� ȭ��
	CBuyState*			mBuyState;			// �����۱��� ȭ��
	CSellState*			mSellState;			// �������Ǹ� ȭ��
	CShowState*			mShowState;			// �κ��丮 ȭ��

	CUser*				mNowUser;			// �α����� ���� ����
	Character*			mNowCharacter;		// �� �޴����� ������ ���� ĳ����

	CLoginSystem();
	~CLoginSystem();

public:

	static CLoginSystem* Create();			// �̱��� ��ü �����Լ�
	static CLoginSystem* GetInstance();		// �̱��� ��ü �ν��Ͻ� ��ȯ �Լ�
	static void Destroy();					// �̱��� ��ü ���� �Լ�

	void InitializeProcess();				// �����쿡�� ȣ��� �ʱ�ȭ �Լ�
	void ButtonProcess(WPARAM);				// ��ư Ŭ���� �����쿡������ ȣ��� �Լ�

	CGameState* GetState(STATE);			// ���� ȭ�� ��ȯ�Լ�

	void SetNowState(CGameState*);			// ȭ�� ������ ���� �Լ�

	int Login(const char*, const char*);	// �α���ó��  �Լ�
	bool Logout();							// �α׾ƿ�ó�� �Լ�

	bool CharacterSetting(char*);			// �Ű������� �޾Ƽ� ���� ������ ����Ʈ�� ���� ĳ���� �������ִ� �Լ� 
	Character* GetNowCharacter();			// �ܺο��� ĳ���Ϳ� �����Ҽ� �ְԲ� ������ �Լ�
	
	int GetUserMoney();						// ���� ������ �� �б� ������
	void SetUserMoney(int);					// ���� ������ �� ���� ������

	bool Signup(const char*, const char*);	// ���� ���� �Լ�
	bool CreateCharacter(const char*, CharacterFactory*, CLASS);	// ĳ���� ���� �Լ�
	bool RemoveCharacter(char*);			// ĳ���� ���� �Լ�
	void ShowAllCharacter();				// ����Ʈ�信 ĳ���� �ѷ��ִ� �Լ�

	bool SellItemToStore(char*);			// ������ ������ �Ĵ� �Լ�
	bool BuyItemFromStore(char*);			// �������� �������� �����ϴ� �Լ�

	int ChangeItem(char*);					// �κ��丮 ȭ�鿡�� ĳ������ �������� �����ϴ� �Լ�
	bool OnItem(char*);						// ĳ���Ͱ� �������� �����ϱ� ���� ȣ��Ǵ� �Լ�
	int OffItem(char*);						// ĳ���Ͱ� �������� ���� ���� �ϱ����� ȣ��Ǵ� �Լ�
	
};

