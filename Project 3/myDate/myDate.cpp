#include "stdafx.h" 
#include "myDate.h"
#include <math.h>
#include <stdlib.h>
#include <iomanip>

int max(int a, int b)
{
	if (a>b) return(a); else return (b);
}

int min(int a, int b)
{
	if (a>b) return(b); else return (a);
}
myDate::myDate()
{
	month = 05;
	day = 11;
	year = 1959;
}

myDate::myDate(int m, int d, int y)
{
	static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isValid(m, d, y)) {
		month = m;
		day = d;
		year = y;
	}

	else {
		month = 05;
		day = 11;
		year = 1959;
	}
	
}


//use a case statements here instead of array


void myDate::display()
{
	myDate thisDate = myDate(this->month, this->day, this->year);

	static char *name[] = { "January", "February", "March", "April", "May",
		"June", "July", "August", "September", "October",
		"November", "December" };


	cout << setw(10) << name[month - 1] << day << ", " << year;
}

void myDate::incrDate(int days)
{

	myDate tempDate = myDate(this->month, this->day, this->year);

	int jul = days + this->gregToJulian(tempDate);
	this->julToGreg(jul, month, day, year);
}


void myDate::decrDate(int days)
{

	myDate tempDate = myDate(this->month, this->day, this->year);

	int juli = this->gregToJulian(tempDate) - days;
	this->julToGreg(juli, month, day, year);
}



bool myDate::equals(myDate date)
{
	return this->getDay() == date.getDay()
		&& this->getMonth() == date.getMonth()
		&& this->getYear() == date.getYear();
}


int myDate::daysBetween(myDate date)
{
	int daysBetw;
	myDate temp = myDate(month, day, year);

	daysBetw = gregToJulian(date) - gregToJulian(temp);
	return daysBetw;
}

int myDate::getYearOffset()
{
	int offsetnumber;
	myDate date = myDate(month, day, year);
	myDate janOffset = myDate(1, 1, date.getYear());

	offsetnumber = abs(gregToJulian(date) - gregToJulian(janOffset));

	return offsetnumber;
}

int myDate::gregToJulian(myDate arr)
{

	int I = arr.getYear();
	int J = arr.getMonth();
	int K = arr.getDay();

	int jd = K - 32075 + 1461 * (I + 4800 + (J - 14) / 12) / 4 + 367 * (J - 2 - (J - 14) / 12 * 12) / 12 - 3 * ((I + 4900 + (J - 14) / 12) / 100) / 4;

	return jd;
}


myDate myDate::julToGreg(int jd, int &month, int &day, int &year) //calculations given, Julian to Gregorian
{
	int I, J, K, L, N;
	myDate temp;

	L = jd + 68569;
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	year = I;
	month = J;
	day = K;
	temp = myDate(I, J, K);

	return temp;
}
myDate::~myDate()
{

}
int myDate::getMonth()
{
	return month;
}

int myDate::getDay()
{
	return day;
}

int myDate::getYear()
{
	return year;
}

bool myDate::isLeap(int y) {
	if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
		return true;
	else
		return false;
}

bool myDate::isValid(int m, int d, int y) {
	if ((m <= 0 || m >12) || (d <= 0 || d > 31) || y <= 0)
		return false;

	if (month == 2) {
		if (isLeap(y)) {
			if (d > 29)
				return false;
		}
		else {
			if (d > 28)
				return false;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (d > 31)
			return false;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (d > 30)
			return false;
	}

	return true;
}