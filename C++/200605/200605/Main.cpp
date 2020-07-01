#include "Factory.h"
// ���丮 ���Ͽ��� Factory Method�� Abstract Factory�� �ִ�.
// Factory Method�� ��ü�� ���� �������̽��� ���������� � ��ü�� ���������� ����Ŭ�������� �����Ѵ�.
// Abstract Factory�� ��ü���� Ŭ������ �������� �ʰ� ���� �����ְų� ���������� �����̴� Ŭ�������� ������ ������ش�.
// �޴� �����ϴ� �Լ�
int DisplayMenu()
{
	int select;
	do
	{
		cout << "--------------------------------" << endl;
		cout << "<���� ���� ���>" << endl;
		cout << "1. Pencil" << endl;
		cout << "2. Pen" << endl;
		cout << "3. Glue" << endl;
		cout << "4. Scissors" << endl;
		cout << "0. ����" << endl;
		cin >> select;
		cout << "--------------------------------" << endl;
		if (select < 0 || select > 4)
			cout << "�߸��� �Է��Դϴ�." << endl;
	} while (select < 0 || select > 4);
	return select;

}
// �����Լ�
void Run()
{
	int Selection = 0;
	while (1)
	{
		Selection = DisplayMenu();
		Store* temp;	// ������ ���� ���� �θ� Ŭ���� (��ĳ����)
		switch (Selection)
		{
		case 0:
			return;
		case 1:
			temp = new PencilStore();
			temp->NewTool();	// temp�� StoreŬ���� ������ ���� �ȿ��� PencilStore�� ����ִ�. ���� Pencil�� �Լ����� ����ȴ�.
			delete temp;		// ������ �ٷ� �޸𸮸� ���� ������ ���߿��� �� ��ǰ���� �����ͺ��̽��� �����ص� �ɰŰ���.
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