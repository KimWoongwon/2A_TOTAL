#include <iostream>
#include "Base.h"
#include "Warrior.h"
#include "SecondWarrior.h"
using namespace std;

#define EXCONSTCAST 1
#define EXSTATICCAST 2
#define EXDYNAMICCAST 3
//#define REINTERPRETCAST 4

int main(void)
{
#ifndef EXCONSTCAST
	/*const_cast 예제
		상수성을 부여하거나 제거하는 작업만 가능하다.int형을 double형으로 바꾸는 암시적, 명시적 형변환 조차 허용되지 않는다.*/

	// 상수성 부여
	int age = 24;
	int& Rage = age;

	// const int& testage = age; 와 같이 암시적인 형변환이 가능하기때문에 잘 사용하지 않는다.
	const int& testage = const_cast<int&>(age);

	// testage = 20; --> Error
	// const_cast로 인해 int형인 age가 const int& 로 형변환 되어 const키워드가 추가되었다.
	cout << "testage - " << testage << endl;

	// 상수성 제거
	int a = 20;
	const int& b = a;
	// 상수성을 가진 참조형 변수 b가 const_cast로 형변환 해서 참조형 r변수에 할당할수 있다.

	cout << "before : " << "a = " << a << " b = " << b << endl;

	int& r = const_cast<int&>(b);
	r = 24; // const형이 아니기 때문에 값의 수정이 된다. 결과값을 보면 r을 수정하니 a, b가 모두 수정됬다.
	cout << "After : " << "a = " << a << " b = " << b << " r = " << r << endl;
#endif // !EXCONSTCAST

#ifndef EXSTATICCAST
	/* static_cast 예제
		논리적으로 변경이 가능한 경우에만 형변환을 실행합니다.*/

	double a = 20.0f;
	int ia_1 = static_cast<int>(a);
	int ia_2 = static_cast<int>(20.0f);
	// 위와 같이 실수를 정수로 변환하는 것은 논리적으로 가능하기때문에 에러가 나지 않습니다.
	// 또한 정수를 실수로 변환하는 것도 물론 가능합니다.
	
	double b = 20.0f;
	double* dpb = &b;
	//int* ipb = static_cast<int*>(dpb); // 이경우에는 Error가 뜬다.
	// 이경우 처럼 위험한 형변환의 경우 컴파일에러를 통해 알려줍니다.

	Warrior* CWarr_1 = new Warrior();
	Base* Cbase_1 = static_cast<Base*>(CWarr_1);
	// 업캐스팅도 가능하다.
	Cbase_1->Move();
	// Cbase->Attck(); 하지만 자식클래스의 함수에 접근할 수 없다.

	//Warrior* CWarr = Cbase_1;  //자식클래스에 부모클래스를 담는것은 Error
	Warrior* CWarr_2 = static_cast<Warrior*>(Cbase_1);
	// 하지만 static_cast형변환을 사용하면 Error가 뜨지 않는다. 다운캐스팅이 가능하다는 뜻이다.
	CWarr_2->Move();
	CWarr_2->Attck();
	// 따라서 Warrior의 함수가 모두 호출된다.

	// 전체적으로 C방식의 명시적형변환과 매우 비슷하다.
	// 대신 C방식의 형변환 보다 훨씬더 명시적이고 논리적으로 가능한 형변환만 진행하기 때문에 훨씬 더 안전하다.

#endif // !EXSTATICCAST

#ifndef EXDYNAMICCAST
	/* dynamic_cast 예제
		상속관계 안에서 포인터나 참조자 타입을 기본클래스에서 파생클래스로의 다운캐스팅과 다중 상속에서 기본 클래스간의 안전한 타입캐스팅에 사용된다.*/
	// 업캐스팅, 다운캐스팅 모두 가능하다.


	Base* Cbase_1 = new Base();
	Warrior* CWarr_1 = dynamic_cast<Warrior*>(Cbase_1);
	if (CWarr_1 == NULL) // 실패할경우 NULL을 리턴해준다.
		cout << "Failed" << endl;
	// CWarr_3->Move(); 프로그램 멈춤
	// dynamic_cast 가 캐스팅해주는 것은 포인터나 참조자의 타입을 다운 캐스팅하는 것이지 객체의 타입을 캐스팅하지는 못한다.

	// SecondWarrior << BaseTwo와 Base를 다중상속 받은 클래스
	Base* one = NULL;
	BaseTwo* SWarr = new SecondWarrior(); // 업캐스팅

	//one = SWarr; 이경우에 컴파일에러를 표시한다.

	one = dynamic_cast<Base*>(SWarr);
	one->Move();
	// 이렇게 dynamic_cast를 이용하면 가능하다.

	// dynamic_cast를 사용하기 위해선 가상함수가 필수로 필요하다
	// 그 이유는 dynamic_cast가 형변환을 할때 RTTI(Runtime Type Information)을 사용해서
	// 런타임중에 안전하다고 생각되는경우에 형변환을 진행하기 때문이다.
	// c++에서는 클래스에 가상함수가 존재해야만 RTTI에서 타입 정보 객체를 포함하도록 구현되어있고
	// 때문에 RTTI를 사용하기 위해선 가상함수가 존재하는 클래스여야 한다는 뜻이다.

#endif // !EXSTATICCAST

#ifndef REINTERPRETCAST
	/* reinterpret_cast 예제
		이 형변환의 경우 제약없이 C타입의 형변환과 비슷한 기능을 한다.*/

	int a = 20;
	int* pa = &a;

	double* d = reinterpret_cast<double*>(pa);
	// 이런것도 가능하다.
	
	void* pv;
	pv = reinterpret_cast<void*>(pa);
	// 위와 같이 완전 무대뽀로 형변환이 가능하다
	// 사용하는것은 자유지만 책임은 프로그래머에게 있다.
	cout << *pa << '\t' << *d << endl;


#endif // !EXSTATICCAST



	

	



}