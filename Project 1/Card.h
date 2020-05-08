#ifndef _CARD_H
#define _CARD_H
#pragma once //Current source file to be included only once in a single compilation
#include <iostream>
#include <string>

using namespace std;

class Card
{
public:
	
	Card();// default constructor
	Card(char suit, char rank);// constructor taking two parameters

	//return the point value of the card. Ace = 1, 2 through 10, face cards = 10.
	int getValue() const;

	string toString() const;
	void displayCard();
	int score();

	//compare this card to another, decide which is "bigger" for WAR rules
	int compareCard(const Card &other);

	void setRank(char rank);
	void setSuit(char suit);

private:
	char rankValue; //the suite of the card
	char suitValue; //the face value of the card

	//~Card();
};

#endif