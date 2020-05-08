// testupDate.cpp
// Author: Steven H Gold
// Program #5 due date: 11/05/2015
// 
// 
//
// All rights and lefts reserved.
//
#include "stdafx.h"
#include "upDate.h"
#include <iostream>
using namespace std;

int main()
{
	upDate Bday;
	upDate duedate(11, 05, 2015);
	upDate today(duedate);

	int x;
	int month, day, year;


	cout << endl;
	cout << "Today is " << today << endl;
	cout << "This program is due on " << duedate;
	cout << endl;

	cout << "Right now there are " << upDate::GetDateCount() << " upDate objects\n";
	{
		upDate d1, d2, d3;
		cout << "Inside this block there are " << upDate::GetDateCount() << " upDate objects\n";
	}
	cout << "Outside the block there are " << upDate::GetDateCount() << " upDate objects\n";

	upDate dtemp(duedate);
	dtemp++;
	cout << "If you turn this assignment in on " << dtemp << " then is will be late.\n";
	cout << "It is due on " << --dtemp << " so don't be late.\n";
	cout << "One week from due date is " << duedate + 7 << endl;
	cout << "One week from due date is " << 7 + duedate << endl;
	cout << "One week earlier from due date is " << duedate - 7 << endl;

	cout << "Your professor was born on " << Bday << " : ";
	cout << "Master Gold (oh please...) is " << duedate - Bday << " days old today\n";

	cout << "Today is Julian date " << duedate.julian() << endl;;
	cout << "Tomorrrow is Julian date " << (++duedate).julian() << endl;;

	cout << "The very first Julian date was " << upDate(11, 5, 2015) - upDate(11, 5, 2015).julian() << endl;

	cout << "The very first Julian date was " << upDate(1, 1, 2000) - upDate(1, 1, 2000).julian() << endl;

	upDate testdate(11, 10, 2015);
	upDate monday;
	monday = today - 3;
	upDate tuesday = 1 + monday;
	cout << "Monday was " << monday << " and Tuesday was " << tuesday << endl;;

	upDate thanksGivingBreak(11, 23, 2015);

	cout << "Thanksgiving Break begins " << thanksGivingBreak << endl;
	thanksGivingBreak.~upDate();

	cout << "Today is " << today << " and the test will be on " << testdate << endl;

	int dummy;
	cin >> dummy;
	return 0;
}




