#include "CUser.h"

CUser::CUser(const char* _id, const char* _pw)
{
	
	strcpy_s(mId, sizeof(mId), _id);
	strcpy_s(mPw, sizeof(mPw), _pw);
	mLoginState = false;
	for (int i = 0; i < MAX_CHARACTER; i++)
		CharList[i] = nullptr;
	CharCount = 0;
}

CUser::~CUser()
{

}

const char* CUser::GetId()
{
	return mId;
}

const char* CUser::GetPw()
{
	return mPw;
}

bool CUser::GetLoginState()
{
	return mLoginState;
}
Character* CUser::GetChar(int pIndex)
{
	return CharList[pIndex];
}
int CUser::GetCount()
{
	return CharCount;
}

bool CUser::SetId(const char* _id)
{
	strcpy_s(mId, sizeof(mId), _id);
	return true;
}

bool CUser::SetPw(const char* _pw)
{
	strcpy_s(mPw, sizeof(mPw), _pw);
	return true;
}

void CUser::SetLogin()
{
	mLoginState = true;
}

void CUser::SetLogout()
{
	mLoginState = false;
}

void CUser::InsertCharacter(Character* p_char)
{
	CharList[CharCount++] = p_char;
}

void CUser::RemoveCharacter(const char* p_name)
{
	int index = 0;
	for (int i = 0; i < CharCount; i++)
	{
		if (!strcmp(CharList[i]->GetName(), p_name))
		{
			index = i;
			break;
		}
	}
	if(CharList[index] != nullptr)
		delete CharList[index];
	if (index == CharCount)
		return;
	for (int i = index; i < MAX_CHARACTER - 1; i++)
	{
		CharList[i] = CharList[i + 1];
	}
	CharList[MAX_CHARACTER - 1] = nullptr;
	CharCount--;
	return;
}
void CUser::DisplayCharacterInfo(bool flag)
{
	cout << "------------------------" << endl;
	if (CharCount <= 0)
	{
		cout << "생성된 캐릭터가 없습니다." << endl;
		cout << "------------------------" << endl;
		return;
	}
	for (int i = 0; i < CharCount; i++)
	{
		cout << "이름 : " << CharList[i]->GetName() << endl;
		cout << "종족 : " << CharList[i]->GetKind() << endl;
		cout << "직업 : " << CharList[i]->GetJOB() << endl << endl;
		cout << "레벨 : " << CharList[i]->GetLevel() << endl;

		cout << "HP : " << CharList[i]->GetStatus()->Hp << "  (" << 
			CharList[i]->GetWeapon()->GetStatus()->Hp << ")/(" <<
			CharList[i]->GetArmor()->GetStatus()->Hp << ")" << endl;
		cout << "MP : " << CharList[i]->GetStatus()->Mp << "  (" << 
			CharList[i]->GetWeapon()->GetStatus()->Mp << ")/(" <<
			CharList[i]->GetArmor()->GetStatus()->Mp << ")" << endl;
		cout << "공격력 : " << CharList[i]->GetStatus()->ATK << "  (" << 
			CharList[i]->GetWeapon()->GetStatus()->ATK << ")/(" <<
			CharList[i]->GetArmor()->GetStatus()->ATK << ")" << endl;
		cout << "방어력 : " << CharList[i]->GetStatus()->DEF << "  (" << 
			CharList[i]->GetWeapon()->GetStatus()->DEF << ")/(" <<
			CharList[i]->GetArmor()->GetStatus()->DEF << ")" << endl;

		cout << "펫 종류 : " << CharList[i]->GetPetkind() << endl << endl;

		cout << "<세부착용정보>" << endl;
		cout << "- 무기 -------" << endl;
		cout << "\t이름 : " << CharList[i]->GetWeapon()->GetName() << endl;
		if (flag)
		{
			cout << "\t스텟 : " << endl;
			cout << "\tHP : " << CharList[i]->GetWeapon()->GetStatus()->Hp << endl;
			cout << "\tMP : " << CharList[i]->GetWeapon()->GetStatus()->Mp << endl;
			cout << "\tATK : " << CharList[i]->GetWeapon()->GetStatus()->ATK << endl;
			cout << "\tDEF : " << CharList[i]->GetWeapon()->GetStatus()->DEF << endl;
			cout << "\t가격 : " << CharList[i]->GetWeapon()->GetPrice() << endl;
		}

		cout << "- 방어구 -------" << endl;
		cout << "\t이름 : " << CharList[i]->GetArmor()->GetName() << endl;
		if (flag)
		{
			cout << "\t스텟 : " << endl;
			cout << "\tHP : " << CharList[i]->GetArmor()->GetStatus()->Hp << endl;
			cout << "\tMP : " << CharList[i]->GetArmor()->GetStatus()->Mp << endl;
			cout << "\tATK : " << CharList[i]->GetArmor()->GetStatus()->ATK << endl;
			cout << "\tDEF : " << CharList[i]->GetArmor()->GetStatus()->DEF << endl;
			cout << "\t가격 : " << CharList[i]->GetArmor()->GetPrice() << endl;
		}
		

		cout << "------------------------" << endl;
	}
	
	
}