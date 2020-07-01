#pragma once
struct Grade
{
	int Cplus = 0;
	int Csharp = 0;
	int api = 0;
	double total = 0;
	//Grade(int p_val1, int p_val2, int p_val3);
};
class Student
{
private:
	char name[20];
	char number[20];
	Grade* grade;
public:
	Student();
	Student(const char* p_name, const char* p_num, int* p_val);
	~Student();
	char* GetName();
	char* GetNumber();
	Grade* GetGrade();
	void SetTotal();
};

