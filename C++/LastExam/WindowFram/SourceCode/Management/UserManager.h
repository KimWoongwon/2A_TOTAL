#pragma once

#include "../Global.h"
#include "User.h"

// 유저의 리스트를 관리하는 데이터베이스입니다.
// 유저의 리스트는 여러개 생길 이유가 없으므로 싱글톤 패턴으로 제작합니다.

class CUserManager
{
	DECLARE_SINGLETONE(CUserManager)	// 싱글톤패턴 선언 메크로
private:
	CLinkedList<CUser*>* mUserList;		// 유저 리스트
	CNode<CUser*>* mData;				// 데이터를 하나씩 넘겨줄때 사용하는 노드
	int UserListCount;					// 유저의 총 수

	CUserManager();						// 생성자
	~CUserManager();					// 소멸자
public:

	void Initialize();					// 초기화 함수	: 파일에서 유저리스트 정보를 읽어옵니다.
	void SaveInfo(CUser*);				// 저장 함수		: 파일에 유저리스트를 저장합니다.
	bool Input(CUser*);					// 유저리스트에 유저를 추가합니다.
	bool Delete(CUser*);				// 유저리스트에서 유저를 삭제합니다.
	bool GetData(CUser**);				// 외부에서 유저를 한개씩 넘겨줄때 사용합니다.
	void GetDataEnd();					// 외부에서 한개씩 넘겨주고 나면 이 함수를 통해 위치를 초기로 되돌립니다.
	int	 GetCount();					// 유저의 수를 반환합니다.
	
};

