#pragma once
#include <iostream>
using namespace std;
// Ư�� Ŭ���� manager�� �������� ������ ���ϴ� Ŭ������ ������ �����Ǿ �ȵǴ� ������ ������.
// �̸� ���� �̱��������̶�� ����� �̿��� 1���� �����ǵ��� �����ϰ� �̸� �����ϴ� ����̴�.
// �����ڸ� private���� ����� Getinstance��� �Լ��� �ڱ� �ڽ��� ��ȯ�ϴ� �Լ��� ������.
// ������ü�� �̱����̱� ������ �ٸ� ���� ��ü�� �����ڿ��� �����ϰ� ������� ������ �����.
// ��ü�� ���������� �Һи��ϱ� �����̴�. ���� �̰�쿡�� ���������� �������־�� �Ѵٴ� ������ �����.
// �׷��� GetInstance�Լ��� ó�� ȣ��ɶ� Ŭ������ �����Ҵ����ִ� �κ��� �����.

class Singleton
{
private:
	Singleton() {};
	Singleton(const Singleton& other);
	

	static Singleton* Instance;
	static bool InsFlag;

	int m_val = 0; // ���𰡸� �����ϱ� ���� �������
public:
	static Singleton* GetInstance();
	void Addvalue(int);	// �����ϴ� ��������� �̿��� �پ��� ��ɵ��� �����ϴ� �Լ�
	int GetValue(); // ������ ���� ������ �����߱� ������ �����ְ� ���� �������ִ� �Լ��� �����Ѵ�.
};