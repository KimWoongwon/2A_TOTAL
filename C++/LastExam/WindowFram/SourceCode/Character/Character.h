#pragma once
#include "../Global.h"
#include "../Management/ItemListManager.h"
#include "../Items/Factorys/ItemFactory.h"

class Character
{
protected:
	char name[20];									// 캐릭터의 이름
	int Level;										// 캐릭터의 레벨
	STATUS* status;									// 캐릭터 스텟수치

	REGION		region;								// 캐릭터 종족
	CLASS		cls;								// 캐릭터 직업

	Weapon*		NowWeapon;							// 현제 착용중인 무기
	Armor*		NowArmor;							// 현재 착용중인 방어구

	CItemListManager* Inventory;					// 인벤토리	:	아이템 리스트를 관리하는 매니저객체입니다.
public:
	Character(const char*, CLASS, ItemFactory*);	// 생성자
	virtual ~Character();							// 소멸자

	char* GetName();								// 캐릭터 닉네임 읽기 접근자
	char* GetRegion();								// 캐릭터 종족코드를 문자열로 변환후 반환하는 함수
	char* GetClass();								// 캐릭터 직업코드를 문자열로 변환후 반환하는 함수
	CLASS GetClassType();							// 캐릭터 직업 코드 읽기 접근자

	STATUS* GetStatus();							// 캐릭터의 스텟 읽기 접근자
	CItemListManager* GetInventory();				// 캐릭터의 인벤토리 읽기 접근자

	Weapon* GetWeapon();							// 캐릭터의 현재 무기 읽기 접근자
	Armor* GetArmor();								// 캐릭터의 현재 방어구 읽기 접근자

	bool OnItem(Item*);								// 매개변수로 받은 아이템을 무기인지 방어구인지 구분하고 해당 아이템의 OnItem 함수 호출
	bool OffItem(Item*);							// 매개변수로 받은 아이템이 무기인지 방어구인지 구분하고 현재 아이템의 OffItem 함수 호출

	void BuyItem(Item*);							// 상점에서 산 아이템을 매개변수로 받아 인벤토리에 넣어주는 함수
	Item* SellItem(char*);							// 인벤토리에서 매개변수로 받은 아이템이름(문자열)을 비교후 찾아서 상점에 팔기위해 넘겨주는 함수

	virtual void SetHp() = 0;						// 가상함수 목록 : Elf, Orc, Human 각각 초기 스텟이 다르게 설정하기 위해 가상함수화
	virtual void SetMp() = 0;
	virtual void SetATK() = 0;
	virtual void SetDEF() = 0;
	

};

