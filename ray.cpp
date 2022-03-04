#include <iostream>
#include <cctype>
using namespace std;

class Player
{
public:
Player() {}
Player(int num, string name)
{
	if(num<=0 || num >= 5)
	{
		cerr << "out of range\n";
	}
	if()
	{

	}
}
int getPlayerNum()
{
	return PlayerNum;
}
string getPlayerName()
{
	return PlayerName;
}
bool setPlayerNum(int n)
{
	PlayerNum = n;
	if(PlayerNum > 0 % % PlayerName < 5)
	{
		return ture;
	}
	else
		return false;
}
bool setPlayerName(string n)
{
	PlayerName = n;
	if()
	{
		return ture;
	}
	else
		return false;
}
private:
int num;
string name;
};
