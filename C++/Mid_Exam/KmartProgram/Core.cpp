#include "MainManager.h"
// ���� ���α׷��� �������� core.cpp ���� �Դϴ�.
// MainManager�� ������ ������ �Ŵ������� ������ �������踦 ���� �����ϰԲ� �߽��ϴ�.
// ���� Initialaze �Լ��� ȣ���ؼ� �ʱ�ȭ �۾��� �մϴ�. 
// Run �Լ��� ���� �������� ���α׷��� ����ǰ� Destroy�Լ��� ���� MainManager�� �����ϸ�
// �ٸ� �Ŵ����鵵 ���� �����ǰԲ� �����߽��ϴ�.
int main(void)
{
	MainManager::Create(); 
	MainManager::GetInstance()->Initialaze();
	MainManager::GetInstance()->Run();
	MainManager::Destroy();

	return 0;
}