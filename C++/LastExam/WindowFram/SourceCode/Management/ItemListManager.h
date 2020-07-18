#pragma once

#include "../Global.h"
#include "../Items/Item.h"
#include "../LinkedList.h"

// 캐릭터의 아이템 리스트 : 인벤토리
class CItemListManager
{
private:
	char CharacterName[20];			// 현재 객체의 주인이 누구인지 판별을 위한 변수
	CLinkedList<Item*>* mItemList;	// 캐릭터의 아이템 리스트 : 인벤토리
	CNode<Item*>* mData;			// 외부에서 검색시 리스트의 내용을 넘겨주는 함수

	int ItemListCount;				// 리스트 내부 아이템의 총 갯수
public:		
	CItemListManager(const char*); // 생성자 매개변수로는 현재 플레이어가 누군지 구별하기 위한 함수
	~CItemListManager();

	void Initialize(Item**, Item**);	// 초기화 함수 장착장비및 인벤토리 내부의 장비 리스트를 파일에서 부터 불러와 초기화
	void SaveInfo();					// 아이템의 구입 판매등이 끝난후 최종 정보를 파일에 저장하기 위한 함수
	void SaveNowInfo(Item*,Item*);		// 착용정보를 파일에 출력해줄 함수

	bool Input(Item*);					// 아이템 추가 함수
	bool Delete(Item*);					// 해당 아이템 삭제 함수
	bool GetData(Item**);				// 외부에서 아이템을 하나씩 넘겨주는 함수
	void GetDataEnd();					// 외부에서 검색시 검색 위치값 초기화 함수
	int	 GetCount();					// 외부에서 검색시 리스트의 갯수를 체크하기 위한 함수


};