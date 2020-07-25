#include <iostream>
#include <algorithm>
using namespace std;
//// ���� ////
//�迭�� ��� ���ҿ� �ݺ����� �۾��� �����ϰ� �߻�ȭ
void For_each(int* begin, int* end, void(*ptr)(int))
{
	while (begin != end)
	{
		ptr(*begin++);	// Ŭ���̾�Ʈ �Լ� ȣ�� (�ݹ�)
	}
	
}


//// Ŭ���̾�Ʈ ////
// ������ �̿��� ���Ҹ� ���
void Print1(int n)
{
	cout << n << ' ';
}
// �� ���Ҹ� ������ ���
void Print2(int n)
{
	cout << n * n << endl;
}
// ���ڿ��� endl�� �̿��� ���Ҹ� ���
void Print3(int n)
{
	cout << "���� : " << n << endl;
}

void main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };

	For_each(arr, arr + 5, Print1);
	cout << endl;

	For_each(arr, arr + 5, Print2);
	cout << endl;

	For_each(arr, arr + 5, Print3);
	cout << endl;
}