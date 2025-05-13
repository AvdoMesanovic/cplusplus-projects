// *************************************************
// 
//  Assignment:    #6
//  File:          math_tutor.cpp
//
//  Due Date:      September 17, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program generates two random numbers and
//				   then dispalys the sum of the two numbers
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
	const int MAXRANGE = 500; 
	unsigned seed;
	cout << "Type in a number and press enter key to see an addition problem" << endl;
	cin >> seed;
	srand(seed);

	int random1 = 1 + rand() % MAXRANGE; 
	int random2 = 1 + rand() % MAXRANGE; 
	srand(time(0));

	cout << "Press enter key when you are ready to see the answer" << endl;

	cout << right << setw(7) << random1 << endl;
	cout << left << "+" << right << setw(6) << random2 << endl;
	cout << "  -----" << endl;

	int total = random1 + random2;
	cin.ignore();
	cin.get();
	cout << right << setw(7) << total << endl;

	return 0;
}

/*
	Type in a number and press enter key to see an addition problem
	3
	Press enter key when you are ready to see the answer.
		 49
	+   197
	  -----

		246

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 6\Debug\assignment 6.exe (process 12000) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	Type in a number and press enter key to see an addition problem
	1
	Press enter key when you are ready to see the answer.
		 42
	+   468
	  -----

		510

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 6\Debug\assignment 6.exe (process 6640) exited with code 0.
	Press any key to close this window . . .
-------------------------------------------------------------------------------------------------------------------------
	Type in a number and press enter key to see an addition problem
	6
	Press enter key when you are ready to see the answer.
		 59
	+   174
	  -----

		233

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 6\Debug\assignment 6.exe (process 15220) exited with code 0.
	Press any key to close this window . . .
*/