#ifndef CUSER_H
#define CUSER_H

#include "../Global.h"
#include "CharacterManager.h"

// 유저 클래스
class CUser
{
private:
	char mId[10];						// 유저의 아이디
	char mPw[10];						// 유저의 비밀번호
	
	CCharacterManager* CharList;		// 유저가 가지는 캐릭터 리스트
	bool mLoginState;					// 유저의 로그인 상태

	int money;							// 유저의 돈 상태

public:
	CUser(const char*, const char*);	// 생성자 
	~CUser();

	const char* GetId();				// 아이디 읽기 접근자
	const char* GetPw();				// 비밀번호 읽기 접근자
	int GetMoney();						// 돈 읽기 접근자
	void SetMoney(int);					// 돈 수정 접근자
	bool  GetLoginState();				// 로그인 상태 읽기 접근자
	Character* GetChar(const char*);	// 매개변수로 받은 문자열과 맞는 캐릭터를 찾아 반환하는 함수
	CCharacterManager* GetCharList();	// 캐릭터 리스트 읽기 접근자
	int GetCount();						// 캐릭터 리스트 내부의 캐릭터 숫자 반환 함수

	void SetLogin();					// 유저의 로그인상태 변경 함수
	void SetLogout();
	
	void InsertCharacter(Character*);	// 캐릭터 생성 함수
	bool RemoveCharacter(const char*);	// 캐릭터 리스트에서 매개변수로 받은 문자열에 해당하는 캐릭터 삭제 함수
};

#endif