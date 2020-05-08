// Shinesunny Som
// Class: CECS 282
// Prog 5 - upDate - Overload
// Inst: Steve Gold
// Tu/Th 7:30P-9:45P
// 11/5/15

#include "stdafx.h"
#include <string>
#include <iostream>
#include "upDate.h"


using namespace std;

int upDate::count = 0;

upDate::upDate() {
	dptr = new int[3];
	dptr[0] = 5;
	dptr[1] = 11;
	dptr[2] = 1959;
	count = count + 1;
}

upDate::upDate(int M, int D, int Y) {
	dptr = new int[3];
	dptr[0] = M;
	dptr[1] = D;
	dptr[2] = Y;
	count = count + 1;
}

upDate::upDate(const upDate& n) {
	dptr = new int[3];
	dptr[0] = n.dptr[0];
	dptr[1] = n.dptr[1];
	dptr[2] = n.dptr[2];
	count = count + 1;

}

upDate::~upDate() {
	delete[]dptr;
	count = count - 1;
}

int upDate::GetDateCount() {
	return count;
}
int upDate::getDay() {
	return dptr[1];
}

int upDate::getMonth() {
	return dptr[0];
}

int upDate::getYear() {
	return dptr[2];
}

string upDate::getMonthName() {
	switch (dptr[0]) {
	case 1:
		return "January";
		break;
	case 2:
		return "February";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	default:
		return "No Month";
		break;
	}

}

int upDate::gregToJulian(const int& j, const int& k, const int& i) {

	return (k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4);

}

void upDate::julianToGreg(int JD) {

	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	dptr[2] = I;
	dptr[0] = J;
	dptr[1] = K;

}

void upDate::julianToGreg(int JD, int &m, int &d, int &y) {

	int L = JD + 68569;
	int N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	int I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	int J = 80 * L / 2447;
	int K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	y = I;
	m = J;
	d = K;

}

upDate upDate::operator+(int n) {
	int temp = gregToJulian(this->getMonth(), this->getDay(), this->getYear());
	int date = temp + n;
	upDate newDate;
	newDate.julianToGreg(date);
	return newDate;
}

upDate upDate::operator=(upDate ud)
{
	dptr = new int[3];
	dptr[0] = ud.dptr[0];
	dptr[1] = ud.dptr[1];
	dptr[2] = ud.dptr[2];
	return *this;
}


upDate operator+(int n, upDate d) {
	int temp = d.gregToJulian(d.getMonth(), d.getDay(), d.getYear());
	int date = n + temp;
	upDate newDate;
	newDate.julianToGreg(date);
	return newDate;
}

upDate upDate::operator-(int n) {
	int temp = gregToJulian(this->getMonth(), this->getDay(), this->getYear());
	int date = temp - n;
	upDate newDate;
	newDate.julianToGreg(date);
	return newDate;
}

int upDate::operator-(upDate n) {
	int result = 0;
	int first = this->julian();
	int second = n.julian();
	result = first - second;
	return result;
}
int upDate::julian() {
	return gregToJulian(this->getMonth(), this->getDay(), this->getYear());
}


upDate upDate::operator++(int) {
	int hold = this->julian();
	int num = this->julian();
	num++;
	int m, d, y;
	julianToGreg(num, m, d, y);
	dptr[0] = m;
	dptr[1] = d;
	dptr[2] = y;
	upDate result;
	result.julianToGreg(hold);
	return  result;
}

upDate upDate::operator++() {
	int num = this->julian();
	num++;
	int m, d, y;
	julianToGreg(num, m, d, y);
	dptr[0] = m;
	dptr[1] = d;
	dptr[2] = y;
	return *this;
}
upDate upDate::operator--(int) {
	int hold = this->julian();
	int num = this->julian();
	num--;
	int m, d, y;
	julianToGreg(num, m, d, y);

	dptr[0] = m;
	dptr[1] = d;
	dptr[2] = y;
	upDate result;
	result.julianToGreg(hold);
	return  result;
}

upDate upDate::operator--() {
	int num = this->julian();
	num--;
	int m, d, y;
	julianToGreg(num, m, d, y);
	dptr[0] = m;
	dptr[1] = d;
	dptr[2] = y;
	return *this;
}

ostream & operator<<(ostream & out, upDate d) {
	out << d.getMonth() << "/" << d.getDay() << "/" << d.getYear();
	return out;
}