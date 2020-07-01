#include "Global.h"

istream& operator>>(istream& i, MAIN_MENU& input)
{
	scanf_s("%d", &input, sizeof(MAIN_MENU));
	return i;
}

istream& operator>>(istream& i, LOGIN_MENU& input)
{
	scanf_s("%d", &input, sizeof(LOGIN_MENU));
	return i;
}