// *************************************************
// 
//  Assignment:    #20
//  File:          test_scores.cpp
//
//  Due Date:      December 3, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program allows user to enter 4 tests scores, then calculates and prints the
//				   total of the scores, the average score, the highest score, and the lowest score.
//
// *************************************************

#include <iostream>
#include <iomanip>
using namespace std;

void getTests(double[], int);
double toTotalTest(double[], int);
double getAverage(double, int);
double getHighest(double[], int);
double getLowest(double[], int);
void report(double[], double, double, double, double);

int main()
{
	const int SIZE = 4;
	double tests[SIZE],
		   total = 0,
		   average,
		   highest,
		   lowest;

	getTests(tests, SIZE);
	total = toTotalTest(tests, SIZE);
	average = getAverage(total, SIZE);
	highest = getHighest(tests, SIZE);
	lowest = getLowest(tests, SIZE);
	report(tests, total, average, highest, lowest);

	return 0;
}

// *************************************************
// This function promptrs user to enter 4 test scores of a student
void getTests(double scores[], int size)
{
	for (int count = 0; count < size; count++)
	{
		cout << "Enter score " << count + 1 << ": ";
		cin >> scores[count];
	}
}

// *************************************************
// This function sums the 4 scores and returns a total
double toTotalTest(double scores[], int size)
{
	double total = 0;
	for (int count = 0; count < size; count++)
	{
		total += scores[count];
	}

	return total;
}

// *************************************************
// This function computes and returns the average of the 4 scores
double getAverage(double total, int size)
{
	double average = total / size;

	return average;
}

// *************************************************
// This function finds and returns the highest test score
double getHighest(double scores[], int size)
{
	double highest = scores[0];
	for (int count = 0; count < size; count++)
	{
		if (scores[count] > highest)
		{
			highest = scores[count];
		}
	}

	return highest;
}

// *************************************************
// This function finds and returns the lowest test score
double getLowest(double scores[], int size)
{
	double lowest = scores[0];
	for (int count = 0; count < size; count++)
	{
		if (scores[count] < lowest)
		{
			lowest = scores[count];
		}
	}

	return lowest;
}

// *************************************************
// This function will print each score, the average, and the highest and the lowest scores
void report(double scores[], double total, double average, double highest, double lowest)
{
	cout << fixed << showpoint << setprecision(2);
	cin.get();
	cout << "Press enter to continue \n";
	cin.get();
	cout << "Student score 1 is: " << scores[0] << endl;
	cout << "Student score 2 is: " << scores[1] << endl;
	cout << "Student score 3 is: " << scores[2] << endl;
	cout << "Student score 4 is: " << scores[3] << endl;
	cout << "Press enter to continue \n";
	cin.get();
	cout << "The total of all scores is " << total << endl;
	cout << "Press enter to continue \n";
	cin.get();
	cout << "The average of all scores is " << average << endl;
	cout << "Press enter to continue \n";
	cin.get();
	cout << "The highest test score is " << highest << endl;
	cout << "Press enter to continue \n";
	cin.get();
	cout << "The lowest test score is " << lowest << endl;
}

/*
	Enter score 1: 1
	Enter score 2: 2
	Enter score 3: 3
	Enter score 4: 4
	Press enter to continue

	Student score 1 is: 1.00
	Student score 2 is: 2.00
	Student score 3 is: 3.00
	Student score 4 is: 4.00
	Press enter to continue

	The total of all scores is 10.00
	Press enter to continue

	The average of all scores is 2.50
	Press enter to continue

	The highest test score is 4.00
	Press enter to continue

	The lowest test score is 1.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 20\Debug\assignment 20.exe (process 15860) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Enter score 1: 79.45
	Enter score 2: 45.67
	Enter score 3: 98.68
	Enter score 4: 85.68
	Press enter to continue

	Student score 1 is: 79.45
	Student score 2 is: 45.67
	Student score 3 is: 98.68
	Student score 4 is: 85.68
	Press enter to continue

	The total of all scores is 309.48
	Press enter to continue

	The average of all scores is 77.37
	Press enter to continue

	The highest test score is 98.68
	Press enter to continue

	The lowest test score is 45.67

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 20\Debug\assignment 20.exe (process 13420) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Enter score 1: 62.38
	Enter score 2: 90.21
	Enter score 3: 84.95
	Enter score 4: 73.71
	Press enter to continue

	Student score 1 is: 62.38
	Student score 2 is: 90.21
	Student score 3 is: 84.95
	Student score 4 is: 73.71
	Press enter to continue

	The total of all scores is 311.25
	Press enter to continue

	The average of all scores is 77.81
	Press enter to continue

	The highest test score is 90.21
	Press enter to continue

	The lowest test score is 62.38

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 20\Debug\assignment 20.exe (process 17148) exited with code 0.
	Press any key to close this window . . .
*/