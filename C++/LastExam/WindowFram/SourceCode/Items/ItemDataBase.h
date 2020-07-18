#pragma once
#include "../Global.h"
#include "../LinkedList.h"
#include "Weapon.h"
#include "Armor.h"
// 아이템 스토어 State 시 사용되는 데이터 베이스
class ItemDataBase	
{
	DECLARE_SINGLETONE(ItemDataBase)	// 싱글톤 패턴 선언
private:
	CLinkedList<Item*>* ItemList;		// 상점이 가지는 아이템 리스트
	CNode<Item*>* mData;				// 상점에서 한개씩 호출시 넘겨줄 노드
	int ItemListCount;					// 상점 아이템의 총 갯수
	ItemDataBase();				
	~ItemDataBase();
public:
	void Initialize();					// 초기화 함수 : 파일에서 아이템 정보 읽어오기
	bool Input(Item*);					// 플레이어가 아이템에 상점을 판경우 상점에 아이템을 넣어주는 함수
	bool Delete(Item*);					// 플레이어가 아이템을 살경우 해당 아이템을 상점에서 없애주기 위한함수
	bool GetData(Item**);				// 아이템 객체 하나씩 외부로 전달하기 위한 함수
	void GetDataEnd();					// 아이템 객체 전달후 위치값을 초기화 하는 함수
	int	 GetCount();					// 해당 리스트 내용 갯수를 반환하는 함수
};

