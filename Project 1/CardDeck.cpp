#include "CardDeck.h"
#include "Card.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

CardDeck::CardDeck() : mCardCount(DECK_SIZE) {
	//initializing the array
	int index = 0;
	for (int s = 0; s < 4; s++) { //4 suit
		for (int k = 2; k <= 14; k++) { //ranks
			mCards[index].setRank(k);
			mCards[index].setSuit(s);
			index++;
		}
	}
}

int CardDeck::cardsLeft() {
	return mCardCount;
}

 Card CardDeck::deal() {
	//if (!isEmpty())
	return mCards[--mCardCount];
}

void CardDeck::shuffle() {
	for (int i = mCardCount - 1; i >= 1; i--) {
		int j = rand() % (i + 1);
		Card temp = mCards[j];
		mCards[j] = mCards[i];
		mCards[i] = temp;
	}
}

void CardDeck::PrintDeck()  {
	for (int i = 0; i < mCardCount; i++) {
		cout << mCards[i].toString() << "; ";
	}
	cout << endl;
}