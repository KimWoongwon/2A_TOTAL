#include <iostream>
#include <algorithm>
using namespace std;
//// 서버 ////
//배열의 모든 원소에 반복적인 작업을 수행하게 추상화
void For_each(int* begin, int* end, void(*ptr)(int))
{
	while (begin != end)
	{
		ptr(*begin++);	// 클라이언트 함수 호출 (콜백)
	}
	
}


//// 클라이언트 ////
// 공백을 이용해 원소를 출력
void Print1(int n)
{
	cout << n << ' ';
}
// 각 원소를 제곱해 출력
void Print2(int n)
{
	cout << n * n << endl;
}
// 문자열과 endl을 이용해 원소를 출력
void Print3(int n)
{
	cout << "정수 : " << n << endl;
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