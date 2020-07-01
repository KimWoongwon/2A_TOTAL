#include "CheeseGimBabStore.h"

CCheeseGimBabStore::CCheeseGimBabStore()
{
	memset(mCheeseGimbabMenu, 0, sizeof(mCheeseGimbabMenu));
	mCount = 0;

	mCheeseGimbabMenu[mCount++] = new CGimBabStore::Menu("Ʈ���� ġ����", 3000);
	mCheeseGimbabMenu[mCount++] = new CGimBabStore::Menu("���̾�Ʈ ġ����", 4000);
	mCheeseGimbabMenu[mCount++] = new CGimBabStore::Menu("Ÿ�̰��� ġ����", 3500);

}
CCheeseGimBabStore::~CCheeseGimBabStore()
{
	for (int i = 0; i < mCount; i++)
	{
		if (mCheeseGimbabMenu[i] != nullptr)
		{
			delete mCheeseGimbabMenu[i];
		}
	}

	cout << "ġ�� ��䰡�԰� ���� �ݽ��ϴ�. " << endl;
}

CGimBab* CCheeseGimBabStore::CreateGimBab(const char* _name, int _price)
{
	cout << "<<����� ���� >>" << endl;
	cout << "1. ���õ��" << endl;
	cout << "2. ����α��" << endl;

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


	CGimBab* gimbab = new CCheeseGimBab(_name, _price, factory);
	return gimbab;
}

CGimBabStore::Menu* CCheeseGimBabStore::MenuSelect()
{
	cout << "<<ġ�� ��� �޴� >>" << endl;
	
	for (int i = 0; i < mCount; i++)
	{
		cout << i + 1 << ". " << mCheeseGimbabMenu[i]->gimbab_name << "  ����:" << mCheeseGimbabMenu[i]->price << endl;
	}

	int select;
	cin >> select;

	return mCheeseGimbabMenu[select-1];
}

CGimBab* CCheeseGimBabStore::WrapGimBab(CGimBab* _gimbab)
{
	cout << "ġ�� �׸��� �������� ����� �ΰ� ġ�Ƽ�Ÿ� ���Դϴ�. " << endl;
	return _gimbab;
}