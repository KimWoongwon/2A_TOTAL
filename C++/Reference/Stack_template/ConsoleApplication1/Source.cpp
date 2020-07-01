#include <iostream>
#include "Header.h"

using namespace std;



int main(void)
{	
	/*CStak<int>* _intstack=new CStak<int>();
	int pdata;
	_intstack->Push(10);
	_intstack->Push(20);
	_intstack->Push(30);
	_intstack->Push(44);
	_intstack->Push(55);
	_intstack->Push(66);	

	for(int i=0; i<6; i++)
	{
		_intstack->Pop(pdata);
		cout << pdata << endl;
	}

	CStak<char*>* _charstack=new CStak<char*>();
	char* pdata;
	_charstack->Push("aa");
	_charstack->Push("bb");
	_charstack->Push("cc");

	for(int i=0; i<3; i++)
	{
		_charstack->Pop(pdata);
		cout << pdata << endl;
	}
	
	*/

//==============================================================

	/*CStak<int, 5> stacklst;
	CStak<char*, 5> stacklst2;

	char* str=new char[10];
	char* strdata=nullptr;

	strcpy(str, "aaaa");
	stacklst2.Push(str);
	stacklst.Push(3);

	int data;
	
	stacklst.Pop(data);
	stacklst2.Pop(strdata);

	
	cout << data << endl;
	cout << strdata << endl;*/

	
	return 0;
}

