// *************************************************
// 
//  Assignment:    #1
//  File:          test_scores.cpp
//
//  Due Date:      January 31, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program displays various information about 
//				   different students, tests, and test scores
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int NUM_TESTS = 8;  

void readTestScores(ifstream& inFile, int scores[][NUM_TESTS], int numStds);
void displayTestScores(const int scores[][NUM_TESTS], int numStds);
int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int topStudent(const int scores[][NUM_TESTS], int numStds);

int main()
{
	const int numStds = 10;

	int scores[numStds][NUM_TESTS];
	int testTotal,
		studentTotal,
		highestScore,
		topStu;
	double testAverage,
		   studentAverage;

	ifstream inFile;
	inFile.open("Assignment1Data.txt");
	if (!inFile)
	{
		exit(1);
	}
	readTestScores(inFile, scores, numStds);
	inFile.close();

	displayTestScores(scores, numStds);
	cout << "\n";

	cout << fixed << showpoint << setprecision(2);

	testTotal = totalOneTest(scores, numStds, 0);
	cout << "Total for Test #1: " << testTotal << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	testTotal = totalOneTest(scores, numStds, 4);
	cout << "Press enter key to continue \n";
	cout << "Total for Test #5 is " << testTotal << endl;
	cin.get();
	studentTotal = totalOneStudent(scores, numStds, 2);
	cout << "Total for Student #3: " << studentTotal << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	studentTotal = totalOneStudent(scores, numStds, 7);
	cout << "Total for Student #8: " << studentTotal << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	testAverage = averageOneTest(scores, numStds, 4);
	cout << "Average for Test #5: " << testAverage << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	testAverage = averageOneTest(scores, numStds, 7);
	cout << "Average for Test #8: " << testAverage << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	studentAverage = averageOneStudent(scores, numStds, 4);
	cout << "Average for Student #5: " << studentAverage << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	studentAverage = averageOneStudent(scores, numStds, 8);
	cout << "Average for Student #9: " << studentAverage << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	highestScore = highestOneStudent(scores, numStds, 2);
	cout << "Highest test score for Student #2: " << highestScore << endl;
	cout << "Press enter key to continue \n";
	cin.get();
	topStu = topStudent(scores, numStds);
	cout << "The top student: " << topStu << endl;

	return 0;
}

// *************************************************
// This function reads all test scores from the file and store in the array 
void readTestScores(ifstream& inFile, int scores[][NUM_TESTS], int numStds)
{
	for (int s = 0; s < numStds; s++)
	{
		for (int t = 0; t < NUM_TESTS; t++)
		{
			inFile >> scores[s][t];
		}
	}
}

void displayTestScores(const int scores[][NUM_TESTS], int numStds)
{
	cout << "All test scores: \n";
	for (int t = 0; t < NUM_TESTS; t++)
	{
		for (int s = 0; s < numStds; s++)
		{
			cout << scores[s][t] << " ";
		}
		cout << endl;
	}
}

// *************************************************
// This function returns the total for the test specified in the third argument 
int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{
	int t = testNumber;
	int total = 0;
	for (int s = 0; s < numStds; s++)
	{
		total += scores[s][t];
	}
	return total;
}

// *************************************************
// This function returns the total for the student specified in the third argument 
int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
	int s = studentNumber;
	int total = 0;
	for (int t = 0; t < NUM_TESTS; t++)
	{
		total += scores[s][t];
	}
	return total;
}

// *************************************************
// This function returns the average of the test specified in the third argument  
double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{
	int t = testNumber;
	int total = 0;
	for (int s = 0; s < numStds; s++)
	{
		total += scores[s][t];
	}
	double average = static_cast<double>(total) / numStds;
	return average;
}

// *************************************************
// This function returns the average for the student specified in the third argument
double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
	int s = studentNumber;
	int total = 0;
	for (int t = 0; t < NUM_TESTS; t++)
	{
		total += scores[s][t];
	}
	double average = static_cast<double>(total) / NUM_TESTS;
	return average;
}

// *************************************************
// This function returns the highest result for the student specified in the third argument
int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
	int s = studentNumber;
	int highest = scores[0][0];
	for (int t = 0; t < NUM_TESTS; t++)
	{
		if (scores[s][t] > highest)
		{
			highest = scores[s][t];
		}
	}
	return highest;
}

// *************************************************
// This function returns the student number with the highest average test score 
int topStudent(const int scores[][NUM_TESTS], int numStds)
{
	double highest = 0;
	int topStu = 0;
	for (int s = 0; s < numStds; s++)
	{
		double average = averageOneStudent(scores, numStds, s);
		if (average > highest)
		{
			highest = average;
			topStu = s + 1;
		}
	}
	return topStu;
}




/*
	All test scores:
	87 89 80 90 55 30 90 99 90 35
	90 85 90 65 75 60 55 97 65 75
	65 78 72 80 66 80 95 99 80 60
	45 56 95 98 99 90 35 98 98 99
	88 90 99 99 99 99 98 98 99 99
	89 91 66 76 56 56 86 96 76 56
	75 99 77 77 87 67 37 87 87 87
	80 82 88 88 86 88 88 83 88 88

	Total for Test #1: 745
	Press enter key to continue

	Press enter key to continue
	Total for Test #5 is 968

	Total for Student #3: 667
	Press enter key to continue

	Total for Student #8: 757
	Press enter key to continue

	Average for Test #5: 96.80
	Press enter key to continue

	Average for Test #8: 85.90
	Press enter key to continue

	Average for Student #5: 77.88
	Press enter key to continue

	Average for Student #9: 85.38
	Press enter key to continue

	Highest test score for Student #2: 99
	Press enter key to continue

	The top student: 8

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 1\Debug\exercise 1.exe (process 17176) exited with code 0.
	Press any key to close this window . . .
*/