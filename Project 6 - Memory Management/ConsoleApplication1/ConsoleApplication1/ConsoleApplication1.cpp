// Shinesunny Som
// Class: CECS 282
// Prog 1 - Shell Game
// Inst: Steve Gold
// Tu/Th 7:30P-9:45P
// 9/15/15

#include "stdafx.h" //Compiles
#include "stdlib.h" //Headers
#include "stdio.h"  
#include <iostream> //input output
#include "time.h";

using namespace std;
int mainMenu();
int hidePeanut();
int showShells(int);
int main(void) {
	int gamesPlayed = 0;
	int gamesWon = 0;
	int gamesLost = 0;
	while (true) {
		if (mainMenu() == 2) {
			cout << "Statistics" "\n";
			cout << "Games Played: " << gamesPlayed << "\n";
			cout << "Games Won: " << gamesWon << "\n";
			cout << "Games Lost: " << gamesLost << "\n";
			if (gamesPlayed > 0) {
				cout << "You won " << (gamesWon * 100) / gamesPlayed << "\% of the games.\n \n Thanks for playing! :)\n";
				int c = 1, d = 1; //delays for 5 secs to read stats

				for (c = 1; c <= 32767; c++)
					for (d = 1; d <= 32767; d++)
					{
					}

				return 0;
			}
			break;
		}
		gamesPlayed++;
		/*
		int mainMenu() { //Selection screen, information
		cout << "Main Menu\n1) Play the Shell Game\n2) Exit\n \n Your stats will display when you exit the game.\n Please use only numbers when selecting a choice.\n";
		int userInput;
		int valid = false;
		while (!valid) {
		cin >> userInput;
		if (userInput == 1 || userInput == 2) {
		valid = true;
		}
		else {
		cout << "Invalid input. Try again.\n";
		return 0;
		}
		}
		return userInput;
		}
		*/
		int peanut = hidePeanut();
		if (showShells(0) == peanut) {
			cout << "[YOU WIN] Looks like the RNG God forgives you, You found the peanut!\n\n";
			if (peanut == 3) {
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "\n";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "\n";
				cout << "/  "  " "  "  \\";
				cout << "    ";
				cout << "/  " " "  "  \\";
				cout << "    ";
				cout << "/  " "#"  "  \\";
				cout << "\n";
			}
			if (peanut == 2) {
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "\n";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "\n";
				cout << "/  "  " "  "  \\";
				cout << "    ";
				cout << "/  " "#"   "  \\";
				cout << "    ";
				cout << "/  " " "  "  \\";
				cout << "\n";
			}
			if (peanut == 1) {
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "\n";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "\n";
				cout << "/ "  " # "  " \\";
				cout << "    ";
				cout << "/  " " "   "  \\";
				cout << "    ";
				cout << "/  " " "  "  \\";
				cout << "\n";
			}
			gamesWon++;

		}
		else {

			cout << "[YOU LOSE] Seems like the RNG God doesn't like you...it was under shell " << peanut << ".\n\n";
			if (peanut == 3) {
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "\n";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "\n";
				cout << "/  "  " "  "  \\";
				cout << "    ";
				cout << "/  " " "  "  \\";
				cout << "    ";
				cout << "/  " "#"  "  \\";
				cout << "\n";
			}
			if (peanut == 2) {
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "\n";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "\n";
				cout << "/  "  " "  "  \\";
				cout << "    ";
				cout << "/  " "#"   "  \\";
				cout << "    ";
				cout << "/  " " "  "  \\";
				cout << "\n";
			}
			if (peanut == 1) {
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "    ";
				cout << "  ___  ";
				cout << "\n";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "    ";
				cout << " /   \\ ";
				cout << "\n";
				cout << "/ "  " # "  " \\";
				cout << "    ";
				cout << "/  " " "   "  \\";
				cout << "    ";
				cout << "/  " " "  "  \\";
				cout << "\n";
			}

			gamesLost++;
		};
	}
	return 0;
}
int mainMenu() {
	cout << "Main Menu\n1) Play the Shell Game\n2) Exit\n";
	int userInput;
	int valid = false;
	while (!valid) {
		cin >> userInput;
		if (userInput == 1 || userInput == 2) {
			valid = true;
		}
		else {
			cout << "Invalid input. Try again:\n";
			return 0;
		}
	}
	return userInput;
}
int hidePeanut() {
	srand(time(NULL));
	return rand() % 3 + 1;
}
int showShells(int peanut) {
	string a, b, c;
	switch (peanut) {
	case 0:
		a = "1"; b = "2"; c = "3";
		break;
	case 1:
		a = "#"; b = " "; c = " ";
		break;
	case 2:
		a = " "; b = "#"; c = " ";
		break;
	case 3:
		a = " "; b = " "; c = "#";
		break;
	}

	cout << "  ___  ";
	cout << "    ";
	cout << "  ___  ";
	cout << "    ";
	cout << "  ___  ";
	cout << "\n";
	cout << " /   \\ ";
	cout << "    ";
	cout << " /   \\ ";
	cout << "    ";
	cout << " /   \\ ";
	cout << "\n";
	cout << "/  "  "1"  "  \\";
	cout << "    ";
	cout << "/  " "2"   "  \\";
	cout << "    ";
	cout << "/  " "3"  "  \\";
	cout << "\n";
	if (peanut == 0) {
		cout << "[From 1-3] Choose a shell:\n";
		int userInput;
		while (true) {
			cin >> userInput;
			if (userInput >= 1 && userInput <= 3) {
				break;
			}
			else {
				cout << "Invalid Input. Please Try again.\n";
			}
		}
		return userInput;
	}
	else {
		return 0;
	}
}