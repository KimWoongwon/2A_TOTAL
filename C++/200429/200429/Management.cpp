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
	cout << "이름 : ";
	cin >> name;

	char number[10];
	cout << "학번 : ";
	cin >> number;
	for (int i = 0; i < cur; i++)
	{
		if (!strcmp(this->list[i]->GetNumber(), number))
		{
			cout << "중복된 학번입니다." << endl;
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
bool Management::Search()	//성적조회
{
	int count = 0;
	char num[10];
	cout << "학번 : ";
	cin >> num;

	for (int i = 0; i < cur; i++)
	{
		if (!strcmp(list[i]->GetNumber(), num))
		{
			Display(i);
			return true;
		}
	}
	
	cout << "일치하는 학번이 없습니다." << endl;
	return false;
	
	
}
void Management::Display(int i)
{
	
	cout << "이름 : " << this->list[i]->GetName() << endl;
	cout << "학번 : " << this->list[i]->GetNumber() << endl;
	cout << "Cplus : " << this->list[i]->GetGrade()->Cplus << endl;
	cout << "Csharp : " << this->list[i]->GetGrade()->Csharp << endl;
	cout << "api : " << this->list[i]->GetGrade()->api << endl;
	cout << "평점 : " << this->list[i]->GetGrade()->total << endl;
	cout << "-----------------------" << endl;
}
void Management::Display_All()	//성적출력
{
	for (int i = 0; i < cur; i++)
	{
		
		cout << "이름 : " << this->list[i]->GetName() << endl;
		cout << "학번 : " << this->list[i]->GetNumber() << endl;
		cout << "Cplus : " << this->list[i]->GetGrade()->Cplus << endl;
		cout << "Csharp : " << this->list[i]->GetGrade()->Csharp << endl;
		cout << "api : " << this->list[i]->GetGrade()->api << endl;
		cout << "평점 : " << this->list[i]->GetGrade()->total << endl;
		cout << "-----------------------" << endl;
	}
}
void Management::Display_Menu()
{
	cout << "<성적조회 프로그램>" << endl;
	cout << "1. 성적입력" << endl;
	cout << "2. 성적조회" << endl;
	cout << "3. 성적출력" << endl;
	cout << "4. 종료" << endl;
}
void Management::Run()
{
	bool EndFlag = true;
	int select = 0;
	do
	{
		Display_Menu();
		cout << "선택 : ";
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
			cout << "프로그램 종료" << endl;
			EndFlag = false;
			break;
		default:
			break;
		}
	} while (EndFlag);
}