#ifndef _BASEMANAGER_H
#define _BASEMANAGER_H

// 각 매니저에 상속되는 추상클래스 입니다.
class BaseManager
{
private:
public:
	BaseManager() {}
	~BaseManager() {}

	// 순수 가상함수로 만들어서 무조건 구현하게끔 했습니다.
	virtual void InseartItem() = 0;
	virtual void DeleteItem() = 0;
	virtual void Display() = 0;
	virtual void Search() = 0;
	virtual void OverDateSearch(const char*) = 0;
};

#endif // !_BASEMANAGER_H


