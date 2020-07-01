#include <iostream>
using namespace std;

//#include "Header.h"
//#include "SpeialTemp.h"
//#include "Header1.h"
#include "Header2.h"

int main(void)
{	
	
	//CStak<int>* _intstack=new CStak<int>();
	//int pdata;
	//_intstack->Push(10);
	//_intstack->Push(20);
	//_intstack->Push(30);
	//_intstack->Push(44);
	//_intstack->Push(55);
	//_intstack->Push(66);	

	//for(int i=0; i<6; i++)
	//{
	//	_intstack->Pop(pdata);
	//	cout << pdata << endl;
	//}

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

//=======================================================

	/*CStak<const char*>* _charstack=new CStak<const char*>();
	const char* pdata;
	_charstack->Push("aa");
	_charstack->Push("bb");
	_charstack->Push("cc");

	for(int i=0; i<3; i++)
	{
		_charstack->Pop(pdata);
		cout << pdata << endl;
	}*/

	//CStak<char*>* _charstack = new CStak<char*>();
	//char* pdata=new char[10];
	//strcpy(pdata, "aa");
	//_charstack->Push(pdata);

	//pdata = new char[10];
	//strcpy(pdata, "bb");

	//_charstack->Push(pdata);

	//pdata = new char[10];
	//strcpy(pdata, "cc");

	//_charstack->Push(pdata);

	///*for (int i = 0; i < 3; i++)
	//{
	//	_charstack->Pop(pdata);
	//	cout << pdata << endl;
	//}*/

	//delete _charstack;

//=======================================================

	/*temp<int>* _temp=new temp<int>(3);
	_temp->show();*/

	/*temp<const char*>* _temp2 = new temp<const char*>("hello");
	_temp2->show();*/

	/*temp<char*>* _temp3=new temp<char*>("hello");
	_temp3->show();*/


//=======================================================

	//temp<int, int, 3>* _temp=new temp<int, int, 3>();
	//_temp->show();                     


	/*temp<double, int, 3>* _temp=new temp<double, int, 3>();
	_temp->show(); */

	/*temp<double, double, 3>* _temp2=new temp<double, double, 3>();
	_temp2->show(); */

	/*temp<int, double, 3>* _temp3=new temp<int, double, 3>();
	_temp3->show();*/ 

	/*temp<double, int, 10>* _temp=new temp<double, int, 10>();
	_temp->show(); */


//=======================================================

	//temp<int>* _temp=new temp<int>();
	//_temp->show();

	//temp<char*>* _temp2=new temp<char*>("hello");
	//_temp2->show(); 

	//int a=100;
	//int* ap=&a;

	//temp<int*>* _temp3=new temp<int*>(ap);
	//_temp3->show();

	//delete _temp3;
	
	return 0;
}

