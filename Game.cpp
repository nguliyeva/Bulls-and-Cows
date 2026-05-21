
#include "Game.h"

void vShowMenu(Game &game, Player &player);

Game::Game() :
		iDigit(0),
		sType("")
{
}

Game::Game(int digit, string type) :
	iDigit(digit),
	sType(type)
{
}

void Game::vSetDigit(string digit)
{
	string choice;

	if (digit == "a")
	{
		this->iDigit = 2;
		cout << endl;
	}
	else if (digit == "b")
	{
		this->iDigit = 3;
		cout << endl;
	}
	else if (digit == "c")
	{
		this->iDigit = 4;
		cout << endl;
	}
	else
	{
		cout << "Invalid choice! Please enter again (a/b/c): ";
		cin >> choice;
		vSetDigit(choice);
	}
}

void Game::vSetType(string type)
{
	string choice;

	if (type != "a" && type != "b")
	{
		cout << "Invalid choice! Please enter again (a/b): ";
		cin >> choice;
		vSetType(choice);
	}
	else
	{
		this->sType = type;
		cout << endl;
	}
}

int Game::iGetDigit() const
{
	return iDigit;
}

string Game::sGetType() const
{
	return sType;
}

string Game::sSecNumber()
{
	string num = "";
	int counter = 0;
	int randomNum = rand()%10;

	while (!randomNum)
	{
		randomNum = rand()%10;
	}

	cout << randomNum << endl;

	num = num + to_string(randomNum);

	bool repeat = true;

	while (counter < this->iDigit - 1)
	{
		while (repeat)
		{
			randomNum = rand()%10;

			for (int i = 0; i < num.length(); i++)
			{
				if (randomNum == (num[i] - '0'))
				{
					repeat = true;
					break;
				}
				else
				{
					repeat = false;
				}
			}
		}
		repeat = true;
		num = num + to_string(randomNum);
		counter++;
	}
	return num;
}

bool Game::bCheckNum(string sNumber)
{
	if (sNumber[0] == '0')
	{
		cout << "First digit shouldn't be zero! Please enter again: ";
		return false;
	}

	if (sNumber.length() != this->iDigit)
	{
		cout << "Number should be exactly " << this->iDigit << "-digit long! Please enter again: ";
		return false;
	}

    for (char c : sNumber)
    {
        if (!isdigit(c))
        {
            cout << "You can only enter digits! Please enter again: ";
            return false;
        }
    }

    for (int i = 0; i < sNumber.length(); i++)
    {
        for (int j = i + 1; j < sNumber.length(); j++)
        {
        	if (sNumber[i] == sNumber[j])
        	{
        		cout << "There should be no repeating digits! Please enter again: ";
        		return false;
        	}
        }
    }

    return true;
}

// Show prediction table for player
void Game::vShowTable(vector<string> myTable) const
{
	// myTable: 0rounds, 1guessP, 2bullP, 3cowP, 4rounds ...
	cout << setiosflags(ios::left) << setw(8) << "Round" << setw(14) << "Your guess" << setw(25) << "Result\n" << endl;

	for (int i = 0; i < myTable.size(); i += 4)
	{
		cout << setw(8) << myTable[i] << setw(14) << myTable[i+1] << setw(6) << "Bull: " << myTable[i+2] << setw(8) << " | Cow: " << myTable[i+3] << endl;
	}
	cout << endl;
	cout << resetiosflags(ios::left);
}

void Game::vShowRound(int counter)
{
	cout << "*" << string(38, '-') << "*" << endl;
	cout << "|" << setiosflags(ios::right) << setw(21) << "ROUND " << counter << setw(17) << "|" << endl; // 38/2 + string/2
	cout << "*" << string(38, '-') << "*" << endl;
	cout << resetiosflags(ios::right) << endl;
}

string Game::sDrawLine()
{
	return string(40, '-') + "\n";
}

void Game::vCalculateResult(int &bull, int &cow, string guessNum, string secretNum)
{
	// BULL: correct digit, correct position
	// COW: correct digit, wrong position 1234 5678
	bull = 0; cow =0;

	for (int i = 0; i < guessNum.length(); i++)
	{
		if (guessNum[i] == secretNum[i])
		{
			bull += 1;
		}
		else
		{
			for (int j = 0; j < secretNum.length(); j++)
			{
				if (guessNum[i] == secretNum[j])
				{
					cow += 1;
				}
			}
		}
	}

}

// YAZ
string Game::sCompGuess(int bull, int cow, string playerGuess)
{

	// lazimdi bullc cowc geussc
	return "1234";
}

void Game::vPlay(Player &player)
{
	string sPSecNumber; // Player's secret number BLEIBT KONSTANT
	string sCSecNumber = this->sSecNumber(); // Computer's secret number BLEIBT KONSTANT

	vector<string> vTable;

	// STEP 1: Entering secret numbers
	cout << "Game started! Computer already made his secret number!\n" << endl;
	cout << "Please enter your " << this->iDigit << "-digit secret number: ";
	cin >> sPSecNumber;

	while (!bCheckNum(sPSecNumber))
	{
		cin >> sPSecNumber;
	}
	cout << "\nSecret number saved!\n" << endl;
	cout << "\nComputer's secret number: "<< sCSecNumber << endl << endl; // SONRA SILERSEN!!!

	// STEP 2: Game starts

	int bullP = 0;
	int bullC = 0;
	int cowP = 0;
	int cowC = 0;
	int rounds = 1;

	bool winner = false;

	string guessP;
	string guessC;

	while (!winner)
	{
		vShowRound(rounds);

		// PLAYER'S TURN
		cout << "YOUR TURN\n" << sDrawLine();

		cout << "Your guess: ";
		cin >> guessP;
		while (!bCheckNum(guessP))
		{
			cin >> guessP;
		}

		vCalculateResult(bullP, cowP, guessP, sCSecNumber);

		cout << "\nResult: " << bullP << " Bulls | " << cowP << " Cows" << endl << endl;

		// COMPUTER'S TURN
		cout << "COMPUTER'S TURN\n" << sDrawLine();

		guessC = sCompGuess(bullP, cowP, guessP);

		cout << "Computer's guess: " << guessC << endl;

		vCalculateResult(bullC, cowC, guessC, sPSecNumber);

		cout << "\nResult: " << bullC << " Bulls | " << cowC << " Cows" << endl << endl;

		// HAS ANYONE WON?
		if (guessP == sCSecNumber && guessC == sPSecNumber)
		{
			cout << "CONGRATULATIONS! You both guessed correctly!\n\n" <<
					"Your secret number was: " << sPSecNumber << " (Computer found it!)\n" <<
					"Computer's secret number was: " << sCSecNumber << " (You found it!)\n\n" <<
					"Total number of rounds: " << rounds << endl << endl;

			cout << "Press Enter to return to Main Menu...";
		    cin.ignore();
		    cin.get();
			return vShowMenu(*this, player);
		}
		else if (guessP == sCSecNumber)
		{
			cout << "CONGRATULATIONS, " << player.sGetName() <<"! You guessed correctly!\n\n" <<
					"Your secret number was: " << sPSecNumber << " (Computer couldn't find it!)\n" <<
					"Computer's secret number was: " << sCSecNumber << " (You found it!)\n\n" <<
					"Total number of rounds: " << rounds << endl << endl;

			cout << "Press Enter to return to Main Menu...";
		    cin.ignore();
		    cin.get();
			return vShowMenu(*this, player);
		}
		else if (guessC == sPSecNumber)
		{
			cout << "Unfortunately, computer won! :(\n\n" <<
					"Your secret number was: " << sPSecNumber << " (Computer found it!)\n" <<
					"Computer's secret number was: " << sCSecNumber << " (You couldn't find it!)\n\n" <<
					"Total number of rounds: " << rounds << endl << endl;

			cout << "Press Enter to return to Main Menu..." << endl;
		    cin.ignore();
		    cin.get();
			return vShowMenu(*this, player);
		}
		else
		{
			cout << "Prediction History Table\n" << sDrawLine();

			vTable.push_back(to_string(rounds));
			vTable.push_back(guessP);
			vTable.push_back(to_string(bullP));
			vTable.push_back(to_string(cowP));

			vShowTable(vTable);
		}

		rounds++;
	}
}

Game::~Game()
{
}

