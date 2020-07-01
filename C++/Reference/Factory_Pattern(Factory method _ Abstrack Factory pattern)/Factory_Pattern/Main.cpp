#include "Global.h"
#include "CheeseGimBabStore.h"

int main(void)
{
	CGimBabStore* store = new CCheeseGimBabStore();
	CGimBab* gimbab=store->OrderGimBab();
	delete store;
	delete gimbab;
	return 0;
}