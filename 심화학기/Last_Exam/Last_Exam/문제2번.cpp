// ���� 2��
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UpperGenerate
{
	int count = 0;
	int operator()()
	{
		return (++count) * 10;
	}
};

void main()
{
	int selectPos;
	vector<int> vec1(10);
	UpperGenerate tUpperGenerate;
	generate(vec1.begin(), vec1.end(), tUpperGenerate);

	vector<int>::iterator iter;
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	cout << "������ �����ұ�� ? : ";
	cin >> selectPos;

	cout << "�Ϻκ� ���� ��" << endl;
	sort(vec1.begin(), vec1.begin() + selectPos, greater<int>());
	cout << "vec1 : ";
	for (iter = vec1.begin(); iter != vec1.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

}