#ifndef _PRODUCT_H
#define _PRODUCT_H

// 모든 제품이 따로 가져아할 멤버변수가 없기때문에 Product를 이용해 
// 의류 음식 가전제품으로 설정합니다.
class Product
{
private:
	char mName[20]; // 제품명
	char mDate[20]; // 제품의 유통기한
	int mCount = 0; // 재고의 갯수
public:
	Product(const char*, const char*, int);
	~Product();
	const char* GetName(); // 이름을 반환합니다.
	const char* GetDate(); // 유통기한을 반환합니다.
	int GetCount();			// 갯수가 몇개인지 반환합니다.
	void changeCount(int);	// 갯수를 수정할때 이용합니다.
};
#endif // !_PRODUCT_H


