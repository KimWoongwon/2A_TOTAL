#include "Global.h"

istream& operator>>(istream& i, MAIN_MENU& input)
{
	scanf_s("%d", &input);
	return i;
}

istream& operator>>(istream& i, LOGIN_MENU& input)
{
	scanf_s("%d", &input);
	return i;
}
istream& operator>>(istream& i, CHAR_MENU& input)
{
	scanf_s("%d", &input);
	return i;
}
istream& operator>>(istream& i, JOB& input)
{
	scanf_s("%d", &input);
	return i;
}