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
		cout << "테스트 정수 : " << n << endl;
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

	//객체를 멤버함수 포인터를 이용해서 출력
	(pt.*pf1)();
	(pt.*pf2)(10);
	cout << endl;
	//주소로
	(p->*pf1)();
	(p->*pf2)(10);
	cout << endl;
}