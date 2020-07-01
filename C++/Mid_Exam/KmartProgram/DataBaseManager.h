#ifndef _DATABASEMANAGER_H
#define _DATABASEMANAGER_H
#include "LinkedList.h"
#include "Product.h"
// 데이터베이스매니저 입니다. (이하 DB)
class DataBaseManager
{
private:
	// DB 또한 싱글톤 패턴으로 제작되었습니다.
	static DataBaseManager* Instance;

	// 각각의 매니저에서 넘겨주는 객체를 담는 리스트입니다.
	CLinkedList<Product*>* mClothList;
	// 리스트 내부에 몇개의 재고가 저장되있는지 나타내는 변수입니다.
	int	mClothCount;

	CLinkedList<Product*>* mFoodList;
	int	mFoodCount;

	CLinkedList<Product*>* mElectronicList;
	int	mElectronicCount;

	// 데이터를 하나씩 넘겨줄때 이용할 변수입니다.
	CNode<Product*>* mData;

	DataBaseManager();
	~DataBaseManager();
public:
	// DB의 인스턴스를 생성하는 함수입니다.
	static void Create();
	// DB의 인스턴스를 삭제하는 함수입니다.
	static void Destroy();
	// DB를 다른 클래스에서도 사용할 수 있게끔 인스턴스를 넘겨주는 함수입니다.
	static DataBaseManager* GetInstance();

	// 각 리스트의 할당을 담당하는 함수입니다.
	void Initialaze();
	// 각 매니저에서 객체를 생성해서 넘겨주면 저장하는 함수입니다.
	void Input(Product*, int);
	// 각 매니저에서 객체를 찾아서 넘겨주면 삭제하는 함수입니다.
	bool Remove(Product*, int);
	// 리스트가 비었는지 검사하는 함수입니다.
	bool isEmpty(int);
	// 데이터를 하나씩 넘겨주기때문에 초기값으로 설정해주기 위한 함수입니다.
	void GetDataEnd();
	// 데이터를 하나씩 넘어가면서 넘겨주는 함수입니다.
	Product* GetData(int);
	
};


#endif // !_DATABASEMANAGER_H

