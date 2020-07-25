#include <iostream>
#include <functional>
using namespace std;

int main(void)
{
	cout << less<int>()(10, 20) << endl;		//True
	cout << less<int>()(20, 20) << endl;		//False
	cout << less<int>()(20, 10) << endl;		//False
	cout << endl;

	cout << not2(less<int>())(10, 20) << endl;	//False
	cout << not2(less<int>())(20, 20) << endl;	//True
	cout << not2(less<int>())(20, 10) << endl;	//True
	cout << endl;

	less<int> l;
	cout << l(10, 20) << endl;
	cout << not2(l)(10, 20) << endl;

}
