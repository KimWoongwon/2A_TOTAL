// for_each�� ����Ͽ� �������� �÷��� �ð� ����
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct User
{
	int UID;
	int PlayTime;
};
struct UpdatePlayTime	// ������
{
	int playtime;
	void operator()(User& user) const
	{
		user.PlayTime += playtime;
	}
};

void main()
{
	vector<User> Users;
	User user1; user1.UID = 1; user1.PlayTime = 40000;
	User user2; user2.UID = 2; user2.PlayTime = 40000;
	User user3; user3.UID = 3; user3.PlayTime = 40000;

	Users.push_back(user1);
	Users.push_back(user2);
	Users.push_back(user3);

	// ���� �÷��� �ð�
	vector<User>::iterator IterUser;
	for (IterUser = Users.begin(); IterUser != Users.end(); IterUser++)
		cout << "UID : " << IterUser->UID << "�� �� �÷��� �ð� : " << IterUser->PlayTime << endl;
	cout << endl;

	UpdatePlayTime tUpdatePlayTime;
	tUpdatePlayTime.playtime = 200;

	for_each(Users.begin() + 1, Users.end(), tUpdatePlayTime);

	for (IterUser = Users.begin(); IterUser != Users.end(); IterUser++)
		cout << "UID : " << IterUser->UID << "�� �� �÷��� �ð� : " << IterUser->PlayTime << endl;
	cout << endl;
}