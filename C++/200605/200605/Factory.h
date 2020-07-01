#ifndef _FACTORY_H
#define _FACTORY_H

#include "Tools.h"

class Store // ���� ������ �ϴ� �������̽�(?)��� �����ߴ�. �� Ŭ������ ��ü�� �����ϴ� �������̽��� ���������� � ��ü�� ���������� �������� �ʴ´�.
{
private:
	virtual Tool* CreateTool() = 0;	// �� ������ �׿� �´� �п�ǰ�� �������ֱ� ���ؼ� ����ȭ �ߴ�.
public:
	virtual ~Store() {}
	void NewTool()
	{
		Tool* pTool = CreateTool(); // ����ȭ�� ���� Store��ü�� ����Ű�� �ִ� ������� ��ǰ�� ���������.
		pTool->Use();	// ����� ���� �ٸ��Ƿ� �������� �����ִ� �κ��̶�� �����Ѵ�.
		delete pTool;	// ������ �޸𸮸� ���������� ���߿� ������ �뵵�� ������ �ɰŰ���.
	}
}; 

// ������ �̿��ϴ� ����
// �������̽��� �̿��� � ��ü�� �������� �����ϴ� Ŭ�����̴�.
// ���忡 �ֹ��� �־ �̹��� �������ּ��� �ϴ� �����̴�.
class PencilStore : public Store
{
private:
	Tool* CreateTool()	// ���� �ٸ� ��ǰ�� �����ϱ⶧���� �׿� �´� ��ǰ�� �����ؼ� return���ش�.
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

