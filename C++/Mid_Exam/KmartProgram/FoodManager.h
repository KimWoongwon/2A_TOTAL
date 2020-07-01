#ifndef _FOODMANAGER_H
#define _FOODMANAGER_H
#include "BaseManager.h"
// 싱글톤 패턴으로 만들어진 의류관리 매니저입니다.
class FoodManager : public BaseManager
{
private:
	static FoodManager* Instance;
	FoodManager();
	~FoodManager();
public:
	static void Create();
	static void Destroy();
	static FoodManager* GetInstance();

	// 이 클래스에서 이니셜라이즈 함수는 하는것이 없습니다.
	// 하지만 개념적 계층관계를 표현하기위해서 비어있는 함수를 하나 만들었습니다.
	void Initialaze();

	void InseartItem(); // 입고
	void DeleteItem();  // 출고
	void Display();		// 출력
	void Search();		// 검색
	// 입력한 유통기한을 기점으로 유통기한이 지난 재고가 있는지 검사하고 출력하는 함수입니다.
	void OverDateSearch(const char*);
};

#endif // !_FOODMANAGER_H


