// *************************************************
// 
//  Assignment:    #12
//  File:          data_plan.cpp
//
//  Due Date:      October 8, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program calculates a customer's monthly
//				   bill for their mobile service
//
// *************************************************

#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
	char package;
	int gigabytes;
	double total;

	cout << "Calculate your total amount due \n";
	cout << "Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte. \n";
	cout << "Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte. \n";
	cout << "Package C: For $69.99 per month, unlimited data is provided. \n";
	cout << "D: Quit \n";
	cout << "Select a subscription package (Please answer with A, B, C, or D) \n";
	cin >> package;

	cout << fixed << showpoint << setprecision(2);

	switch (package)
	{
		case 'A':
		case 'a':
		{
			cout << "How many gigabytes did you use? \n";
			cin >> gigabytes;
			if (gigabytes <= 4)
			{
				total = 39.99;
				cout << "The total amount due is $" << total << endl;
			}
			else
			{
				total = 39.99 + (gigabytes - 4) * 10;
				cout << "The total amount due is $" << total << endl;
			}
			break;
		}
		case 'B':
		case 'b':
		{
			cout << "How many gigabytes did you use? \n";
			cin >> gigabytes;
			if (gigabytes <= 8)
			{
				total = 59.99;
				cout << "The total amount due is $" << total << endl;
			}
			else
			{
				total = 59.99 + (gigabytes - 8) * 5;
				cout << "The total amount due is $" << total << endl;
			}
			break;
		}
		case 'C':
		case 'c':
		{
			cout << "How many gigabytes did you use? \n";
			cin >> gigabytes;
			total = 69.99;
			cout << "The total amount due is $" << total << endl;
			break;
		}
		case 'D':
		case 'd':
		{
			cout << "Thank you! \n";
		}
		default:
		{
			cout << "That is not a valid choice. Run the program again and select a valid choice. \n";
		}
	}

	return 0;
}

/*
	Calculate your total amount due
	Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.
	Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.
	Package C: For $69.99 per month, unlimited data is provided.
	D: Quit
	Select a subscription package (Please answer with A, B, C, or D)
	a
	How many gigabytes did you use?
	4
	The total amount due is $39.99

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 12\Debug\assignment 12.exe (process 14284) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Calculate your total amount due
	Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.
	Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.
	Package C: For $69.99 per month, unlimited data is provided.
	D: Quit
	Select a subscription package (Please answer with A, B, C, or D)
	a
	How many gigabytes did you use?
	6
	The total amount due is $59.99

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 12\Debug\assignment 12.exe (process 15160) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Calculate your total amount due
	Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.
	Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.
	Package C: For $69.99 per month, unlimited data is provided.
	D: Quit
	Select a subscription package (Please answer with A, B, C, or D)
	b
	How many gigabytes did you use?
	8
	The total amount due is $59.99

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 12\Debug\assignment 12.exe (process 5400) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Calculate your total amount due
	Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.
	Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.
	Package C: For $69.99 per month, unlimited data is provided.
	D: Quit
	Select a subscription package (Please answer with A, B, C, or D)
	b
	How many gigabytes did you use?
	16
	The total amount due is $99.99

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 12\Debug\assignment 12.exe (process 6400) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Calculate your total amount due
	Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.
	Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.
	Package C: For $69.99 per month, unlimited data is provided.
	D: Quit
	Select a subscription package (Please answer with A, B, C, or D)
	c
	How many gigabytes did you use?
	25
	The total amount due is $69.99

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 12\Debug\assignment 12.exe (process 2828) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Calculate your total amount due
	Package A: For $39.99 per month, 4 gigabytes are provided. Additional data costs $10 per gigabyte.
	Package B: For $59.99 per month, 8 gigabytes are provided. Additional data costs $5 per gigabyte.
	Package C: For $69.99 per month, unlimited data is provided.
	D: Quit
	Select a subscription package (Please answer with A, B, C, or D)
	e
	That is not a valid choice. Run the program again and select a valid choice.

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 12\Debug\assignment 12.exe (process 5140) exited with code 0.
	Press any key to close this window . . .
*/