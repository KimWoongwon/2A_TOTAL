#include "Management.h"

Management::Management()
{
	memset(this->list, 0, sizeof(this->list));
	cur = 0;
}
Management::~Management()
{
	for (int i = 0; i < cur; i++)
	{
		delete list[i];
	}
}
bool Management::Insert()
{
	/*if (this->list[cur] == 0)
		return false;*/

	char name[10];
	cout << "�̸� : ";
	cin >> name;

	char number[10];
	cout << "�й� : ";
	cin >> number;
	for (int i = 0; i < cur; i++)
	{
		if (!strcmp(this->list[i]->GetNumber(), number))
		{
			cout << "�ߺ��� �й��Դϴ�." << endl;
			return false;
		}
	}

	int grade[3];
	cout << "Cplus : ";
	cin >> grade[0];
	cout << "Csharp : ";
	cin >> grade[1];
	cout << "api : ";
	cin >> grade[2];
	
	this->list[cur] = new Student(name, number, grade);
	cur++;
	return true;
}
bool Management::Search()	//������ȸ
{
	int count = 0;
	char num[10];
	cout << "�й� : ";
	cin >> num;

	for (int i = 0; i < cur; i++)
	{
		if (!strcmp(list[i]->GetNumber(), num))
		{
			Display(i);
			return true;
		}
	}
	
	cout << "��ġ�ϴ� �й��� �����ϴ�." << endl;
	return false;
	
	
}
void Management::Display(int i)
{
	
	cout << "�̸� : " << this->list[i]->GetName() << endl;
	cout << "�й� : " << this->list[i]->GetNumber() << endl;
	cout << "Cplus : " << this->list[i]->GetGrade()->Cplus << endl;
	cout << "Csharp : " << this->list[i]->GetGrade()->Csharp << endl;
	cout << "api : " << this->list[i]->GetGrade()->api << endl;
	cout << "���� : " << this->list[i]->GetGrade()->total << endl;
	cout << "-----------------------" << endl;
}
void Management::Display_All()	//�������
{
	for (int i = 0; i < cur; i++)
	{
		
		cout << "�̸� : " << this->list[i]->GetName() << endl;
		cout << "�й� : " << this->list[i]->GetNumber() << endl;
		cout << "Cplus : " << this->list[i]->GetGrade()->Cplus << endl;
		cout << "Csharp : " << this->list[i]->GetGrade()->Csharp << endl;
		cout << "api : " << this->list[i]->GetGrade()->api << endl;
		cout << "���� : " << this->list[i]->GetGrade()->total << endl;
		cout << "-----------------------" << endl;
	}
}
void Management::Display_Menu()
{
	cout << "<������ȸ ���α׷�>" << endl;
	cout << "1. �����Է�" << endl;
	cout << "2. ������ȸ" << endl;
	cout << "3. �������" << endl;
	cout << "4. ����" << endl;
}
void Management::Run()
{
	bool EndFlag = true;
	int select = 0;
	do
	{
		Display_Menu();
		cout << "���� : ";
		cin >> select;
		cout <<"-----------------------"<< endl;
		select += 100;
		switch (select)
		{
		case ID_INSERT:
			Insert();
			break;
		case ID_SEARCH:
			Search();
			break;
		case ID_DISPLAY:
			Display_All();
			break;
		case ID_END:
			cout << "���α׷� ����" << endl;
			EndFlag = false;
			break;
		default:
			break;
		}
	} while (EndFlag);
}