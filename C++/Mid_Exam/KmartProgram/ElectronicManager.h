#ifndef _ELECTRONICMANAGER_H
#define _ELECTRONICMANAGER_H
#include "BaseManager.h"
// �̱��� �������� ������� ������ǰ���� �Ŵ����Դϴ�.

class ElectronicManager : public BaseManager
{
private:
	static ElectronicManager* Instance;
	ElectronicManager();
	~ElectronicManager();
public:
	static void Create();
	static void Destroy();
	static ElectronicManager* GetInstance();

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

#endif // !_ELECTRONICMANAGER_H


