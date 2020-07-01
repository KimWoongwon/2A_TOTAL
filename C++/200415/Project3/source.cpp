#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> stack;
	
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);
	stack.Push(60);

	stack.Display_all();
	cout << endl;

	cout << "찾기 결과 : " << stack.Find(60) << endl;
	cout << "찾기 결과 : " << stack.Find(50) << endl;

	cout << "pop 되었습니다. : " << stack.Pop() << endl;
	cout << "pop 되었습니다. : " << stack.Pop() << endl;
	cout << "pop 되었습니다. : " << stack.Pop() << endl;

	cout << "찾기 결과 : " << stack.Find(60) << endl;
	cout << "찾기 결과 : " << stack.Find(50) << endl;

	stack.Display_all();
	return 0;
}

