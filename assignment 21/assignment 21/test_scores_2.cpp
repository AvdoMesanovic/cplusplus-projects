// *************************************************
// 
//  Assignment:    #21
//  File:          test_scores_2.cpp
//
//  Due Date:      December 10, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program allows user to enter 4 tests scores for 3 students, then calculates and prints the
//				   total, the average, and the highest and lowest scores.
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int S = 3;
const int T = 4;

void getTests(double scores[][T]);
double totalTests(double scores[][T]);
double averageTests(double);
void averageEachTest(double scores[][T]);
void averageEachStudent(double scores[][T]);
double getHighest(double scores[][T]);
void getHighestOfEachTest(double scores[][T]);
void getLowestOfEachStudent(double scores[][T]);
void report(double scores[][T]);

int main()
{
	double scores[S][T];
	getTests(scores);
	report(scores);

	return 0;
}

// *************************************************
// This function obtains test scores from test.txt
void getTests(double scores[][T])
{
	fstream inFile;
	inFile.open("test.txt");
	if ( ! inFile)
	{
		exit(1);
	}
	for (int student = 0; student < S; student++)
	{
		for (int test = 0; test < T; test++)
		{
			inFile >> scores[student][test];
		}
	}
}

// *************************************************
// This function will total all tests for all students
double totalTests(double scores[][T])
{
	double total = 0;
	for (int student = 0; student < S; student++)
	{
		for (int test = 0; test < T; test++)
		{
			total += scores[student][test];
		}
	}

	return total;
}

// *************************************************
// This function will average all tests for all students
double averageTests(double total)
{
	double average = total / (12);

	return average;
}

// *************************************************
// This function will average each test
void averageEachTest(double scores[][T])
{
	double total = 0;
	double average = 0;
	for (int test = 0; test < T; test++)
	{
		total = 0;
		for (int student = 0; student < S; student++)
		{
			total += scores[student][test];
			average = total / S;
		}
		cout << "Average for test " << test + 1 << ": " << average << endl;
	}
	cout << "Press enter key to continue \n";
	cin.get();
}

// *************************************************
// This function will average each student's test scores
void averageEachStudent(double scores[][T])
{
	double total = 0;
	double average = 0;
	for (int student = 0; student < S; student++)
	{
		total = 0;
		for (int test = 0; test < T; test++)
		{
			total += scores[student][test];
			average = total / T;
		}
		cout << "Average for student " << student + 1 << ": " << average << endl;
	}
	cout << "Press enter key to continue \n";
	cin.get();
}

// *************************************************
// This function will get the highest score of all tests from all students
double getHighest(double scores[][T])
{
	double highest = scores[0][0];
	for (int student = 0; student < S; student++)
	{
		highest = scores[student][0];
		for (int test = 0; test < T; test++)
		{
			if (scores[student][test] > highest)
			{
				highest = scores[student][test];
			}
		}
	}
	return highest;
}

// *************************************************
// This function will display the highest score of each test
void getHighestOfEachTest(double scores[][T])
{
	double highest = scores[0][0];
	for (int test = 0; test < T; test++)
	{
		highest = scores[test][0];
		for (int student = 0; student < T; student++)
		{
			if (scores[student][test] > highest)
			{
				highest = scores[student][test];
			}
		}
		cout << "Highest score of test " << test + 1 << ": " << highest << endl;
	}
	cout << "Press enter key to continue \n";
	cin.get();
}

// *************************************************
// This function will get the lowest score of each student
void getLowestOfEachStudent(double scores[][T])
{
	double lowest = scores[0][0];
	for (int student = 0; student < S; student++)
	{
		lowest = scores[student][0];
		for (int test = 0; test < T; test++)
		{
			if (scores[student][test] < lowest)
			{
				lowest = scores[student][test];
			}
		}
		cout << "Lowest test of student " << student + 1 << ": " << lowest << endl;
	}
	cout << "Press enter key to continue";
	cin.get();
}

// *************************************************
// This function will print the results of the other functions besides getTests()
void report(double scores[][T])
{
	cout << fixed << showpoint << setprecision(2);
	double total = totalTests(scores);
	cout << "Total of all tests is: " << total << endl;
	cout << "Press enter key to continue \n";
	cin.get();

	double average = averageTests(total);
	cout << "Average of all tests is " << average << endl;
	cout << "Press enter key to continue \n";
	cin.get();

	averageEachTest(scores);

	averageEachStudent(scores);

	double highest = getHighest(scores);
	cout << "Highest of all tests is " << highest << endl;
	cout << "Press enter key to continue \n";
	cin.get();

	getHighestOfEachTest(scores);
	getLowestOfEachStudent(scores);
}

/*
	Total of all tests is: 955.00
	Press enter key to continue

	Average of all tests is 79.58
	Press enter key to continue

	Average for test 1: 78.33
	Average for test 2: 86.67
	Average for test 3: 76.67
	Average for test 4: 76.67
	Press enter key to continue

	Average for student 1: 78.75
	Average for student 2: 78.75
	Average for student 3: 81.25
	Press enter key to continue

	Highest of all tests is 90.00
	Press enter key to continue

	Highest score of test 1: 85.00
	Highest score of test 2: 90.00
	Highest score of test 3: 90.00
	Highest score of test 4: 80.00
	Press enter key to continue

	Lowest test of student 1: 70.00
	Lowest test of student 2: 60.00
	Lowest test of student 3: 75.00
	Press enter key to continue

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 21\Debug\assignment 21.exe (process 12716) exited with code 0.
	Press any key to close this window . . .
*/