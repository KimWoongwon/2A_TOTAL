#include "Product.h"
#include "Global.h"
// ��ü�� �����Ҷ� ��ǰ��, ��ǰ�� �������, ��ǰ�� ������ ��� �����մϴ�.
Product::Product(const char* pName, const char* pDate, int pCount)
{
	strcpy_s(mName, strlen(mName), pName);
	strcpy_s(mDate, strlen(mDate), pDate);
	mCount = pCount;
}
Product::~Product()
{

}

// �̸��� ��ȯ�ϴ� �Լ��Դϴ�. �̸��� ��� �� �˻��Ҷ� �̿��մϴ�
const char* Product::GetName()
{
	return mName;
}
// ��������� ��ȯ�ϴ� �Լ��Դϴ�. ��������� ��� �� �˻��Ҷ� �̿��մϴ�.
const char* Product::GetDate()
{
	return mDate;
}
// ������ ��ȯ�ϴ� �Լ��Դϴ�. ������ ����Ҷ� �̿��մϴ�.
int Product::GetCount()
{
	return this->mCount;
}
// ��� ����Ҷ� ������ ���� ����ϴ� ��� ȣ��Ǵ� �Լ��Դϴ�.
void Product::changeCount(int p_val)
{
	mCount -= p_val;
}

