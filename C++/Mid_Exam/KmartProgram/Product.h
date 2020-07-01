#ifndef _PRODUCT_H
#define _PRODUCT_H

// ��� ��ǰ�� ���� �������� ��������� ���⶧���� Product�� �̿��� 
// �Ƿ� ���� ������ǰ���� �����մϴ�.
class Product
{
private:
	char mName[20]; // ��ǰ��
	char mDate[20]; // ��ǰ�� �������
	int mCount = 0; // ����� ����
public:
	Product(const char*, const char*, int);
	~Product();
	const char* GetName(); // �̸��� ��ȯ�մϴ�.
	const char* GetDate(); // ��������� ��ȯ�մϴ�.
	int GetCount();			// ������ ����� ��ȯ�մϴ�.
	void changeCount(int);	// ������ �����Ҷ� �̿��մϴ�.
};
#endif // !_PRODUCT_H


