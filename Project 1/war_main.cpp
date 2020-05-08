/* Shinesunny Som
 Class: CECS 282
 Prog 1 - WAR Game
 Inst: Steve Gold
 M/W 5P-7:15P
 Due: 2/8/16
 */

#include <iostream>
#include <string>
#include "Card.h"
#include "CardDeck.h"
#include <time.h>

using namespace std;
void playWar(void);
void option(void);
CardDeck d1;
Card tempCard;

int main() {
	//srand(time(0));
	int exit = 1;
	while (exit == 1){
		int selections;
		cout << "This...is 'WAR'. WAR Game, select an option!" << endl;
		cout << "1: Get a new Deck\n";
		cout << "2: Show all cards in Deck\n";
		cout << "3: Shuffle Deck\n";
		cout << "4: Play WAR!\n";
		cout << "5: Exit\n";
		cin >> selections; // User input the 5 selections

		switch (selections) { // switch cases, 1-5

		case 1:{ // Creates a new deck, even if it already has been created.
			d1=CardDeck();
			cout << "A NEW deck is created!" << endl;
			cout << endl;
			break; // To make sure no other option are selectable and conflicts.
		}
		case 2:{
			cout << "The following cards are the ones left in the deck you're playing with..." << d1.cardsLeft() << endl;
			d1.PrintDeck();
			cout << endl;
			break;
		}
		case 3: {
			
			cout << "The deck has been shuffled. :O" << endl;
			cout << endl;
			d1.shuffle();
			cout << "This deck has been already shuffled. :D" << endl;
			d1.PrintDeck();
			cout << endl;
			break;
		}
		case 4:{
			playWar();
			break;
		}
		case 5:{
			return 0;
			break;
		}
		default: {
			if (selections != 5) {
				cout << " Invalid option, choose only option 1 through 5 please! >:(";
				cout << endl;
				break;
			}
		}
		}//exit switch statement
	}//exit while loop

	system("PAUSE");
}
void playWar(){
	char again = 'y';
	int gameCounter = 0;
	
		do {
		
		if (gameCounter < 13) { // 52 cards divides 4 cards = 13
			int mPlayerOne = 0, mPlayerTwo = 0;
			int mCompOne = 0, mCompTwo = 0, playerSum = 0, compSum = 0;
			cout << "Get ready to play WAR!! Comparing with TWO cards." << endl;
			cout << "" << endl;
			cout << "There are 52 cards in the deck." << endl;
			cout << ".....dealing..." << endl;
		
			cout << " A card for the player..." << endl;
			cout << endl;
			tempCard = d1.deal();
			tempCard.displayCard();
			mPlayerOne = tempCard.score();

			cout << " A second card for the player..." << endl;
			cout << endl;
			tempCard = d1.deal();
			tempCard.displayCard();
			mPlayerTwo = tempCard.score();

			cout << " A card for the evil computer..." << endl;
			cout << endl;
			tempCard = d1.deal();
			tempCard.displayCard();
			mCompOne = tempCard.score();

			cout << " A second card for the evil computer..." << endl;
			cout << endl;
			tempCard = d1.deal();
			tempCard.displayCard();
			mCompTwo = tempCard.score();

			playerSum = mPlayerOne + mPlayerTwo;
			compSum = mCompOne + mCompTwo;

			cout << "Player has: " << playerSum << " points." << endl;
			cout << "Computer has: " << compSum << " points." << endl;
			cout << endl;

			if (playerSum < compSum) {
				cout << "REKT'd....the computer wins. You LOSE." << endl;
				cout << endl;
			}
			else if (playerSum > compSum) {
				cout << "Take that evil computer!! You WIN." << endl;
				cout << endl;
			}
			else if (playerSum = compSum) {
				cout << "What?! It's a TIE, folks." << endl;
				cout << endl;
			}

			cout << "There are : " << d1.cardsLeft() << "cards left" << endl; //Number of cards left.
			cout << endl;
			cout << endl;
			gameCounter++;
		}
		else {
			cout << "You have ran out of cards, please create another deck :)" << endl;
			cout << "" << endl;
		}
		cout << "Would you like to play again? (y/n)" << endl;
		cin >> again;

	} while (again != 'n');
	cout << endl;

}