#ifndef _DATABASEMANAGER_H
#define _DATABASEMANAGER_H
#include "LinkedList.h"
#include "Product.h"
// �����ͺ��̽��Ŵ��� �Դϴ�. (���� DB)
class DataBaseManager
{
private:
	// DB ���� �̱��� �������� ���۵Ǿ����ϴ�.
	static DataBaseManager* Instance;

	// ������ �Ŵ������� �Ѱ��ִ� ��ü�� ��� ����Ʈ�Դϴ�.
	CLinkedList<Product*>* mClothList;
	// ����Ʈ ���ο� ��� ��� ������ִ��� ��Ÿ���� �����Դϴ�.
	int	mClothCount;

	CLinkedList<Product*>* mFoodList;
	int	mFoodCount;

	CLinkedList<Product*>* mElectronicList;
	int	mElectronicCount;

	// �����͸� �ϳ��� �Ѱ��ٶ� �̿��� �����Դϴ�.
	CNode<Product*>* mData;

	DataBaseManager();
	~DataBaseManager();
public:
	// DB�� �ν��Ͻ��� �����ϴ� �Լ��Դϴ�.
	static void Create();
	// DB�� �ν��Ͻ��� �����ϴ� �Լ��Դϴ�.
	static void Destroy();
	// DB�� �ٸ� Ŭ���������� ����� �� �ְԲ� �ν��Ͻ��� �Ѱ��ִ� �Լ��Դϴ�.
	static DataBaseManager* GetInstance();

	// �� ����Ʈ�� �Ҵ��� ����ϴ� �Լ��Դϴ�.
	void Initialaze();
	// �� �Ŵ������� ��ü�� �����ؼ� �Ѱ��ָ� �����ϴ� �Լ��Դϴ�.
	void Input(Product*, int);
	// �� �Ŵ������� ��ü�� ã�Ƽ� �Ѱ��ָ� �����ϴ� �Լ��Դϴ�.
	bool Remove(Product*, int);
	// ����Ʈ�� ������� �˻��ϴ� �Լ��Դϴ�.
	bool isEmpty(int);
	// �����͸� �ϳ��� �Ѱ��ֱ⶧���� �ʱⰪ���� �������ֱ� ���� �Լ��Դϴ�.
	void GetDataEnd();
	// �����͸� �ϳ��� �Ѿ�鼭 �Ѱ��ִ� �Լ��Դϴ�.
	Product* GetData(int);
	
};


#endif // !_DATABASEMANAGER_H

