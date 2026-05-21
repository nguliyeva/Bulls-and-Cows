
#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>
#include <iomanip> // setw(), setprecision(), setiosflags()
#include <vector>

#include <cstdlib> // srand, rand
#include <ctime> // time
#include <cctype> // isdigit

#include "Player.h"

using namespace std;

class Game
{
private:

	int iDigit;
	string sType;

public:

	Game();
	Game(int digit, string type);
	void vSetDigit(string digit);
	void vSetType(string type);
	int iGetDigit() const;
	string sGetType() const;
	string sSecNumber();
	bool bCheckNum(string sNumber);
	void vShowTable(vector<string> myTable) const;
	void vShowRound(int counter);
	static string sDrawLine();
	void vCalculateResult(int &bull, int &cow, string guessNum, string secretNum);
	string sCompGuess(int bull, int cow, string playerGuess);
	void vPlay(Player &player);
	virtual ~Game();
};

#endif /* GAME_H_ */
