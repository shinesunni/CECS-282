#include "Card.h"
#include <string>
#include "time.h"

using std::string;
using namespace std;

Card::Card(char rank, char suit) {
	rankValue=rank; 
	suitValue=suit;
}
int Card::getValue() const {
	if (rankValue <= 11) {
		return rankValue;                   // return the rank value based on rank value that was passed in 
	}
	else {
		return 10;                          // Rank K,Q,J: return value of 10
	}
}
	
Card::Card() : rankValue(0), suitValue(0){  // Default constructor gives default values to member variables
}

int Card::compareCard(const Card & other)  { 
	return (rankValue + rankValue) - (other.rankValue + other.rankValue);
}

//string Card::
string Card::toString() const {
	string strValue;
	string suits[] = { "Spades\n", "Clubs\n", "Diamonds\n", "Hearts\n" };
	if (rankValue <= 10)
		strValue += to_string(rankValue);
	else {
		strValue += (
			rankValue == 11 ? "Jack" :
			rankValue == 12 ? "Queen" :
			rankValue == 13 ? "King" :
			"Ace"
			);
	}
	strValue += " of " ;
	strValue += suits[suitValue];
	return strValue;
}

void Card::setRank(char rank) {
	if (rank >= 2 && rank <= 13) // 2, 14
		rankValue = rank;
}

void Card::setSuit(char suit) {
	if (suit >= 0 && suit <= 3)
		suitValue = suit;
}

int Card::score()
{
	cout << "rankValue = " << rankValue;
	cout << "\nactual rankValue expected ";
	if (rankValue == 1)
	{
		cout << "1";
		return 1;
	}
	else if (rankValue == 2)
	{
		cout << "2";
		return 2;
	}
	else if (rankValue == 3)
	{
		cout << "3";
		return 3;
	}
	else if (rankValue == 4)
	{
		cout << "4";
		return 4;
	}
	else if (rankValue == 5)
	{
		cout << "5";
		return 5;
	}
	else if (rankValue == 6)
	{
		cout << "6";
		return 6;
	}
	else if (rankValue == 7)
	{
		cout << "7";
		return 7;
	}
	else if (rankValue == 8)
	{
		cout << "8";
		return 8;
	}
	else if (rankValue == 9)
	{
		cout << "9";
		return 9;
	}
	else if (rankValue == 11)
	{
		cout << "11";
		return 10;
	}
	else if (rankValue == 12)
	{
		cout << "12";
		return 10;
	}
	else if (rankValue == 13)
	{
		cout << "13";
		return 10;
	}
	else if (rankValue == 10)
	{
		cout << "10";
		return 10;
	}
//	else if (rankValue == 14)
//	{
//		return 10;
//	}
}

void Card::displayCard()
{
	char cardSuit[4] = { 'D', 'S', 'H', 'C' };
	char symbol[4] = { '6', '5', '4', '3' };
	char cardRank[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	int sD = 0, rD = 0; //suit display, rank display
	while (suitValue != cardSuit[sD]){
		cout << "suitValue is:" << sD;
		if (sD < 4) {
			sD++;
		}
}
	while (rankValue != cardRank[rD]) {


		cout << "rankValue is:" << rD;
	if (rD < 13)
		rD++;
	}
	cout << "[-------]" << endl;
	if (rD == 9)
		cout << "[10 ]" << endl;
	else
		cout << "[" << cardRank[rD] << " ]" << endl;


	if (rD == 0 || rD == 10 || rD == 11 || rD == 12)
		cout << "[ ]\n[ ]\n[ " << symbol[sD] << " ]\n[ ]\n[ ]" << endl;
	else if (rD == 1)
		cout << "[ " << symbol[sD] << " ]\n[ ]\n[ ]\n[ ]\n[ " << symbol[sD] << " ]" << endl;
	else if (rD == 2)
		cout << "[ " << symbol[sD] << " ]\n[ ]\n[ " << symbol[sD] << " ]\n[ ]\n[ " << symbol[sD] << " ]" << endl;
	else if (rD == 3)
		cout << "[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ ]\n[ ]\n[ ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]" << endl;
	else if (rD == 4)
		cout << "[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ ]\n[ " << symbol[sD] << " ]\n[ ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]" << endl;
	else if (rD == 5)
		cout << "[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]" << endl;
	else if (rD == 6)
		cout << "[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]" << endl;
	else if (rD == 7)
		cout << "[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]" << endl;
	else if (rD == 8)
		cout << "[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]" << endl;
	else if (rD == 9)
		cout << "[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]\n[ " << symbol[sD] << " " << symbol[sD] << " ]" << endl;
	else
		0;


	if (rD == 9)
		cout << "[ 10]" << endl;
	else
		cout << "[ " << cardRank[rD] << "]" << endl;
	cout << "[-------]" << endl;
}