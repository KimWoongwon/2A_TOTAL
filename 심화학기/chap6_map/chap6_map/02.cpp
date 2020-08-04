#include <iostream>
#include <map>
using namespace std;
void main()
{
	map<int, int, less<int>> m;
	pair<map<int, int>::iterator, bool> pr;

	m.insert(pair<int, int>(5, 100));	// 임시객체를 활용해 저장하는 방법
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));

	pr = m.insert(pair<int, int>(9, 50)); // 성공
	if (pr.second)
	{
		cout << "key : " << pr.first->first << ", value : " 
			<< pr.first->second << " 저장완료 " << endl;
	}
	else
	{
		cout << "key 9가 이미 m에 있습니다." << endl;
	}

	pr = m.insert(pair<int, int>(2, 50)); // 실패
	if (pr.second)
	{
		cout << "key : " << pr.first->first << ", value : "
			<< pr.first->second << " 저장완료 " << endl;
	}
	else
	{
		cout << "key 9가 이미 m에 있습니다." << endl;
	}

	pr = m.insert(pair<int, int>(9, 50)); // 성공
	if (pr.second)
	{
		cout << "key : " << pr.first->first << ", value : "
			<< pr.first->second << " 저장완료 " << endl;
	}
	else
	{
		cout << "key 9가 이미 m에 있습니다." << endl;
	}

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << "," << iter->second << ")" << " ";
	cout << endl;
}