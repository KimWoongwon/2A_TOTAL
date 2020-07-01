#include "Product.h"
#include "Global.h"
// 객체를 생성할때 제품명, 제품의 유통기한, 제품의 갯수를 모두 설정합니다.
Product::Product(const char* pName, const char* pDate, int pCount)
{
	strcpy_s(mName, strlen(mName), pName);
	strcpy_s(mDate, strlen(mDate), pDate);
	mCount = pCount;
}
Product::~Product()
{

}

// 이름을 반환하는 함수입니다. 이름을 출력 및 검사할때 이용합니다
const char* Product::GetName()
{
	return mName;
}
// 유통기한을 반환하는 함수입니다. 유통기한을 출력 및 검사할때 이용합니다.
const char* Product::GetDate()
{
	return mDate;
}
// 갯수를 반환하는 함수입니다. 갯수를 출력할때 이용합니다.
int Product::GetCount()
{
	return this->mCount;
}
// 재고를 출고할때 갯수를 정해 출고하는 경우 호출되는 함수입니다.
void Product::changeCount(int p_val)
{
	mCount -= p_val;
}

