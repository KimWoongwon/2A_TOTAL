#ifndef _MAINMANAGER_H
#define _MAINMANAGER_H

#include "BaseManager.h"
class MainManager // ���θŴ��� �Դϴ�.
{
private:
	static MainManager* Instance; // �̱��������� ����Ͽ� �����߽��ϴ�.

	MainManager(); // ������
	~MainManager();// �Ҹ��� 
	// ������ ���ο��� �ϴ����� �����ϴ�.
public:
	// ���θŴ����� �ν��Ͻ��� �Ҵ����ְ� ������ �ٸ� �Ŵ������� Create�Լ��� ȣ���մϴ�.
	static void Create(); 
	// ���θŴ����� �ν��Ͻ��� �����ϸ鼭 ������ �ٸ� �Ŵ������� Destroy�Լ��� ȣ���մϴ�.
	static void Destroy(); 
	// ���θŴ����� �ν��Ͻ��� �Ѱ��ִ� �Լ��Դϴ�.
	static MainManager* GetInstance(); 

	// �ʱ�ȭ �Լ��Դϴ�.
	void Initialaze(); 
	// ���θ޴� ����Լ�
	int SelectMainMenu();
	// ������ �Ŵ����� �����ϴ� �Լ�
	BaseManager* MajorSelect();
	// ���α׷� �����Լ�
	void Run();
	// ��������� ���� ��� ����ϴ� �Լ�
	void DateManagement();
};

#endif // !_MAINMANAGER_H



