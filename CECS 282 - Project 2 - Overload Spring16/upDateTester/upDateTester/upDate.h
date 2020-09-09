#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class upDate {

private:
	//pointer to keep track of the month date year
	int *dptr;
	//only accessed in our upDate class so we dont want other to use it make it private
	void julianToGreg(int);
	int gregToJulian(const int&, const int&, const int&);

public:
	static int count;//static so it wont be reinitialized 
	upDate();//default with Golds Bday
	upDate(int, int, int);//the constutor 
	upDate(const upDate&);//this is the overloaded constructor that will copy basically
	~upDate();//to delete the pointer
	static int GetDateCount();
	int getMonth();
	int getYear();
	int getDay();

	void julianToGreg(int, int&, int&, int&);//pass by reference so we can change them 
	int julian();

	string getMonthName();
	upDate operator+(int);
	upDate operator-(int);
	int    operator-(upDate);

	//friend functions
	friend upDate operator+(int, upDate);
	friend upDate operator-(int, upDate);
	int operator==(upDate);
    int operator<(upDate);
	int operator>(upDate);

	friend ostream & operator<<(ostream &, upDate);

	//new operators
	upDate operator++(int);
	upDate operator++();
	upDate operator--(int);
	upDate operator--();
	upDate operator=(upDate ud);
};