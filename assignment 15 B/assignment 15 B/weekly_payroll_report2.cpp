// *************************************************
// 
//  Assignment:    #15(B)
//  File:          weekly_payroll_report2.cpp
//
//  Due Date:      October 29, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program displays a weekly 
//				   payroll report for a company
//
// *************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double employeeNumber = 1,
		grossPay,
		witholdings,
		totalGrossPay = 0,
		totalWitholdings = 0,
		netTotal;

	cout << fixed << showpoint << setprecision(2);
	cout << "Enter the following information: \n";
	cout << "Enter a positive employee number (0 to quit): \n";
	cin >> employeeNumber;

	while (employeeNumber != 0)
	{
		while (employeeNumber < 0)
		{
			cout << "Employee number must be positive, try again \n";
			cin >> employeeNumber;
		}
		cout << "Enter gross pay: \n";
		cin >> grossPay;
		while (grossPay < 0)
		{
			cout << "Gross pay can not be negative, try again \n";
			cin >> grossPay;
		}
		cout << "Enter any witholdings \n";
		cin >> witholdings;
		while (witholdings > grossPay)
		{
			cout << "witholdings can not be greater than gross pay, try again \n";
			cin >> witholdings;
		}
		cout << "Enter a positive employee number (0 to quit): \n";
		cin >> employeeNumber;
		totalGrossPay += grossPay;
		totalWitholdings += witholdings;
		netTotal = totalGrossPay - totalWitholdings;
	}

	cout << "Total gross pay: " << right << setw(6) << "$ " << totalGrossPay << endl;
	cout << "Total witholdings: " << right << setw(4) << "$ " << setw(7) << totalWitholdings << endl;
	cout << "Net total: " << right << setw(12) << "$ " << netTotal << endl;

	return 0;
}

/*
	Enter the following information:
	Enter a positive employee number (0 to quit):
	-1
	Employee number must be positive, try again
	1
	Enter gross pay:
	500
	Enter any witholdings
	50
	Enter a positive employee number (0 to quit):
	-2
	Employee number must be positive, try again
	2
	Enter gross pay:
	500
	Enter any witholdings
	50
	Enter a positive employee number (0 to quit):
	3
	Enter gross pay:
	500
	Enter any witholdings
	50
	Enter a positive employee number (0 to quit):
	4
	Enter gross pay:
	500
	Enter any witholdings
	50
	Enter a positive employee number (0 to quit):
	0
	Total gross pay:     $ 2000.00
	Total witholdings:   $  200.00
	Net total:           $ 1800.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 15 B\Debug\assignment 15 B.exe (process 2252) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Enter the following information:
	Enter a positive employee number (0 to quit):
	1
	Enter gross pay:
	-500
	Gross pay can not be negative, try again
	500
	Enter any witholdings
	100
	Enter a positive employee number (0 to quit):
	2
	Enter gross pay:
	-500
	Gross pay can not be negative, try again
	500
	Enter any witholdings
	501
	witholdings can not be greater than gross pay, try again
	100
	Enter a positive employee number (0 to quit):
	3
	Enter gross pay:
	500
	Enter any witholdings
	100
	Enter a positive employee number (0 to quit):
	4
	Enter gross pay:
	500
	Enter any witholdings
	100
	Enter a positive employee number (0 to quit):
	0
	Total gross pay:     $ 2000.00
	Total witholdings:   $  400.00
	Net total:           $ 1600.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 15 B\Debug\assignment 15 B.exe (process 12224) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Enter the following information:
	Enter a positive employee number (0 to quit):
	1
	Enter gross pay:
	1000
	Enter any witholdings
	200
	Enter a positive employee number (0 to quit):
	2
	Enter gross pay:
	1000
	Enter any witholdings
	200
	Enter a positive employee number (0 to quit):
	3
	Enter gross pay:
	1000
	Enter any witholdings
	200
	Enter a positive employee number (0 to quit):
	4
	Enter gross pay:
	100
	Enter any witholdings
	1
	Enter a positive employee number (0 to quit):
	0
	Total gross pay:     $ 3100.00
	Total witholdings:   $  601.00
	Net total:           $ 2499.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 15 B\Debug\assignment 15 B.exe (process 5260) exited with code 0.
	Press any key to close this window . . .
*/