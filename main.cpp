
#include <iostream>
#include <iomanip> // setw(), setprecision(), setiosflags()
#include <string>
#include "Game.h"
#include "Player.h"

using namespace std;

void vShowTitle()
{
	cout << "*" << string(38, '-') << "*" << endl;
	cout << "|" << setiosflags(ios::right) << setw(31) << "Welcome to Bulls & Cows!" << setw(8) << "|" << endl; // 38/2 + string/2
	cout << "*" << string(38, '-') << "*" << endl;
	cout << resetiosflags(ios::right) << endl;
}

void vStartGame(Game &game, Player &player)
{
	string choice;

	// Start Game Head
	cout << "\n*" << string(38, '-') << "*" << endl;
	cout << "|" << setiosflags(ios::right) << setw(24) << "Start Game" << setfill(' ') << setw(15) << "|" << endl;
	cout << "*" << string(38, '-') << "*" << endl;
	cout << resetiosflags(ios::right) << endl;

	// Player Inquiry
	cout << "How would you like to play?\n\n" <<
			"(a) Player vs Player\n" <<
			"(b) Player vs Computer\n" << endl;
	cout << "Your choice (a/b): ";
	cin >> choice;
	game.vSetType(choice);

	// Digits Inquiry
	cout << "How would you like to play?\n\n" <<
			"(a) Two digits  (e.g. 12)\n" <<
			"(b) Three digits (e.g. 123)\n" <<
			"(c) Four digits (e.g. 1234)\n" << endl;
	cout << "Your choice (a/b/c): ";
	cin >> choice;
	game.vSetDigit(choice);

	// Name Inquiry
	cout << "Let’s get started! What’s your name?\n" << endl;
	cout << "Enter: ";
	cin >> choice;
	player.vSetName(choice);

	game.vPlay(player);
}

void vShowInstructions()
{
	// Instructions Head
	cout << "\n*" << string(38, '-') << "*" << endl;
	cout << "|" << setiosflags(ios::right) << setw(25) << "Instructions" << setfill(' ') << setw(14) << "|" << endl;
	cout << "*" << string(38, '-') << "*" << endl;
	cout << resetiosflags(ios::right) << endl;

	// Objective?
	cout << "OBJECTIVE:\n" << Game::sDrawLine();
	cout << "Be the first player to guess your opponent's secret number.\n" <<
			"Your opponent can be either another player or the computer.\n\n" <<
			"- Each player (or the computer) secretly chooses a number\n" <<
			"- Players take turns guessing each other's numbers\n" <<
			"- After each guess, you get Bulls & Cows feedback\n" <<
			"- The first player to guess the opponent's number correctly wins!\n" << endl;

	// Number Rules?
	cout << "NUMBER RULES:\n" << Game::sDrawLine();
	cout << "- All digits must be different (no repeating numbers)\n" <<
			"- First digit cannot be zero\n" <<
			"- You must enter exactly the number of digits you selected\n" << endl;

	// Scoring System?
	cout << "SCORING SYSTEM:\n" << Game::sDrawLine();
	cout << "After each guess, you receive feedback:\n\n" <<
			"BULL:\n" <<
			"- Correct digit in the CORRECT position\n" <<
			"- Example: Secret: 1234, Guess: 1534 → 3 Bulls (1,3,4)\n\n" <<
			"COW:\n" <<
			"- Correct digit but WRONG position\n" <<
			"- Example: Secret: 1234, Guess: 4321 → 4 Cows\n" << endl;


	cout << "Good Luck! :)\n" << endl;
	cout << "Press Enter to return to menu...\n";
    cin.ignore();
    cin.get();
}

void vShowMenu(Game &game, Player &player)
{
	int choice;

	cout << "MENU:\n" << Game::sDrawLine();
	cout << "(1) " << "Start Game" << endl;
	cout << "(2) " << "Instructions" << endl;
	cout << "(3) " << "Exit" << endl;

	cout << "\nSelect: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		vStartGame(game, player);
		break;
	case 2:
		vShowInstructions();
		return vShowMenu(game, player);
	case 3:
		cout << "\nGame exited.\n" << endl;
		break;
	default:
		cout << "\nInvalid choice! Please enter 1, 2, or 3.\n\n" << endl;
		return vShowMenu(game, player);
	}
}

int main()
{
	srand(time(NULL));
	Game *game = new Game();
	Player *p1 = new Player();
	vShowTitle();
	vShowMenu(*game, *p1);
	return 0;
}

