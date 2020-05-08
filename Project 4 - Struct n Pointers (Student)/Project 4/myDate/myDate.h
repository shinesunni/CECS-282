#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

#ifndef MYDATE_H
#define MYDATE_H //used twice
class myDate
{
private:
	int month;
	int day;
	int year;
public:
	myDate();
	myDate(int m, int d, int y);
	int getMonth();
	int getDay();
	int getYear();
	void display();
	void incrDate(int days);
	void decrDate(int days);
	bool equals(myDate date);
	int daysBetween(myDate date);
	bool isLeap(int);
	bool isValid(int, int, int);
	int getYearOffset();
	int gregToJulian(myDate arr);
	myDate julToGreg(int jd, int &month, int &day, int &year);
	~myDate();
};
#endif