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

class PointPtr					//스마트 포인터
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
		return ptr;				//Point 객체의 포인터를 리턴해줌 //실제 포인터
	}

	Point& operator*() const	//참조리턴
	{
		return *ptr;			//Point객체 자체를 의미하는 포인터
	}
};

int main()
{
	PointPtr p1 = new Point(2, 3);
	Point* p2 = new Point(5, 5);

	p1->Print();				//p1내에 존재하는 Point객체 포인터를 리턴하여 함수 사용가능
	//p1.operator->()->Print(); //위 코드랑 내용 같음(명시적)
	p2->Print();

	cout << endl;

	(*p1).Print();				//p1.operator*().Print()
	(*p2).Print();				//(*p2).Print()

	delete p2;
	return 0;
}
