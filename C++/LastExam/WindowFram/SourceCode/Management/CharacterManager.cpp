#include "CharacterManager.h"
#include "../Character/Elf/ElfFactory.h"
#include "../Character/Orc/OrcFactory.h"
#include "../Character/Human/HumanFactory.h"

CCharacterManager::CCharacterManager(char* pname)
{
	strcpy_s(UserName, sizeof(UserName), pname);
	mCharacterList = new CLinkedList<Character*>;
	mData = nullptr;
	CharacterListCount = 0;
}
CCharacterManager::~CCharacterManager()
{
	SaveInfo();
	delete mCharacterList;
}
void CCharacterManager::Initialize() // ���Ͽ��� ĳ�������� ��������
{
	ifstream File;
	char filestr[100];
	wsprintf(filestr, "UserCharacter_%s.txt", UserName);
	File.open(filestr, ios::app);

	char temparr[256];
	char* name;
	char* region;
	char* Class;

	Character* tempChar = nullptr;
	CharacterFactory* charFactory;
	CLASS cls;
	if (File.is_open())
	{
		while (!File.eof())
		{
			File.getline(temparr, 256);
			if (!strcmp(temparr, ""))
				break;

			name = strtok(temparr, "|");
			region = strtok(NULL, "|");
			Class = strtok(NULL, "|");

			if (!strcmp(region, "�ΰ�"))
				charFactory = new HumanFactory();
			else if(!strcmp(region, "��ũ"))
				charFactory = new OrcFactory();
			else if (!strcmp(region, "����"))
				charFactory = new ElfFactory();

			if (!strcmp(Class, "����"))
				cls = CLASS::WARRIOR;
			else if (!strcmp(Class, "�ü�"))
				cls = CLASS::ARCHER;
			else if (!strcmp(Class, "������"))
				cls = CLASS::SORCERER;

			tempChar = charFactory->SettingCharacter(name, cls);
			mCharacterList->Insert(tempChar);
			CharacterListCount++;
		}
	}

	File.close();
}
void CCharacterManager::SaveInfo() // ���Ͽ� ĳ�������� �����ϱ�
{
	ofstream File;
	char filestr[100];
	wsprintf(filestr, "UserCharacter_%s.txt", UserName);
	File.open(filestr);
	File.clear();
	string temp;

	CNode<Character*>* ptr = mCharacterList->GetmHead();
	Character* data = nullptr;
	if (File.is_open())
	{
		do
		{
			ptr = ptr->GetmNext();
			data = ptr->GetmData();
			if (data == nullptr)
				break;
			temp += data->GetName();
			temp += "|";
			temp += data->GetRegion();
			temp += "|";
			temp += data->GetClass();
			temp += "|";
			temp += "\n";

			File.write(temp.c_str(), temp.size());
			temp = "";

		} while (ptr->GetmNext() != NULL);
		
	}
	
	File.close();
}
bool CCharacterManager::Input(Character* data)
{
	mCharacterList->Insert(data);
	CharacterListCount++;
	return true;
}

bool CCharacterManager::Delete(Character* data)
{
	bool result = false;

	result = mCharacterList->Delete(data);
	if (result)
		CharacterListCount--;

	return result;
}

bool CCharacterManager::GetData(Character** _char)
{

	if (!mData)
	{
		mData = mCharacterList->GetmHead()->GetmNext();
	}
	else
	{
		mData = mData->GetmNext();
	}

	if (mData)
	{
		*_char = mData->GetmData();
		return true;
	}

	return false;
}

void CCharacterManager::GetDataEnd()
{
	mData = nullptr;
}

int	 CCharacterManager::GetCount()
{
	return CharacterListCount;
}
