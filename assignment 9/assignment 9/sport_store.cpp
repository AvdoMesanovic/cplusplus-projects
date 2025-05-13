// *************************************************
// 
//  Assignment:    #9
//  File:          sport_store.cpp
//
//  Due Date:      September 24, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program displays a store that sells baseballs
//
// *************************************************

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int numberOfBalls,
		price1 = 4,
		price2 = 7,
		quotient,
		remainder,
		totalPrice{};
	double totalPriceAsDouble;

	cout << "The price for one baseball is $4.00 \n";
	cout << "The price for two baseballs is $7.00 \n";
	cout << "How many balls would you like? \n";
	cin >> numberOfBalls;

	if (numberOfBalls % 2 == 0)
	{
		totalPrice = (numberOfBalls / 2) * price2;
	}
	else if (numberOfBalls % 2 != 0)
	{
		quotient = (numberOfBalls / 2) * price2;
		remainder = (numberOfBalls % 2) * price1;
		totalPrice = quotient + remainder;
	}

	cout << fixed << showpoint << setprecision(2);
	totalPriceAsDouble = static_cast<double>(totalPrice);

	cout << "Your total price for " << numberOfBalls << " balls will be $" << totalPriceAsDouble << endl;

	return 0;
}

/*
	The price for one baseball is $4.00
	The price for two baseballs is $7.00
	How many balls would you like?
	8
	Your total price for 8 balls will be $28.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 9\Debug\assignment 9.exe (process 8824) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	The price for one baseball is $4.00
	The price for two baseballs is $7.00
	How many balls would you like?
	12
	Your total price for 12 balls will be $42.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 9\Debug\assignment 9.exe (process 2784) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	The price for one baseball is $4.00
	The price for two baseballs is $7.00
	How many balls would you like?
	7
	Your total price for 7 balls will be $25.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 9\Debug\assignment 9.exe (process 3924) exited with code 0.
	Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------------
	The price for one baseball is $4.00
	The price for two baseballs is $7.00
	How many balls would you like?
	11
	Your total price for 11 balls will be $39.00

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 9\Debug\assignment 9.exe (process 14516) exited with code 0.
	Press any key to close this window . . .
*/