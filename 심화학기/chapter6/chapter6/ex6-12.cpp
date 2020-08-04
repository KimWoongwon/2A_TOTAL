#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	cout << v[0] << "," << v.front() << endl;
	cout << v[4] << "," << v.back() << endl;

	v.front() = 100;
	v.back() = 500;
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	v[1] = 200;
	v[3] = 300;
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	try
	{
		v.at(0) = 1000;
		v.at(4) = 5000;
		v.at(6) = 6000;
	}
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
