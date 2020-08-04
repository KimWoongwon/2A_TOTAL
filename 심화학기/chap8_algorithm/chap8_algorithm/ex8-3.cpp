// for_each를 사용하여 유저들의 플레이 시간 갱신
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct User
{
	int UID;
	int PlayTime;
};
struct UpdatePlayTime	// 조건자
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

	// 현재 플레이 시간
	vector<User>::iterator IterUser;
	for (IterUser = Users.begin(); IterUser != Users.end(); IterUser++)
		cout << "UID : " << IterUser->UID << "의 총 플레이 시간 : " << IterUser->PlayTime << endl;
	cout << endl;

	UpdatePlayTime tUpdatePlayTime;
	tUpdatePlayTime.playtime = 200;

	for_each(Users.begin() + 1, Users.end(), tUpdatePlayTime);

	for (IterUser = Users.begin(); IterUser != Users.end(); IterUser++)
		cout << "UID : " << IterUser->UID << "의 총 플레이 시간 : " << IterUser->PlayTime << endl;
	cout << endl;
}