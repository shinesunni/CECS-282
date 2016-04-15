/* CECS-282
Lab assignments given in CSULB's CECS C++ course.
*/

// Shinesunny Som
// Class: CECS 282
// Prog 5 - stl - Standard Library
// Inst: Steve Gold
// Mo/We 5P-7:15P
// 4/12/16

//ROBUST INCLUDE DIRECTIVES
#include "stdafx.h" 
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;

//To print out 10000 integers from ranges 1-100, the are two ways to do it.
void print(vector<int> v)
{
	vector<int>::iterator it; int i = 0;
	for (it = v.begin(); i < 500; it++) 
		cout << setw(4) << *it << ((++i % 15) ? ',' : '\n');
}

/*
void print(vector<int> v)
{
	vector<int>::iterator it; 
	int i = 0;
	for (it = v.begin(); it!= v.end(); it++)
	{
		cout << setw(4) << *it << ((++i % 15) ? ',' : '\n');
		if (i > 500) break;
	}
}
*/
//Random generated numbers, including the sum of the array, and average in decimals.
int main()
{
	vector<int>myArray;
	int sum = 0;
	int avg = 0;
	for (int i = 0; i < 10000; i++)
	{
		int randNum = rand() % 100 + 1; //+1
		myArray.push_back(randNum);
		sum = sum + randNum;
		//		mode[(myArray[i] % 100) ? myArray[i] : 100]++;
		//		mode[6] = mode[0] + 1;
		//		mode[6]++;
		//   	mode[100]++;
	}

	print(myArray);
	cout << endl; //to seperate the array 
	sort(myArray.begin(), myArray.end());
	cout << "\nThe sorted array: " << endl;
	print(myArray);
	cout << "\nThe sum is " << endl;
	cout << sum << endl;
	cout << endl;
	cout << "The average is: " << endl;
	cout << sum / 10000.0 << endl; //debug taking 1/4 value
	cout << endl;
}

//I have also have to include frequency and mode of the array, this code is hidden on purpose.


