#ifndef _BASEMANAGER_H
#define _BASEMANAGER_H

// �� �Ŵ����� ��ӵǴ� �߻�Ŭ���� �Դϴ�.
class BaseManager
{
private:
public:
	BaseManager() {}
	~BaseManager() {}

	// ���� �����Լ��� ���� ������ �����ϰԲ� �߽��ϴ�.
	virtual void InseartItem() = 0;
	virtual void DeleteItem() = 0;
	virtual void Display() = 0;
	virtual void Search() = 0;
	virtual void OverDateSearch(const char*) = 0;
};

#endif // !_BASEMANAGER_H


