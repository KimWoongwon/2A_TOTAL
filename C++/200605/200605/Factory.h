#ifndef _FACTORY_H
#define _FACTORY_H

#include "Tools.h"

class Store // 공장 역할을 하는 인터페이스(?)라고 생각했다. 이 클래스는 객체를 생성하는 인터페이스를 제공하지만 어떤 객체를 생성할지는 결정하지 않는다.
{
private:
	virtual Tool* CreateTool() = 0;	// 각 스토어에서 그에 맞는 학용품을 리턴해주기 위해서 가상화 했다.
public:
	virtual ~Store() {}
	void NewTool()
	{
		Tool* pTool = CreateTool(); // 가상화로 인해 Store객체가 가르키고 있는 스토어의 물품이 만들어진다.
		pTool->Use();	// 기능이 각각 다르므로 다형성을 보여주는 부분이라고 생각한다.
		delete pTool;	// 지금은 메모리를 해제하지만 나중엔 저장의 용도로 지워도 될거같다.
	}
}; 

// 공장을 이용하는 상점
// 인터페이스를 이용해 어떤 객체를 생산할지 결정하는 클래스이다.
// 공장에 주문을 넣어서 이물건 생산해주세요 하는 느낌이다.
class PencilStore : public Store
{
private:
	Tool* CreateTool()	// 각자 다른 물품을 관리하기때문에 그에 맞는 물품을 생성해서 return해준다.
	{
		return new Pencil();
	}
};
class PenStore : public Store
{
private:
	Tool* CreateTool()
	{
		return new Pen();
	}
};
class GlueStore : public Store
{
private:
	Tool* CreateTool()
	{
		return new Glue();
	}
};
class ScissorsStore : public Store
{
private:
	Tool* CreateTool()
	{
		return new Scissors();
	}
};
#endif // !_FACTORY_H

