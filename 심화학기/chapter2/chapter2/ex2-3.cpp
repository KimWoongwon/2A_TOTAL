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
	operator int()
	{
		cout << "operator int() Ÿ�Ժ�ȯ ������ ����" << endl;
		return x;
	}
};

int main()
{
	int n = 10;
	Point pt(2, 3);
	n = pt;

	cout << n << endl;

	return 0;
}