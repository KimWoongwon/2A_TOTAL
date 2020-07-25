#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	//explicit Ű���� = ����� ȣ�⸸ �����ϰ� �Ѵ�
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

	//pt = 10;			//�Ͻ��� ������ ȣ�� -> explicit Ű����� ȣ�� �ȵ�
	pt = Point(10);		//����� ������ ȣ��
	pt.Print();

	return 0;
}
