#pragma once

#include "../Global.h"
#include "../Character/Character.h"
// 유저의 캐릭터 리스트를 관리하는 매니저 클래스
// 유저마다 하나씩 생성되는 클래스
class CCharacterManager
{
private:
	char UserName[20];							// 이 객체의 주인을 알아보기 위한 이름
	CLinkedList<Character*>* mCharacterList;	// 캐릭터 리스트
	CNode<Character*>* mData;					// 캐릭터를 외부로 하나씩 넘겨주기 위한 노드
	
	int CharacterListCount;						// 총 캐릭터 수
public:
	CCharacterManager(char* pname);				// 캐릭터 리스트 생성자 : 해당 캐릭터 리스트의 주인 유저의 이름을 위한 매개변수
	~CCharacterManager();	

	void Initialize();							// 초기화 : 파일에서 읽어오는것 구현
	void SaveInfo();							// 해당 리스트의 모든 정보를 파일에 저장하는 함수
	bool Input(Character*);						// 외부에서 캐릭터 생성시 캐릭터를 리스트 안에 넣어주는 함수
	bool Delete(Character*);					// 외부에서 캐릭터 삭제시 매개변수로 넘겨받은 캐릭터를 찾아서 삭제해주는 함수
	bool GetData(Character**);					// 외부에서 검색이 필요한 경우 한개씩 데이터를 넘겨주는 함수
	void GetDataEnd();							// 외부에서 검색시 위치값의 초기화를 위한 함수
	int	 GetCount();							// 캐릭터의 수 반환 함수

};