// *************************************************
// 
//  Assignment:    #7
//  File:          monthly_sales_tax.cpp
//
//  Due Date:      September 17, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program computes sales tax and
//				   displays the data in a table
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	cout << "Enter the month: " << endl;
	string month;
	cin >> month;

	cout << "Enter the year: " << endl;
	string year;
	cin >> year;

	cout << "Enter the total collected: " << endl;
	double totalCollected;
	cin >> totalCollected;

	double countySalesTaxPercent = 0.02;
	double stateSalesTaxPercent = 0.04;
	double sales = totalCollected / 1.06;
	double countySalesTax = sales * countySalesTaxPercent;
	double stateSalesTax = sales * stateSalesTaxPercent;
	double totalSalesTax = countySalesTax + stateSalesTax;

	cout << fixed << showpoint << setprecision(2);

	cout << "\n";
	cout << "Month: " << month << endl;
	cout << "Year: " << year << endl;
	cout << "-----------------" << endl;
	cout << left << setw(12) << "Total Collected: " << right << setw(5) << "$ " << setw(6) << totalCollected << endl;
	cout << left << setw(12) << "Sales: " << right << setw(10) << "$ " << setw(6) << sales << endl;
	cout << left << setw(12) << "County Sales Tax: " << right << setw(4) << "$ " << setw(8) << countySalesTax << endl;
	cout << left << setw(12) << "State Sales Tax: " << right << setw(5) << "$ " << setw(8) << stateSalesTax << endl;
	cout << left << setw(12) << "Total Sales Tax: " << right << setw(5) << "$ " << setw(8) << totalSalesTax << endl;

	return 0;
}

/*
	Enter the month:
	October
	Enter the year:
	2020
	Enter the total collected:
	26572.89

	Month: October
	Year: 2020
	-----------------
	Total Collected:    $ 26572.89
	Sales:              $ 25068.76
	County Sales Tax:   $   501.38
	State Sales Tax:    $  1002.75
	Total Sales Tax:    $  1504.13

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 7\Debug\assignment 7.exe (process 13304) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	Enter the month:
	March
	Enter the year:
	2009
	Enter the total collected:
	11312.15

	Month: March
	Year: 2009
	-----------------
	Total Collected:    $ 11312.15
	Sales:              $ 10671.84
	County Sales Tax:   $   213.44
	State Sales Tax:    $   426.87
	Total Sales Tax:    $   640.31

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 7\Debug\assignment 7.exe (process 13288) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	Enter the month:
	June
	Enter the year:
	1996
	Enter the total collected:
	50834.32

	Month: June
	Year: 1996
	-----------------
	Total Collected:    $ 50834.32
	Sales:              $ 47956.91
	County Sales Tax:   $   959.14
	State Sales Tax:    $  1918.28
	Total Sales Tax:    $  2877.41

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 7\Debug\assignment 7.exe (process 13236) exited with code 0.
	Press any key to close this window . . .
*/