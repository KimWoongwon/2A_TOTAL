#pragma once
#include <iostream>
using namespace std;
// 특정 클래스 manager나 관리자의 성격을 지니는 클래스는 여러개 생성되어선 안되는 성격을 가진다.
// 이를 위해 싱글톤패턴이라는 기법을 이용해 1개만 생성되도록 제한하고 이를 공유하는 방법이다.
// 생성자를 private으로 숨기고 Getinstance라는 함수로 자기 자신을 반환하는 함수를 가진다.
// 정적개체인 싱글톤이기 때문에 다른 전역 객체의 생성자에서 참조하고 싶은경우 문제가 생긴다.
// 객체의 생성시점이 불분명하기 때문이다. 따라서 이경우에는 생성시점을 조정해주어야 한다는 문제가 생긴다.
// 그래서 GetInstance함수가 처음 호출될때 클래스를 동적할당해주는 부분이 생긴다.

class Singleton
{
private:
	Singleton() {};
	Singleton(const Singleton& other);
	

	static Singleton* Instance;
	static bool InsFlag;

	int m_val = 0; // 무언가를 관리하기 위한 멤버변수
public:
	static Singleton* GetInstance();
	void Addvalue(int);	// 관리하는 멤버변수를 이용한 다양한 기능들을 구현하는 함수
	int GetValue(); // 지금은 그저 예제를 구현했기 때문에 더해주고 값을 리턴해주는 함수만 구현한다.
};