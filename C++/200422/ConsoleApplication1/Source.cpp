#include <iostream>
using namespace std;

//#include "Header.h"
//#include "SpeialTemp.h"
//#include "Header1.h"
//#include "Header2.h"

int main(void)
{	
	
	//CStak<int>* _intstack=new CStak<int>(); // 가장 일반적인 템플릿 클래스이다. 지금은 int형으로 만들어 졌지만, <> 이 안에 다른 자료형이 오더라도 같은일을 수행할수 있다.
	//int pdata;
	//_intstack->Push(10);	
	//_intstack->Push(20);
	//_intstack->Push(30);
	//_intstack->Push(44);
	//_intstack->Push(55);
	//_intstack->Push(66);	// push함수로 6개의 값을 스택에 넣어 주었다. pop했을때의 결과 값은 66, 55, 44, 30, 20, 10 순서로 출력될것으로 예상한다.

	//for(int i=0; i<6; i++)
	//{
	//	_intstack->Pop(pdata);	// pop하면서 매개변수에 참조자 형식을 사용하여 int형 변수인 pdata에 값을 바꾸어준다.
	//	cout << pdata << endl;  // pop한 결과가 어떻게 되는지 출력하는 부분이다.
	//}

//==============================================================

	//CStak<int, 5> stacklst;			// 일반적인 템플릿 T형을 이용한 템플릿 클래스 / 템플릿을 만들때 int형의 SIZE라는 define 처럼 전처리기를 통해 정의되는 값을 추가로 만들어 배열의 갯수를 정한다.
	//CStak<char*, 5> stacklst2;		// 템플릿의 T형이 부분특수화로 인해 T*형으로 바뀌어 템플릿클래스가 만들어지고 뒤에 오는 상수값은 int 형으로 이미 정의 되어있기 때문에 정수가 아닌 다른 값이 올수 없다.
	//								
	//char* str=new char[10];			// 평범한 char*형 변수 선언후 동적할당.
	//char* strdata=nullptr;			// char*변수 선언후 NULL값 할당.

	//strcpy(str, "aaaa");			// str변수에 "aaaa"라는 값을 할당한다.
	//stacklst2.Push(str);			// char*형스택이기 때문에 T형 클래스가 아닌 T*형 부분특수화 되어있는 클래스가 만들어지고, 그안의 push함수에서는 speial template push 메세지가 출력된다.
	//stacklst.Push(3);				// int 형 스택이기 떄문에 T형 클래스가 만들어지고 그안의 push함수에서는 speial template push라는 메세지 출력부분이 없다.
	//								// 따라서 실행결과에서는 speial template push라는 메세지가 한번 출력된다.
	//int data;
	//
	//stacklst.Pop(data);				// push상황과 같이 T형 클래스에서는 speial template pop가 출력되지 않고 
	//stacklst2.Pop(strdata);			// char*와 같이 포인터형을 위한 부분특수화가 진행되어 있기때문에 speial template pop라는 메세지가 출력된다.

	//
	//cout << data << endl;
	//cout << strdata << endl;

//=======================================================

	//CStak<const char*>* _charstack=new CStak<const char*>();	// 그냥 일반적인 템플릿 T형을 가지는 클래스 이다.
	//const char* pdata;		
	//_charstack->Push("aa");									// push함수도 다른 보통의 템플릿T형을 가진 클래스와 같다.
	//_charstack->Push("bb");										
	//_charstack->Push("cc");										

	//for(int i=0; i<3; i++)										
	//{															// 기존 T형 클래스에 정의 되어있던 pop함수를 쓰지 않고 pop함수를 함수템플릿의 완전특수화를 적용하여
	//	_charstack->Pop(pdata);									// const char*일때 완전특수화를 적용한 함수가 호출되게 하여 const char* Special Template라는 메세지를 출력하게 된다.
	//	cout << pdata << endl;									// 또한 완전특수화에서 반환값도 const char*형이 되기 때문에 pdata값도 const char*형으로 선언하여 값을 받아온다.
	//}

	//CStak<char*>* _charstack = new CStak<char*>();				// 또 다른 경우로 위의 const char*형이 아닌 그냥 char*형으로 스택을 구현했어도 같은 템플릿을 이용해 클래스를 만든다.
	//char* pdata=new char[10];									// 하지만 이번경우에는 char*에 const char*을 집어넣을수 없으므로 동적할당을 통해 
	//strcpy(pdata, "aa");										// 문자열을 새로이 복사하여 push해준다 push함수도 보통의 push와 다를것이 없다.
	//_charstack->Push(pdata);

	//pdata = new char[10];										// 새로 변수를 생성하는것이 아닌 이미 스택안에서 주소값을 가리키고 있기에 원래 변수에 새로 동적할당을 한다.
	//strcpy(pdata, "bb");

	//_charstack->Push(pdata);

	//pdata = new char[10];
	//strcpy(pdata, "cc");

	//_charstack->Push(pdata);

	//for (int i = 0; i < 3; i++)	
	//{
	//	_charstack->Pop(pdata);									// const char*으로 완전특수화되어있는 함수가 아닌 char*형으로 특수화가 된 함수가 호출되어
	//	cout << pdata << endl;									// Special Template이라는 메세지가 출력된다.
	//}															// 하지만 이렇게 배열로된 스택에 동적할당을 할때는 각각의 배열안의 값이 동적할당한 메모리의 주소를 가리키고 있으므로 이값들을 delete해주어야 한다.

	/*delete _charstack;*/										// pop했을때 배열스택이기 떄문에 바깥에서 delete해주는것이 맞다 하지만 이부분에서 그부분은 건너뛰고 pop을 하지 않고 스택자체를 delete했을때 결과값이다.
																// 동적으로 잡혀있는 메모리들이 있으므로 해제를 해주면서 메모리반납 이라는 메세지가 출력된다. 이부분도 함수의 완전특수화를 통해 소멸자를 재정의 할수 있다는것을 보여준다.
//=======================================================
		
	//temp<int>* _temp=new temp<int>(3);							// 이 코드는 함수의 완전특수화를 보여주고 있다. 항상 함수 템플릿의 특수화를 위해선 가장 기본이 되는 base템플릿이 필요하다.
	//_temp->show();												// int형으로 만들었을경우 가장 기본이 되는 T형 템플릿을 이용하고 있고 이것을 base템플릿이라고 한다. 
	//															// show함수를 이용해 출력을 해보면  base template!! 이라는 메세지가 출력되는것을 기억해두자.
	//temp<const char*>* _temp2 = new temp<const char*>("hello"); // const char*으로 템플릿을 이용해 만들었다. 이경우에 완전특수화를 이용해 어떤결과가 출력되는지 잘 보도록하자.
	//_temp2->show();												// show함수를 통해 출력값을 보면 const char*으로 완전특수화된 함수가 호출되어  full specialized template 라고 메세지가 뜨는것을 확인할수 있다.

	//temp<char*>* _temp3=new temp<char*>("hello");				// 이경우엔 char*형으로 만들었을때 T의 값이 한함수 내에 달라질수 없으므로 클래스의 완전특수화를 통해 해결하고 있다.
	//_temp3->show();												// 클래스의 선언부를 보면 생성자와 소멸자에서 각각 동적할당과 해제를 하고 있다.
																// 이부분은 base템플릿에 없는 부분을 추가시켜 다른 클래스를 만들수 있게 틀을 완전 새로 짯다고 말할수 있다.

//=======================================================

	/*temp<int, int, 3>* _temp0=new temp<int, int, 3>();		// 클래스의 정의 부분에서 템플릿인자값으로 3개를 받고 있다. T1, T2, int형인 a 
	_temp0->show();   */										// 클래스의 부분특수화를 통해 템플릿인자로 넘어오는 자료형에 따라 다른 형태의 클래스를 구현할수 있다.
																// 클래스의 정의 부분에 가보면 3가지 방법으로 부분특수화를 해놓았는데 아래 3개의 경우에 해당한다.

	//temp<double, int, 3>* _temp1=new temp<double, int, 3>();	// 이경우 T, int, 3이라는 탬플릿인자로 만들어져서 출력시 T,int template!! 메세지가 출력된다.
	//_temp1->show(); 

	//temp<double, double, 3>* _temp2=new temp<double, double, 3>(); // 이경우 T, T, 3이라는 템플릿인자로 만들어져 출력시 T,T template!! 라는 메세지가 출력된다.
	//_temp2->show(); 

	//temp<int, double, 3>* _temp3=new temp<int, double, 3>();	// 이경우 int, T, 3 으로 만들어져 int,T template!! 라는 메세지가 출력된다.
	//_temp3->show(); 

	/*temp<double, int, 10>* _temp=new temp<double, int, 10>(); // 마지막으로 이경우와 첫번째 경우에서는 Header2 파일에서 템플릿 인수 목록이 겹치는 상황이 발생한다. 따라서 에러표시는 나지 않지만 컴파일러가 모호하다고 판단하여 에러메세지를 출력한다.
	_temp->show(); */


//=======================================================

	//temp<int>* _temp=new temp<int>(20);							// base템플릿을 만들어 출력해보는 모습이다.
	//_temp->show();												// 출력시 base template 이라는 메세지가 출력된다.
	//	
	//temp<char*>* _temp2=new temp<char*>("hello");				// char* 형으로 템플릿을 만들었고 char*형으로 클래스가 완전특수화 되어있다.
	//_temp2->show();												// 출력시 아무런 메세지가 안나오도록 정의했다.

	//int a=100;													// 이번엔 int*형으로 구현했다.
	//int* ap=&a;

	//temp<int*>* _temp3=new temp<int*>(ap);						// int* 형 템플릿으로 클래스를 만들었을때, T = int* 가 될수 있다. 하지만 클래스의 부분특수화로 인해 T형이 아닌 T*형 템플릿이 설정되 클래스를 만든다.
	//_temp3->show();												// 클래스 내부로 가보면 동적할당을 하고 포인터 변수의 값을 카피하는 모습을 볼수 있다.
	//															// 출력시 Pointer specialization 이라는 메세지가 출력된다.
	//delete _temp3;												// _temp3을 delete하며 소멸자에서 생성자에서 동적할당한 메모리를 해제하며 memory return 이라는 메세지를 출력한다.
	//
	return 0;
}

