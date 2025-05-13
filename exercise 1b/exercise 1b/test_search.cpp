// *************************************************
// 
//  Assignment:    #1b
//  File:          test_search.cpp
//
//  Due Date:      February 7, 2022
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming II 
//
//  Course Number: COSC 1560 
//
//  Description:   This program adds on a search function 
//				   to the previous program
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
bool searchStudents(const int scores[][NUM_TESTS], int numStds, double average);
bool searchTests(const int scores[][NUM_TESTS], int numStds, double average);

int main()
{
	const int numStds = 10;

	int scores[numStds][NUM_TESTS];
	int testTotal,
		studentTotal,
		highestScore,
		topStu,
		studentResult,
		testResult;
	double testAverage,
		studentAverage,
		userAverage;

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
	cout << "Total for Test #5 is " << testTotal << endl;
	cout << "Press enter key to continue \n";
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
	cout << "Press enter key to continue \n";
	cin.get();
	cout << "Please enter an average test score \n";
	cin >> userAverage;
	cout << "\n";
	studentResult = searchStudents(scores, numStds, userAverage);
	cout << "A student does/does not have an average score greater than: " << userAverage << endl;
	if (studentResult == 0)
	{
		cout << "It does not" << endl;
	}
	else
	{
		cout << "It does" << endl;
	}
	cout << "\n";
	testResult = searchTests(scores, numStds, userAverage);
	cout << "A test does/does not have an average score greater than: " << userAverage << endl;
	if (testResult == 0)
	{
		cout << "It does not" << endl;
	}
	else
	{
		cout << "It does" << endl;
	}

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

// *************************************************
// This function returns “true” if at least one student has an average score greater than the value
// passed as the third argument and “false” if no students meet the requirement
bool searchStudents(const int scores[][NUM_TESTS], int numStds, double average)
{
	int index = 0;
	bool found = false;

	while (index < NUM_TESTS && !found)
	{
		if (average < averageOneStudent(scores, numStds, index))
		{
			found = true;
		}
		index++;
	}
	return found;
}

// *************************************************
// This function returns “true” if at least one tests has an average score greater than the value
// passed as the third argument and “false” if no tests meet the requirement
bool searchTests(const int scores[][NUM_TESTS], int numStds, double average)
{
	int index = 0;
	bool found = false;

	while (index < numStds && !found)
	{
		if (average < averageOneTest(scores, numStds, index))
		{
			found = true;
		}
		index++;
	}
	return found;
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

	Total for Test #5 is 968
	Press enter key to continue

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
	Press enter key to continue

	Please enter an average test score
	99

	A student does/does not have an average score greater than: 99.00
	It does not

	A test does/does not have an average score greater than: 99.00
	It does not

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 1b\Debug\exercise 1b.exe (process 15152) exited with code 0.
	Press any key to close this window . . .
------------------------------------------------------------------------------------------------------------------------
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

	Total for Test #5 is 968
	Press enter key to continue

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
	Press enter key to continue

	Please enter an average test score
	50

	A student does/does not have an average score greater than: 50.00
	It does

	A test does/does not have an average score greater than: 50.00
	It does

	C:\Users\avdom\OneDrive\Documents\source\repos\exercise 1b\Debug\exercise 1b.exe (process 12608) exited with code 0.
	Press any key to close this window . . .
*/