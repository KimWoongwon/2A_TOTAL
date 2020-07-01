#include "Global.h"
#include "Student.h"
//
//Grade::Grade(int p_val1, int p_val2, int p_val3)
//{
//	this->Cplus = p_val1;
//	this->Csharp = p_val2;
//	this->api = p_val3;
//}

Student::Student()
{
	memset(this->name, NULL, sizeof(this->name));
	memset(this->number, NULL, sizeof(this->number));
	this->grade = nullptr;
}
Student::Student(const char* p_name, const char* p_num, int* p_val)
{
	strcpy_s(this->name, p_name);
	strcpy_s(this->number, p_num);
	grade = new Grade();
	grade->Cplus = p_val[0];
	grade->Csharp = p_val[1];
	grade->api = p_val[2];
	this->SetTotal();
}
Student::~Student()
{
	if (grade != nullptr)
		delete grade;
}
char* Student::GetName()
{
	return this->name;
}
char* Student::GetNumber()
{
	return this->number;
}
Grade* Student::GetGrade()
{
	return this->grade;
}
void Student::SetTotal()
{
	double sum = 0;
	for (int i = 1; i <= 5; i++)
	{
		if ((grade->Cplus / 10) >= 10 - i)
		{
			sum += ((double)grade->Cplus / 10) - 5.0f;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if ((grade->Csharp / 10) >= 10 - i)
		{
			sum += ((double)grade->Csharp / 10) - 5.0f;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if ((grade->api / 10) >= 10 - i)
		{
			sum += ((double)grade->api / 10) - 5.0f;
			break;
		}
	}
	this->grade->total = (sum * 3.0f) / 9.0f;
	if ((sum * 3.0f) / 9.0f >= 5.0f)
		this->grade->total -= 1.0f;
}
