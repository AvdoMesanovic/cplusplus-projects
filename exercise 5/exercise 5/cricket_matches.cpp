// *************************************************
// 
//  Assignment:    #5
//  File:          cricket_matches.cpp
//
//  Due Date:      February 28, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program is used to gather data about the number of cricket 
//				   matches college students play in a year.
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void input(string names[], int matches[], int size);
void display(const string names[], const int matches[], int size);
void displayMostMatches(const string names[], const int matches[], int size);
double mean(const int matches[], int num);
void sortStudents(string names[], int matches[], int size);

int main()
{
	string* sptr = nullptr;
	int* iptr = nullptr;

	int numStudents;
	double average;

	cout << "How many students were surveyed? \n";
	cin >> numStudents;
	cout << "\n";
	cin.get();
	sptr = new string[numStudents];
	iptr = new int[numStudents];

	input(sptr, iptr, numStudents);
	cout << "\n";
	display(sptr, iptr, numStudents);
	cout << "\n";
	displayMostMatches(sptr, iptr, numStudents);
	cout << "\n";
	average = mean(iptr, numStudents);
	cout << "The average number of matches played by students is " << average << endl;
	cout << "\n";
	cout << "Ascending order: \n";
	sortStudents(sptr, iptr, numStudents);
	display(sptr, iptr, numStudents);

	delete[]sptr;
	delete[]iptr;
	return 0;
}

// *************************************************
// This function allows the user to enter the name of each student and number of cricket matches played by that student
void input(string names[], int matches[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Name of student " << i + 1 << ": \n";
		getline(cin, names[i]);
	}
	cin.get();
	for (int i = 0; i < size; i++)
	{
		cout << "Number of matches played by student " << i + 1 << ":" << endl;
		cin >> matches[i];
		while (matches[i] < 0)
		{
			cout << "Error: please enter a positive number \n";
			cin >> matches[i];
		}
	}
}

// *************************************************
// This function displays the names of the students, and the number of matches each has played
void display(const string names[], const int matches[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Student " << i + 1 << ": " << names[i] << " ===> Matches played: " << matches[i] << endl;
	}
}

// *************************************************
// This function displays the name of the student who played the most cricket matches in the year, and the number of matches they played
void displayMostMatches(const string names[], const int matches[], int size)
{
	string name;
	int most = matches[0];

	for (int i = 0; i < size; i++)
	{
		if (matches[i] > most)
		{
			most = matches[i];
			name = names[i];
		}
	}
	cout << "Student with the most matches: " << name << " with " << most << " matches played" << endl;
}

// *************************************************
// This function determines the mean of the array
double mean(const int matches[], int num)
{
	double average,
		   total = 0;

	cout << fixed << showpoint << setprecision(2);

	for (int i = 0; i < num; i++)
	{
		total += matches[i];
	}

	average = total / num;
	return average;
}

// *************************************************
// This function sorts the array of student names into ascending order
void sortStudents(string names[], int matches[], int size)
{
	int minIndex,
		minMatch;
	string minName;
	for (int i = 0; i < size; i++)
	{
		minIndex = i;
		minName = names[minIndex];
		minMatch = matches[minIndex];
		for (int index = i + 1; index < size; index++)
		{
			if (names[index] < minName)
			{
				minName = names[index];
				minMatch = matches[index];
				minIndex = index;
			}
		}
		names[minIndex] = names[i];
		names[i] = minName;
		matches[minIndex] = matches[i];
		matches[i] = minMatch;
	}
}

/*
	How many students were surveyed?
	4

	Name of student 1:
	Zachary Kingston
	Name of student 2:
	Avdo Mesanovic
	Name of student 3:
	Henry Leatherford
	Name of student 4:
	Sylvia Ashwell

	Number of matches played by student 1:
	-1
	Error: please enter a positive number
	3
	Number of matches played by student 2:
	5
	Number of matches played by student 3:
	7
	Number of matches played by student 4:
	9

	Student 1: Zachary Kingston ===> Matches played: 3
	Student 2: Avdo Mesanovic ===> Matches played: 5
	Student 3: Henry Leatherford ===> Matches played: 7
	Student 4: Sylvia Ashwell ===> Matches played: 9

	Student with the most matches: Sylvia Ashwell with 9 matches played

	The average number of matches played by students is 6.00

	Ascending order:
	Student 1: Avdo Mesanovic ===> Matches played: 5
	Student 2: Henry Leatherford ===> Matches played: 7
	Student 3: Sylvia Ashwell ===> Matches played: 9
	Student 4: Zachary Kingston ===> Matches played: 3

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 5\Debug\exercise 5.exe (process 9316) exited with code 0.
	Press any key to close this window . . .
*/