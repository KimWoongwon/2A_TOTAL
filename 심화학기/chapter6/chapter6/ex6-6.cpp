#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v1(5);	// size가 5, 데이터가 0인 vector 생성
	v1.push_back(10);	// 0다음부터 들어감
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl << endl;

	vector<int> v2(5);
	v2[0] = 10;
	v2[1] = 20;
	v2[2] = 30;
	v2[3] = 40;
	v2[4] = 50;
	for (vector<int>::size_type i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl << endl;

	vector<int> v3(5);
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl << endl;

	vector<int> v4(5,0);
	for (vector<int>::size_type i = 0; i < v4.size(); i++)
		cout << v4[i] << " ";
	cout << endl << endl;

	vector<int> v5(5,10);
	for (vector<int>::size_type i = 0; i < v5.size(); i++)
		cout << v5[i] << " ";
	cout << endl << endl;
}