// *************************************************
// 
//  Assignment:    #8
//  File:          coin_collection.cpp
//
//  Due Date:      September 24, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program converts a collection of
//				   coins to total amount of money
//
// *************************************************

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numberOfQuarters,
		numberOfDimes,
		numberOfNickels,
		numberOfPennies;

	double quarters,
		   dimes,
		   nickels,
		   pennies;

	cout << "Register your coin collection to see the total amount in dollars and cents \n";
	
	cout << "Enter number of quarters: \n";
	cin >> numberOfQuarters;
	cout << "Enter number of dimes: \n";
	cin >> numberOfDimes;
	cout << "Enter number of nickels: \n";
	cin >> numberOfNickels;
	cout << "Enter number of pennies: \n";
	cin >> numberOfPennies;

	quarters = numberOfQuarters * 0.25;
	dimes = numberOfDimes * 0.10;
	nickels = numberOfNickels * 0.05;
	pennies = numberOfPennies * 0.01;

	double total = quarters + dimes + nickels + pennies;
	int dollars = (total * 100) / 100;
	int cents = (int)(total * 100) % 100;

	cout << "You have " << dollars << " dollars and " << cents << " cents" << endl;

	return 0;
}

/*
	Register your coin collection to see the total amount in dollars and cents
	Enter number of quarters:
	12
	Enter number of dimes:
	6
	Enter number of nickels:
	35
	Enter number of pennies:
	55
	You have 5 dollars and 90 cents

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 8\Debug\assignment 8.exe (process 8196) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	Register your coin collection to see the total amount in dollars and cents
	Enter number of quarters:
	16
	Enter number of dimes:
	12
	Enter number of nickels:
	41
	Enter number of pennies:
	8
	You have 7 dollars and 33 cents

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 8\Debug\assignment 8.exe (process 4980) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	Register your coin collection to see the total amount in dollars and cents
	Enter number of quarters:
	10
	Enter number of dimes:
	10
	Enter number of nickels:
	10
	Enter number of pennies:
	10
	You have 4 dollars and 10 cents

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 8\Debug\assignment 8.exe (process 3328) exited with code 0.
	Press any key to close this window . . .
*/