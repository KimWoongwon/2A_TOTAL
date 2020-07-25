#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	//explicit 키워드 = 명시적 호출만 가능하게 한다
	explicit Point(int px = 0, int py = 0) : x(px), y(py) {}

	void Print() const 
	{
		cout << x << "," << y << endl; 
	}
};

int main()
{
	Point pt;
	pt.Print();

	//pt = 10;			//암시적 생성자 호출 -> explicit 키워드로 호출 안됨
	pt = Point(10);		//명시적 생성자 호출
	pt.Print();

	return 0;
}
