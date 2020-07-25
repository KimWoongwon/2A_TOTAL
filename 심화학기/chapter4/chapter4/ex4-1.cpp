#include <iostream>
#include <functional> // less()���
using namespace std;

template <typename T>
struct Less
{
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

template <typename T>
struct Greater
{
	bool operator()(T a, T b)
	{
		return a > b;
	}

};


int main()
{
	cout << Less<int>()(10, 20) << endl;				// �Լ� ��ü
	cout << Less<double>()(1.15, 1.2) << endl;
	cout << Greater<int>()(10, 20) << endl;
	cout << Greater<double>()(1.15, 1.2) << endl;

}


