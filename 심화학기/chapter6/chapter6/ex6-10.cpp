#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v(5);
	cout << "size : " << v.size() << "\tcapacity : " << v.capacity() << endl << endl;

	vector<int>().swap(v);
	// 기본생성자로 만든 vector와 v(5) 컨테이너를 서로 교환
	cout << "size : " << v.size() << "\tcapacity : " << v.capacity() << endl << endl;

	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " , " << v2[i] << endl;
	cout << endl << endl;

	v1.swap(v2);
	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " , " << v2[i] << endl;
	cout << endl << endl;

}
