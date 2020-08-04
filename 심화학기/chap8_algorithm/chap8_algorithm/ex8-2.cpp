// 특정 돈을 가진 사용자 검색
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct User
{
	int money;
	int level;
};
struct FindMoneyUser	// 조건자
{
	int CompareMoney;
	bool operator()(User& user) const
	{
		return user.money == CompareMoney;
	}
};

void main()
{
	vector<User> Users;
	User user1; user1.level = 10; user1.money = 2000;
	User user2; user2.level = 5; user2.money = -10;
	User user3; user3.level = 20; user3.money = 35000;

	Users.push_back(user1);
	Users.push_back(user2);
	Users.push_back(user3);

	vector<User>::iterator FindIter;

	FindMoneyUser tFindMoneyUser;
	tFindMoneyUser.CompareMoney = 2000;

	FindIter = find_if(Users.begin(), Users.end(), tFindMoneyUser);

	if (FindIter != Users.end())
		cout << "소지하고 있는 돈은 : " << FindIter->money << "입니다" << endl;
	else
		cout << "유저가 없습니다." << endl;
}