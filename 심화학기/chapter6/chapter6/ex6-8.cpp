#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v1 (5);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	cout << "size : " << v1.size() << "\tcapacity : " << v1.capacity() << endl << endl;

	v1.resize(20);		// ������ �缳�� �����ʹ� 0
	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	cout << "size : " << v1.size() << "\tcapacity : " << v1.capacity() << endl << endl;

	v1.resize(10);		//����� ������� ������ capacity�� ���� �ʴ´�.
	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;
	cout << "size : " << v1.size() << "\tcapacity : " << v1.capacity() << endl;

}