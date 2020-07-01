#ifndef _FOODMANAGER_H
#define _FOODMANAGER_H
#include "BaseManager.h"
// �̱��� �������� ������� �Ƿ����� �Ŵ����Դϴ�.
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

	// �� Ŭ�������� �̴ϼȶ����� �Լ��� �ϴ°��� �����ϴ�.
	// ������ ������ �������踦 ǥ���ϱ����ؼ� ����ִ� �Լ��� �ϳ� ��������ϴ�.
	void Initialaze();

	void InseartItem(); // �԰�
	void DeleteItem();  // ���
	void Display();		// ���
	void Search();		// �˻�
	// �Է��� ��������� �������� ��������� ���� ��� �ִ��� �˻��ϰ� ����ϴ� �Լ��Դϴ�.
	void OverDateSearch(const char*);
};

#endif // !_FOODMANAGER_H


