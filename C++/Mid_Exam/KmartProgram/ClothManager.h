#ifndef _CLOTHMANAGER_H
#define _CLOTHMANAGER_H
#include "BaseManager.h"
// �̱��� �������� ������� �Ƿ����� �Ŵ����Դϴ�.
class ClothManager : public BaseManager
{
private:
	static ClothManager* Instance;
	ClothManager();
	~ClothManager();
public:
	static void Create();
	static void Destroy();
	static ClothManager* GetInstance();
	
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
#endif // !_CLOTHMANAGER_H


