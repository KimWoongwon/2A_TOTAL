#include "VeggieGimBabStore.h"

CVegetableGimBabStore::CVegetableGimBabStore()
{
	memset(mVegetableGimbabMenu, 0, sizeof(mVegetableGimbabMenu));
	mCount = 0;

	mVegetableGimbabMenu[mCount++] = new CGimBabStore::Menu("¥Á±Ÿ∏π¿∫ æﬂ√§±Ëπ‰", 3000);
	mVegetableGimbabMenu[mCount++] = new CGimBabStore::Menu("ø¨±Ÿ∏π¿∫ æﬂ√§±Ëπ‰", 4000);
	mVegetableGimbabMenu[mCount++] = new CGimBabStore::Menu("∞Ì√ﬂ∏π¿∫ æﬂ√§±Ëπ‰", 3500);
}

CVegetableGimBabStore::~CVegetableGimBabStore()
{
	for (int i = 0; i < mCount; i++)
	{
		if (mVegetableGimbabMenu[i] != nullptr)
		{
			delete mVegetableGimbabMenu[i];
		}
	}

	cout << "æﬂ√§ ±Ëπ‰∞°∞‘∞° πÆ¿ª ¥›Ω¿¥œ¥Ÿ. " << endl;
}

CGimBab* CVegetableGimBabStore::CreateGimBab(const char* _name, int _price)
{
	cout << "<<±Ëπ‰¡˝ º±≈√ >>" << endl;
	cout << "1. ±Ëπ‰√µ±π" << endl;
	cout << "2. ∞Ì∫¿πŒ±Ëπ‰" << endl;

	int select;
	cin >> select;

	CIngredientFactory* factory = nullptr;

	switch (select)
	{
	case 1:
		factory = new CGimBabHeavenFactory();
		break;
	case 2:
		factory = new CGoBongMinGimBabFactory();
	}

	CGimBab* gimbab = new CVegetableGimBab(_name, _price, factory);

	return gimbab;
}

CGimBabStore::Menu* CVegetableGimBabStore::MenuSelect()
{
	cout << "<<æﬂ√§ ±Ëπ‰ ∏ﬁ¥∫ >>" << endl;

	for (int i = 0; i < mCount; i++)
	{
		cout << i + 1 << ". " << mVegetableGimbabMenu[i]->gimbab_name << "  ∞°∞›:" << mVegetableGimbabMenu[i]->price << endl;
	}

	int select;
	cin >> select;

	return mVegetableGimbabMenu[select-1];

}
CGimBab* CVegetableGimBabStore::WrapGimBab(CGimBab* _gimbab)
{
	cout << "æﬂ√§ ±◊∏≤¿« ∆˜¿Â¡ˆ∑Œ ±Ëπ‰¿ª ΩŒ∞Ì æﬂ√§Ω∫∆º∞≈∏¶ ∫Ÿ¿‘¥œ¥Ÿ. " << endl;
	return _gimbab;
}