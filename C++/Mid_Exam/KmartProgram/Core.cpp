#include "MainManager.h"
// 먼저 프로그램의 시작점인 core.cpp 파일 입니다.
// MainManager를 생성후 각각의 매니저들을 개념적 계층관계를 통해 생성하게끔 했습니다.
// 그후 Initialaze 함수를 호출해서 초기화 작업을 합니다. 
// Run 함수를 통해 실직적인 프로그램이 실행되고 Destroy함수를 통해 MainManager를 삭제하며
// 다른 매니저들도 같이 삭제되게끔 구현했습니다.
int main(void)
{
	MainManager::Create(); 
	MainManager::GetInstance()->Initialaze();
	MainManager::GetInstance()->Run();
	MainManager::Destroy();

	return 0;
}