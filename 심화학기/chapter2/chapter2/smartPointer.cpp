#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point(int px = 0, int py = 0) : x(px), y(py) {}

	void Print() const 
	{
		cout << x << "," << y << endl; 
	}
};

class PointPtr					//����Ʈ ������
{
private:
	Point* ptr;
public:
	PointPtr(Point* p) :ptr(p) { }
	~PointPtr() 
	{
		if (ptr)
			delete[] ptr; 
	}

	Point* operator ->() const
	{
		return ptr;				//Point ��ü�� �����͸� �������� //���� ������
	}

	Point& operator*() const	//��������
	{
		return *ptr;			//Point��ü ��ü�� �ǹ��ϴ� ������
	}
};

int main()
{
	PointPtr p1 = new Point(2, 3);
	Point* p2 = new Point(5, 5);

	p1->Print();				//p1���� �����ϴ� Point��ü �����͸� �����Ͽ� �Լ� ��밡��
	//p1.operator->()->Print(); //�� �ڵ�� ���� ����(�����)
	p2->Print();

	cout << endl;

	(*p1).Print();				//p1.operator*().Print()
	(*p2).Print();				//(*p2).Print()

	delete p2;
	return 0;
}
