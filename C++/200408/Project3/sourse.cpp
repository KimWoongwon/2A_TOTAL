#include <stdio.h>

void add(int a)
{
	a += 10;
}
void add_pointer(int* a)
{
	*a += 20;
}
void add_reference(int& a)
{
	a += 30;
}

void main()
{
	// Reference
	int a = 10;
	int& b = a;

	printf("a : %d b : %d\n", a, b); //일반적으로 a를 b에 할당했으니 당연히 같은 값이 뜬다.

	b = 20; //b의 값을 변경했을때 a의 값이 변하는것을 본다.
	printf("a : %d b : %d\n", a, b);
	// a의 값이 같이 바뀐걸로 보아 서로 연결되어있다. = a에게 할당된 메모리는 b에게 할당된 메모리와 같다 = b는 a와 같은 메모리를 가지지만 이름이 다르다.
	//int& c = 10;  위에서 a의 메모리를 b가 참조 했다면 이경우에는 10이라는 메모리가 없으니 c가 참조할 메모리가 없으므로 성립하지 않는다.

	//함수에 어떻게 적용되는지에 대한 예제
	//add, add_pointer, add_reference 세 함수다 반환값이 없는 각각 10 20 30을 더해주는 함수이다.
	int c = 20;

	add(c); // call by value 의 형태로 작동한다
	printf("c : %d\n", c);

	add_pointer(&c); // 포인터형 변수로 인해 call by reference의 형태로 작동한다 
	printf("c : %d\n", c);

	add_reference(c);// 레퍼런스형 변수로 인해 call by reference의 형태로 작동한다 
	printf("c : %d\n", c);

	//pointer 함수와 reference 함수의 결과로 c의 값이 변했다 
	//함수 안에서 함수 바깥의 변수의 값을 변경할때에는 Call by Reference 형식으로 함수를 만든다
	//포인터형 변수는 c의 주소값을 받는다 레퍼런스형 변수는 c의 할당된 메모리에 이름을 새로 만든다.

	printf("---------------------Reference End---------------------\n");

	//Const
	//변경가능한 수인 변수가 아니라 고정값인 상수를 만든다.

	const int x = 10;
	//int const x = 10;
	// const int 나 int const 나 동일한 선언방법이다.
	//x = 20; 
	//상수는 변경이 불가능 하기 때문에 x값을 수정하려 하면 에러가 뜬다.
	printf("x : %d\n", x);

	int y = 10;
	const int* Y = &y;
	// 포인터형 상수로 변수 Y안의 주소값의 변수 y을 상수로 만든다. 
	// int const* 나 const int* 나 동일하다.
	//*Y = 60;
	printf("*Y : %d\n", *Y);
	// 따라서 위와 같은 주소값을 통한 변수의 변경이 안된다.

	y = 20;
	printf("*Y : %d\n", *Y);
	// 하지만 주소값으로 접근했을때의 y의 값이 변경이 안되지만 y의값을 직접적으로 y = 20; 과 같이 바꾸면 된다.

	printf("Y : %d\n", Y);
	Y = &x;
	printf("&x : %d\n", &x);
	printf("Y : %d\n", Y);
	// 또한 Y로 접근하는 변수를 상수 취급이기 때문에 Y를 x의 주소값으로 변경하는것 또한 가능하다.

	int z = 10;
	int* const Z = &z;
	// 위와 다르게 변수를 상수취급이 아니라 포인터변수 자체를 상수로 취급한다.
	// Z = &x;
	printf("*Z : %d\n", *Z);
	// 따라서 z의 주소값인 Z에 x의 주소값을 넣는것이 안된다.

	*Z += 10;
	printf("*Z : %d\n", *Z);
	// 하지만 주소값의 내용인 z의 값을 Z를 통해 변경하는것은 된다. 따라서 내용물인 z는 상수가 아니라는것
	z += 10;
	printf("*Z : %d\n", *Z);
	// 그러므로 변수 z의 값을 직접적으로 변경하는것은 가능하다.

	int q = 10;
	const int* const Q = &q;
	// 변수와 포인터 모두 상수로 취급한다.
	//Q = &x;
	//*Q = 20;
	// 따라서 주소값을 변경하거나 주소값을 통해 변수의 내용을 바꾸는것 또한 다 안된다.
	printf("*Q : %d\n", *Q);
}