
#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:

	string sName;
	int iScore;

public:

	Player();
	Player(string name, int score);
	void vSetName(string name);
	void vSetScore(int score);
	string sGetName() const;
	int iGetScore() const;
	virtual ~Player();
};

#endif /* PLAYER_H_ */
