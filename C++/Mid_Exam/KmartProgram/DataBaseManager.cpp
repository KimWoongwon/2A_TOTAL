#include "DataBaseManager.h"
#include "Global.h"
DataBaseManager* DataBaseManager::Instance = nullptr;

DataBaseManager::DataBaseManager()
{
	// �����ڰ� ȣ��Ǹ鼭 �� ��������� �ʱ�ȭ�մϴ�.
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
	// DB�� �����Ǹ鼭 ����Ʈ���� �����մϴ�.
	delete mClothList;
	delete mFoodList;
	delete mElectronicList;
}
void DataBaseManager::Create()
{
	// �̱��������� �ν��Ͻ��� ���������� ���ٸ� �Ҵ��մϴ�.
	if (!Instance)
		Instance = new DataBaseManager();
}
void DataBaseManager::Destroy()
{
	// �̱��������� �ν��Ͻ��� �̹� �����Ǿ��ٸ� �����մϴ�.
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}
DataBaseManager* DataBaseManager::GetInstance()
{
	// �ν��Ͻ��� �Ѱ��ݴϴ�.
	return Instance;
}

void DataBaseManager::Initialaze()
{
	// ���θŴ������� �̴ϼȶ������Լ��� ȣ��ɰ�� ���� ȣ��Ǿ� ����� ����Ʈ�� ��� �Ҵ��մϴ�.
	mClothList = new CLinkedList<Product*>();
	mFoodList = new CLinkedList<Product*>();
	mElectronicList = new CLinkedList<Product*>();
}
void DataBaseManager::Input(Product* p_Data, int p_sel)
{
	// �� �Ŵ������� ȣ��Ǿ� �Ű������� ������ ���� ���� �ɴϴ�.
	// ���� ��� ����Ʈ�� �Ű������� �Ѿ�� ��ü�� �����ϴ��� �����մϴ�.
	// ����Ʈ�� Insert�Լ��� ���� ����Ʈ�� �����ϰ� ī��Ʈ������ �ϳ��� �÷� �󸶳� ����Ǿ��ִ��� ǥ���մϴ�..
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
	// �� �Ŵ������� ȣ��Ǿ� ������ �Ű������� ���� �Ѿ����
	// �Ű������� �Ѿ�� ��ü�� ����Ʈ���� �����մϴ�.
	// ���� ����� ��ä�� ������ �ٱ� ������ ī��Ʈ ������ ���� �ϳ� ���Դϴ�.
	// ���� ���� ���θ� �����մϴ�.
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
	// �Ű������� � ����Ʈ���� ���õǾ� ���õ� ����Ʈ�� ����ִ��� �˻��ϴ� �Լ��Դϴ�.
	// ī��Ʈ ������ ���� 0�̶�� ����ִٴ� ���̹Ƿ� true�� �����մϴ�.
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
	//GetData�Լ����� �Ѱ��� �Ѿ�� �����͸� �����ϹǷ�
	// �������� ��ġ�� ���õ� �����Ϳ� �ӹ����� �˴ϴ�.
	// ���� �ʱⰪ���� �����ؼ� ó������ �ٽ� �Ѱ��� �Ѱ��ټ� �ֵ��� ���ݴϴ�.
	mData = nullptr;
}
Product* DataBaseManager::GetData(int p_sel)
{
	// �� �Լ��� ó�� ȣ��ȴٸ� mData�� nullptr�� ������ �ֽ��ϴ�.
	if (!mData)
	{
		// ���� �̾����� �����Եǰ� ����Ʈ�� ó�� ���� �����ؼ� �Ѱ��ݴϴ�.
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
		// ���Լ��� ó�� ȣ��Ȱ��� �ƴ϶�� ����Ʈ�� ������ġ�� �����մϴ�.
		mData = mData->GetmNext();
	}
	// ���� mData�� ��尪�� ���������Ƿ� �� ����� �����Ͱ��� �Ѱ��ݴϴ�.

	if (mData)
	{
		return mData->GetmData();
	}
	// mData�� ���ϰ�� nullptr�� �Ѱܼ� ����Ʈ�� �˻��� �����ٴ°��� �˸��ϴ�.
	return nullptr;
}