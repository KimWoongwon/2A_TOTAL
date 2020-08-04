#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

void main()
{
	vector<int> vec1(10);
	vector<int> vec2(10);
	vector<int>::iterator Iter;

	generate(vec1.begin(), vec1.end(), rand);

	cout << "vec1 : ";
	for (Iter = vec1.begin(); Iter != vec1.end(); Iter++)
		cout << *Iter << " ";
	cout << endl;
	cout << "vec2 : ";
	for (Iter = vec2.begin(); Iter != vec2.end(); Iter++)
		cout << *Iter << " ";
	cout << endl << endl;


	cout << "vec1 의 모든 데이터를 vec2에 복사" << endl << endl;
	copy(vec1.begin(), vec1.end(), vec2.begin());

	cout << "vec1 : ";
	for (Iter = vec1.begin(); Iter != vec1.end(); Iter++)
		cout << *Iter << " ";
	cout << endl;
	cout << "vec2 : ";
	for (Iter = vec2.begin(); Iter != vec2.end(); Iter++)
		cout << *Iter << " ";
	cout << endl;
	cout << "--------------------------------------------------------------------------" << endl << endl;
		
	list<int> list2(10);
	list<int>::iterator listiter;
	cout << "list2 : ";
	for (listiter = list2.begin(); listiter != list2.end(); listiter++)
		cout << *listiter << " ";
	cout << endl << endl;

	cout << "vec1 의 모든 데이터를 list2에 복사" << endl;
	copy(vec1.begin(), vec1.end(), list2.begin());

	cout << "list2 : ";
	for (listiter = list2.begin(); listiter != list2.end(); listiter++)
		cout << *listiter << " ";
	cout << endl << endl;
}