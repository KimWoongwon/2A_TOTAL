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
void CCharacterManager::Initialize() // 파일에서 캐릭터정보 가져오기
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

			if (!strcmp(region, "인간"))
				charFactory = new HumanFactory();
			else if(!strcmp(region, "오크"))
				charFactory = new OrcFactory();
			else if (!strcmp(region, "엘프"))
				charFactory = new ElfFactory();

			if (!strcmp(Class, "전사"))
				cls = CLASS::WARRIOR;
			else if (!strcmp(Class, "궁수"))
				cls = CLASS::ARCHER;
			else if (!strcmp(Class, "마법사"))
				cls = CLASS::SORCERER;

			tempChar = charFactory->SettingCharacter(name, cls);
			mCharacterList->Insert(tempChar);
			CharacterListCount++;
		}
	}

	File.close();
}
void CCharacterManager::SaveInfo() // 파일에 캐릭터정보 저장하기
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
