#pragma once

#include "../Global.h"
#include "../Character/Character.h"
// ������ ĳ���� ����Ʈ�� �����ϴ� �Ŵ��� Ŭ����
// �������� �ϳ��� �����Ǵ� Ŭ����
class CCharacterManager
{
private:
	char UserName[20];							// �� ��ü�� ������ �˾ƺ��� ���� �̸�
	CLinkedList<Character*>* mCharacterList;	// ĳ���� ����Ʈ
	CNode<Character*>* mData;					// ĳ���͸� �ܺη� �ϳ��� �Ѱ��ֱ� ���� ���
	
	int CharacterListCount;						// �� ĳ���� ��
public:
	CCharacterManager(char* pname);				// ĳ���� ����Ʈ ������ : �ش� ĳ���� ����Ʈ�� ���� ������ �̸��� ���� �Ű�����
	~CCharacterManager();	

	void Initialize();							// �ʱ�ȭ : ���Ͽ��� �о���°� ����
	void SaveInfo();							// �ش� ����Ʈ�� ��� ������ ���Ͽ� �����ϴ� �Լ�
	bool Input(Character*);						// �ܺο��� ĳ���� ������ ĳ���͸� ����Ʈ �ȿ� �־��ִ� �Լ�
	bool Delete(Character*);					// �ܺο��� ĳ���� ������ �Ű������� �Ѱܹ��� ĳ���͸� ã�Ƽ� �������ִ� �Լ�
	bool GetData(Character**);					// �ܺο��� �˻��� �ʿ��� ��� �Ѱ��� �����͸� �Ѱ��ִ� �Լ�
	void GetDataEnd();							// �ܺο��� �˻��� ��ġ���� �ʱ�ȭ�� ���� �Լ�
	int	 GetCount();							// ĳ������ �� ��ȯ �Լ�

};