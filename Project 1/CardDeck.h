#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
#include "Card.h"// need this to use the card type

using namespace std;

const int DECK_SIZE = 52 ;
class CardDeck
{
public:
	CardDeck();//constructor
	//void displayCardAt(int);//display the card at particular location (array index)
	Card deal();//deal a card-return the point value of the card
	int cardsLeft();//how many cards are left in the deck
	void shuffle();//shuffle the cards in the deck
	void PrintDeck();//print the contents of the deck

private:

	int mCardCount;
	Card mCards[DECK_SIZE];//An array of 52 cards
};

