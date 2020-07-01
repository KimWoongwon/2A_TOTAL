#include "Management.h"

int main(void)
{
	Management* ungwon = new Management();
	ungwon->Run();
	delete ungwon;
	return 0;
}