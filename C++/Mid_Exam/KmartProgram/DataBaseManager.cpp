#include "DataBaseManager.h"
#include "Global.h"
DataBaseManager* DataBaseManager::Instance = nullptr;

DataBaseManager::DataBaseManager()
{
	// 생성자가 호출되면서 각 멤버변수를 초기화합니다.
	mData = nullptr;

	mClothList = nullptr;
	mClothCount = 0;
	mFoodList = nullptr;
	mFoodCount = 0;
	mElectronicList = nullptr;
	mElectronicCount = 0;
}
DataBaseManager::~DataBaseManager()
{
	// DB가 삭제되면서 리스트들을 삭제합니다.
	delete mClothList;
	delete mFoodList;
	delete mElectronicList;
}
void DataBaseManager::Create()
{
	// 싱글톤패턴의 인스턴스가 생성된적이 없다면 할당합니다.
	if (!Instance)
		Instance = new DataBaseManager();
}
void DataBaseManager::Destroy()
{
	// 싱글톤패턴의 인스턴스가 이미 생성되었다면 삭제합니다.
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}
DataBaseManager* DataBaseManager::GetInstance()
{
	// 인스턴스를 넘겨줍니다.
	return Instance;
}

void DataBaseManager::Initialaze()
{
	// 메인매니저에서 이니셜라이즈함수가 호출될경우 같이 호출되어 각멤버 리스트를 모두 할당합니다.
	mClothList = new CLinkedList<Product*>();
	mFoodList = new CLinkedList<Product*>();
	mElectronicList = new CLinkedList<Product*>();
}
void DataBaseManager::Input(Product* p_Data, int p_sel)
{
	// 각 매니저에서 호출되어 매개변수로 선택한 값이 같이 옵니다.
	// 따라서 어느 리스트에 매개변수로 넘어온 객체를 저장하는지 결정합니다.
	// 리스트의 Insert함수를 통해 리스트로 저장하고 카운트변수를 하나씩 늘려 얼마나 저장되어있는지 표현합니다..
	switch (p_sel)
	{
	case CLOTH:
		mClothList->Insert(p_Data);
		mClothCount++;
		break;
	case FOOD:
		mFoodList->Insert(p_Data);
		mFoodCount++;
		break;
	case ELECTRONIC:
		mElectronicList->Insert(p_Data);
		mElectronicCount++;
		break;
	default:
		break;
	}
}
bool DataBaseManager::Remove(Product* p_Data, int p_sel)
{
	// 각 매니저에서 호출되어 선택이 매개변수를 통해 넘어오고
	// 매개변수로 넘어온 객체를 리스트에서 삭제합니다.
	// 또한 저장된 객채의 갯수가 줄기 때문에 카운트 변수의 값을 하나 줄입니다.
	// 또한 성공 여부를 전달합니다.
	bool result = false;
	switch (p_sel)
	{
	case CLOTH:
		result = mClothList->Delete(p_Data);
		if (result)
			mClothCount--;
		break;
	case FOOD:
		result = mFoodList->Delete(p_Data);
		if (result)
			mFoodCount--;
		break;
	case ELECTRONIC:
		result = mElectronicList->Delete(p_Data);
		if (result)
			mElectronicCount--;
		break;
	default:
		break;
	}

	return result;
}
bool DataBaseManager::isEmpty(int p_sel)
{
	// 매개변수로 어떤 리스트인지 선택되어 선택된 리스트가 비어있는지 검사하는 함수입니다.
	// 카운트 변수가 값이 0이라면 비어있다는 뜻이므로 true를 리턴합니다.
	switch (p_sel)
	{
	case CLOTH:
		if (mClothCount == 0)
			return true;
		break;
	case FOOD:
		if (mFoodCount == 0)
			return true;
		break;
	case ELECTRONIC:
		if (mElectronicCount == 0)
			return true;
		break;
	default:
		break;
	}
	return false;
}
void DataBaseManager::GetDataEnd()
{
	//GetData함수에서 한개씩 넘어가며 데이터를 전달하므로
	// 데이터의 위치가 선택된 데이터에 머무르게 됩니다.
	// 따라서 초기값으로 설정해서 처음부터 다시 한개씩 넘겨줄수 있도록 해줍니다.
	mData = nullptr;
}
Product* DataBaseManager::GetData(int p_sel)
{
	// 이 함수가 처음 호출된다면 mData는 nullptr을 가지고 있습니다.
	if (!mData)
	{
		// 따라서 이안으로 들어오게되고 리스트의 처음 값을 설정해서 넘겨줍니다.
		switch (p_sel)
		{
		case CLOTH:
			mData = mClothList->GetmHead()->GetmNext();
			break;
		case FOOD:
			mData = mFoodList->GetmHead()->GetmNext();
			break;
		case ELECTRONIC:
			mData = mElectronicList->GetmHead()->GetmNext();
			break;
		default:
			break;
		}
	}
	else
	{
		// 이함수가 처음 호출된것이 아니라면 리스트의 다음위치로 설정합니다.
		mData = mData->GetmNext();
	}
	// 그후 mData에 노드값을 설정했으므로 이 노드의 데이터값을 넘겨줍니다.

	if (mData)
	{
		return mData->GetmData();
	}
	// mData가 끝일경우 nullptr을 넘겨서 리스트의 검색이 끝났다는것을 알립니다.
	return nullptr;
}