// Shinesunny Som
// Class: CECS 282
// Prog 4 - Student List
// Inst: Steve Gold
// Tu/Th 7:30P-9:45P
// 10/22/15

#include "stdafx.h"
#include "myDate.h"
#include <string>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>

struct Student {

	char name[24]; //Doesn't need to be this big but, to accommendate the names.
	int gradeNumber, studentID; //Integer values
	myDate birthday;
};

/*
This function is to display the ID, Name, Grade and Age in order
*/

void display(Student *var[])

{

	cout << ("ID\t\tName\t\t              Birthday\t\t\    Grades\n\n");
	for (int k = 0; k < 10; k++)	{

		cout << var[k]->studentID << "\t\t";
		cout << var[k]->name << "\t\t";
		cout << setw(20) << left;
		((*var[k]).birthday).display();
		cout << right << setw(10) << var[k]->gradeNumber;
		cout << "\n";
	}
	cout << "\n\n";
}



/*
THis function is to display the students name in sorting order as a alphabetical from top to down
-First, it will sort them, then it will show the names in the list
*/

void sortNames(Student *students[]) {

	int j, k;
	for (j = 0; j < 10; j++){
		for (k = 0; k < 10; k++)
		{
			if (strcmp(students[j]->name, students[k]->name) < 0)
			{
				Student *temp = students[j];
				students[j] = students[k];
				students[k] = temp;
			}
		}
	}
}

/*
This function is to display the students ID's in sorting order
-First, it will sort them, then it will show the IDs in the list
*/

void sortIds(Student *students[]){

	int j, k;
	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{
			if (students[j]->studentID < students[k]->studentID)
			{
				Student *temp = students[j];
				students[j] = students[k];
				students[k] = temp;
			}
		}
	}

}



/*

THis function is to display the students Birthday in sorting order
- First, it will sort them, then it will show the age in the list older to younger
*/

void sortBirthdays(Student *students[])

{

	int j, k;
	for (j = 0; j < 10; j++)

	{
		for (k = 0; k < 10; k++)

		{
			myDate bday1 = students[j]->birthday;
			myDate bday2 = students[k]->birthday;

			if (students[j]->birthday.gregToJulian(bday1) < students[k]->birthday.gregToJulian(bday2))
			{

				Student *temp = students[j];
				students[j] = students[k];
				students[k] = temp;
			}
		}
	}
}



/*
-This function is for sorting the grades.
-It sorts by low to high grades and display in the output terminal by
showing all the info of the student.
*/

void sortGrades(Student *students[]){

	int j, k;
	for (j = 0; j < 10; j++)
	{
		for (k = 0; k < 10; k++)
		{

			if (students[j]->gradeNumber < students[k]->gradeNumber)

			{

				Student *temp = students[j];
				students[j] = students[k];
				students[k] = temp;

			}
		}
	}
}



/*
It is a display menu, from where we choose the option to perform the
certain task in the terminal output.
*/

void dislplayList()

{

	cout << "1) Display original list.\n";
	cout << "2) Sort by ID\n";
	cout << "3) Sort by AGE\n";
	cout << "4) Sort by NAME\n";
	cout << "5) Sort by GRADE\n";
	cout << "6) Exit\n\n";

}

/*
Main portion for the program to perform the task of the student profile, the names and such
*/

int main()

{
	cout << "|=|+|=|+|=|+|=|+|=|+|=|+|=|+|=|+|=|+||=|+|=|+|=|+|=|+|=|+|=|+||=|+|=|+|=|+|=|+|" << endl;
	cout << "                          Welcome to Student Profile                           " << endl;
	cout << "|=|+|=|+|=|+|=|+|=|+|=|+|=|+|=|+|=|+||=|+|=|+|=|+|=|+|=|+|=|+||=|+|=|+|=|+|=|+|" << endl;
	cout << " " << endl;
	srand(time(NULL));

	Student theClass[10];
	Student *classCopy[10];
	Student *byGrade[10];
	Student *byName[10];
	Student *byId[10];

	Student *byBday[10];

	bool again = false;
	int choice = 0;
	int j, k;

	/*
	This for loop generates the random grades, IDs and birthday for the student.
	*/

	for (j = 0; j < 10; j++)
	{
		theClass[j].gradeNumber = 50 + (rand() % (99 - 50 + 1));
		theClass[j].studentID = 1000 + (rand() % (9999 - 1000 + 1));
		theClass[j].birthday = myDate((rand() % 12 + 1), (rand() % 31 + 1), (rand() % 4 + 1990));
	}

	/*
	This will show the name of the student using the string copy
	*/

	strcpy_s(theClass[0].name, "Francesca Lucchini");
	strcpy_s(theClass[1].name, "Sanya V. Litvyak");
	strcpy_s(theClass[2].name, "Charlotte E. Yeager");
	strcpy_s(theClass[3].name, "Gertrud Barkhorn");
	strcpy_s(theClass[4].name, "Perrine H. Clostermann");
	strcpy_s(theClass[5].name, "Sakamoto Mio      "); //Until I figure out how to make the names align correctly,
	strcpy_s(theClass[6].name, "Miyafuji Yoshika  "); // I added random spaces to make it even so it doesn't look jagged.
	strcpy_s(theClass[7].name, "Erica Hartmann    "); //Same deal here
	strcpy_s(theClass[8].name, "Helma Lennartz    "); //yup.
	strcpy_s(theClass[9].name, "Hanna-Justina Marseille");

	for (k = 0; k < 10; k++)
	{
		byGrade[k] = &theClass[k];
		byName[k] = &theClass[k];
		byId[k] = &theClass[k];
		byBday[k] = &theClass[k];
		classCopy[k] = &theClass[k];

	}

	/*
	This while loop help to choose the option to sort the list
	*/

	while (!again)
	{
		dislplayList();
		cout << "What would you like to do?" << endl;
		while (!(cin >> choice))

		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a number." << endl;
		}

		/*
		switch statement to show the menu choice is selected
		*/

		switch (choice)
		{
		case 1:
			display(classCopy);
			break;
		case 2:
			cout << "**************************\nSorting By Id\n**************************" << endl;
			sortIds(byId);
			display(byId);
			break;
		case 3:
			cout << "**************************\nSorting By Age\n**************************" << endl;
			sortBirthdays(byBday);
			display(byBday);
			break;
		case 4:
			cout << "**************************\nSorting By Name\n**************************" << endl;
			sortNames(byName);
			display(byName);
			break;
		case 5:
			cout << "**************************\nSorting By Grade\n**************************" << endl;
			sortGrades(byGrade);
			display(byGrade);
			break;

		default:
			again = true;
			break;
		}
	}
	return 0;
}