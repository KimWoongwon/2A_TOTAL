#include <iostream>
#include <vector>
#include <list>
using namespace std;

void main()
{
	vector<int> v;
	list<int> lt;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	vector<int>::iterator viter = v.begin();
	++viter;
	list<int>::iterator liter = lt.begin();
	++liter;

	// v�� �ι�° ��Ҹ� ����
	viter = v.insert(viter, 600);
	liter = lt.insert(liter, 600);

	cout << "���� �߰� : " << *viter << endl;
	cout << "����Ʈ �߰� : " << *liter << endl;

	cout << "������ ����" << endl;
	for(viter = v.begin(); viter != v.end(); viter++)
		cout << *viter << " ";
	cout << endl;

	cout << "����Ʈ�� ����" << endl;
	for (liter = lt.begin(); liter != lt.end(); liter++)
		cout << *liter << " ";
	cout << endl;

}