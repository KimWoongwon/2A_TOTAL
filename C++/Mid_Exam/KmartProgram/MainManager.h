#ifndef _MAINMANAGER_H
#define _MAINMANAGER_H

#include "BaseManager.h"
class MainManager // 메인매니저 입니다.
{
private:
	static MainManager* Instance; // 싱글톤패턴을 사용하여 구현했습니다.

	MainManager(); // 생성자
	~MainManager();// 소멸자 
	// 실제로 내부에선 하는일이 없습니다.
public:
	// 메인매니저의 인스턴스를 할당해주고 각각의 다른 매니저들의 Create함수를 호출합니다.
	static void Create(); 
	// 메인매니저의 인스턴스를 삭제하면서 각각의 다른 매니저들의 Destroy함수를 호출합니다.
	static void Destroy(); 
	// 메인매니저의 인스턴스만 넘겨주는 함수입니다.
	static MainManager* GetInstance(); 

	// 초기화 함수입니다.
	void Initialaze(); 
	// 메인메뉴 출력함수
	int SelectMainMenu();
	// 각각의 매니저를 설정하는 함수
	BaseManager* MajorSelect();
	// 프로그램 실행함수
	void Run();
	// 유통기한이 지난 재고를 출력하는 함수
	void DateManagement();
};

#endif // !_MAINMANAGER_H



