#include <iostream>
#include <list>
using namespace std;

void main()
{
	list<int> lt1;
	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	list<int> lt2;
	lt2.push_back(15);
	lt2.push_back(25);
	lt2.push_back(35);
	lt2.push_back(45);
	lt2.push_back(55);

	list<int>::iterator iter;

	
	cout << "lt1 : ";
	for (iter = lt1.begin(); iter != lt1.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "lt2 : ";
	for (iter = lt2.begin(); iter != lt2.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	lt1.sort(greater<int>());
	lt2.sort(greater<int>());
	lt1.merge(lt2, greater<int>());
	cout << "merge : ";
	for (iter = lt1.begin(); iter != lt1.end(); iter++)
		cout << *iter << " ";
	cout << endl;
}