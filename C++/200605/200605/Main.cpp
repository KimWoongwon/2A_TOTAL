#include "Factory.h"
// 팩토리 패턴에는 Factory Method와 Abstract Factory가 있다.
// Factory Method는 객체를 만들 인터페이스를 정의하지만 어떤 객체가 생성될지는 서브클래스에서 결정한다.
// Abstract Factory는 구체적인 클래스는 지정하지 않고 서로 관련있거나 독립적으로 움직이는 클래스들의 집합을 만들어준다.
// 메뉴 선택하는 함수
int DisplayMenu()
{
	int select;
	do
	{
		cout << "--------------------------------" << endl;
		cout << "<구매 가능 목록>" << endl;
		cout << "1. Pencil" << endl;
		cout << "2. Pen" << endl;
		cout << "3. Glue" << endl;
		cout << "4. Scissors" << endl;
		cout << "0. 종료" << endl;
		cin >> select;
		cout << "--------------------------------" << endl;
		if (select < 0 || select > 4)
			cout << "잘못된 입력입니다." << endl;
	} while (select < 0 || select > 4);
	return select;

}
// 구동함수
void Run()
{
	int Selection = 0;
	while (1)
	{
		Selection = DisplayMenu();
		Store* temp;	// 선택한 스토어를 담을 부모 클래스 (업캐스팅)
		switch (Selection)
		{
		case 0:
			return;
		case 1:
			temp = new PencilStore();
			temp->NewTool();	// temp는 Store클래스 이지만 현재 안에는 PencilStore가 들어있다. 따라서 Pencil의 함수들이 실행된다.
			delete temp;		// 지금은 바로 메모리를 해제 하지만 나중에는 이 물품들을 데이터베이스에 저장해도 될거같다.
			temp = nullptr;
			break;
		case 2:
			temp = new PenStore();
			temp->NewTool();
			delete temp;
			temp = nullptr;
			break;
		case 3:
			temp = new GlueStore();
			temp->NewTool();
			delete temp;
			temp = nullptr;
			break;
		case 4:
			temp = new ScissorsStore();
			temp->NewTool();
			delete temp;
			temp = nullptr;
			break;
		}
		
	}
}

int main(void)
{
	Run();

	return 0;
}