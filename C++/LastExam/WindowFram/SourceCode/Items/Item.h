#pragma once
#include "../Global.h"

class Character;

// 아이템 클래스
class Item
{
private:
	char ItemName[50];	// 아이템의 이름
	STATUS* status;		// 아이템 착용시 보너스 스텟 수치
	int price;			// 가격
	CLASS ClassCode;	// 아이템 착용 가능 직업
	ITEMTYPE TypeCode;	// 아이템의 분류 (무기, 방어구)
public:
	Item(const char*, STATUS*, int, CLASS, ITEMTYPE);	// 생성자
	Item(Item& item);									// 복사 생성자
	~Item();

	char* GetName();									// 이름 읽기 접근자
	STATUS* GetStatus();								// 스텟 읽기 접근자
	int GetPrice();										// 가격 읽기 접근자
	CLASS GetClassCode();								// 클래스 코드 반환 함수
	ITEMTYPE GetTypeCode();								// 분류 코드 반환함수

	virtual void OnItem(Character*);					// 아이템 착용 가상 함수
	virtual void OffItem(Character*);					// 아이템 해제 가상 함수
};

