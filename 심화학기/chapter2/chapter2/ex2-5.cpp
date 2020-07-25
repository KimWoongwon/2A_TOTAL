#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	explicit Point(int px = 0, int py = 0) : x(px), y(py) {}
	void Print() const
	{
		cout << x << "," << y << endl;
	}
	void PrintInt(int n)
	{
		cout << "�׽�Ʈ ���� : " << n << endl;
	}
};

void main()
{
	Point pt(2, 3);
	Point* p = &pt;

	pt.Print();
	pt.PrintInt(10);
	cout << endl;

	void(Point::*pf1)() const;
	pf1 = &Point::Print;
	void(Point:: * pf2)(int);
	pf2 = &Point::PrintInt;

	//��ü�� ����Լ� �����͸� �̿��ؼ� ���
	(pt.*pf1)();
	(pt.*pf2)(10);
	cout << endl;
	//�ּҷ�
	(p->*pf1)();
	(p->*pf2)(10);
	cout << endl;
}