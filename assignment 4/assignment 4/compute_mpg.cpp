// *************************************************
// 
//  Assignment:    #4
//  File:          compute_mpg.cpp
//
//  Due Date:      September 10, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program calculates miles per gallon  
//
// *************************************************

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int milesDriven;
	cout << "Type miles driven: " << endl;
	cin >> milesDriven;

	int gallonsUsed;
	cout << "Type gallons used: " << endl;
	cin >> gallonsUsed;

	cout << "The car drove " << milesDriven << " miles on " << gallonsUsed << " gallons of gas" << endl;

	double milesPerGallon;
	milesPerGallon = static_cast<double>(milesDriven) / gallonsUsed;
	cout << fixed << showpoint << setprecision(2);
	cout << "Miles per gallon is " << milesPerGallon << endl;

	return 0;
}

/*
	Type miles driven:
	350
	Type gallons used:
	12
	The car drove 350 miles on 12 gallons of gas
	Miles per gallon is 29.17

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 4\Debug\assignment 4.exe (process 16400) exited with code 0.
	Press any key to close this window . . .
------------------------------------------------------------------------------------------------------
	Type miles driven:
	1738
	Type gallons used:
	10
	The car drove 1738 miles on 10 gallons of gas
	Miles per gallon is 173.80

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 4\Debug\assignment 4.exe (process 6564) exited with code 0.
	Press any key to close this window . . .
------------------------------------------------------------------------------------------------------
	Type miles driven:
	1026
	Type gallons used:
	14
	The car drove 1026 miles on 14 gallons of gas
	Miles per gallon is 73.29

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 4\Debug\assignment 4.exe (process 4488) exited with code 0.
	Press any key to close this window . . .
*/