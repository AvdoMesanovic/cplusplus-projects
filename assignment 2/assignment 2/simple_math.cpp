// *************************************************
// 
//  Assignment:    #2
//  File:          simple_math.cpp
//
//  Due Date:      September 3, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program calculates the sum, difference,
//                 product, and quotient of two integers
//
// *************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int number1 = 7;
	int number2 = 2;
	int sum = number1 + number2;
	cout << "The sum of " << number1 << " and " << number2 << " is " << sum << endl;

	int difference = number1 - number2;
	cout << "The difference of " << number1 << " and " << number2 << " is " << difference << endl;

	int product = number1 * number2;
	cout << "The product of " << number1 << " and " << number2 << " is " << product << endl;

	double quotient;
	cout << fixed << showpoint << setprecision(2);
	quotient = static_cast<double>(number1) / number2;
	cout << "The quotient of " << number1 << " divided by " << number2 << " is " << quotient << endl;

	return 0;
}

/*
	The sum of 7 and 2 is 9
	The difference of 7 and 2 is 5
	The product of 7 and 2 is 14
	The quotient of 7 divided by 2 is 3.50

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 2\Debug\assignment 2.exe (process 12336) exited with code 0.
	Press any key to close this window . . .
*/