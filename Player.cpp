
#include "Player.h"

Player::Player() :
	sName(""),
	iScore(0)
{
}

Player::Player(string name, int score) :
		sName(name),
		iScore(score)
{
}

void Player::vSetName(string name)
{
	if (name.empty())
	{
		this->sName = "Player";
		return;
	}

	if (name.length() > 20)
	{
	    cout << "Name is too long! Please enter again: ";
	    cin >> name;
	    vSetName(name);
	    return;
	}

	this->sName = name;
	cout << endl;
}

void Player::vSetScore(int score)
{
	this->iScore = score;
	cout << endl;
}

string Player::sGetName() const
{
	return sName;
}

int Player::iGetScore() const
{
	return iScore;
}

Player::~Player()
{
}

