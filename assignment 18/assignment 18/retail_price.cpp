// *************************************************
// 
//  Assignment:    #18
//  File:          retail_price.cpp
//
//  Due Date:      November 15, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program asks the user for the wholesale cost and markup
//				   percentage to calculate the final retail price of an item
//
// *************************************************

#include <iostream>
#include <iomanip>
using namespace std;

double getWholeSale();
double getMarkUp();
double calculateRetail(double, double);
void report(double);


int main()
{
	char repeat;
	cout << fixed << showpoint << setprecision(2);

	do
	{
		double cost = getWholeSale();
		double percentage = getMarkUp();
		double retailPrice = calculateRetail(cost, percentage);
		report(retailPrice);
		cout << "Would you like to do another markup? Please enter Y to continue or N to stop \n";
		cin >> repeat;
		repeat = toupper(repeat);
	} while (repeat != 'N');

	return 0;
}

// *************************************************
// This function prompts the user to enter a number for the wholesale of the item
double getWholeSale()
{
	int wholeSale;
	cout << "Enter the wholesale cost \n";
	cin >> wholeSale;
	while (wholeSale < 0)
	{
		cout << "Enter a positive number for wholesale \n";
		cin >> wholeSale;
	}
	return wholeSale;
}

// *************************************************
// This function prompts the user to enter a number for the markup of the item
double getMarkUp()
{
	int markUp;
	cout << "Enter the markup \n";
	cin >> markUp;
	while (markUp < 0)
	{
		cout << "Enter a positive number for markup \n";
		cin >> markUp;
	}
	return markUp;
}

// *************************************************
// This function calculates and returns the retail price of the item
double calculateRetail(double cost, double percentage)
{
	double retailPrice = 0;
	retailPrice = ((cost / 100) * percentage) + cost;
	return retailPrice;
}

// *************************************************
// This function prints the retail price passed from main
void report(double retailPrice)
{
	cout << "The retail price is $" << retailPrice << endl;
}

/*
	Enter the wholesale cost
	-1
	Enter a positive number for wholesale
	5
	Enter the markup
	-1
	Enter a positive number for markup
	100
	The retail price is $10.00
	Would you like to do another markup? Please enter Y to continue or N to stop
	y
	Enter the wholesale cost
	10
	Enter the markup
	50
	The retail price is $15.00
	Would you like to do another markup? Please enter Y to continue or N to stop
	n

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 18\Debug\assignment 18.exe (process 3620) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Enter the wholesale cost
	-1
	Enter a positive number for wholesale
	10
	Enter the markup
	35
	The retail price is $13.50
	Would you like to do another markup? Please enter Y to continue or N to stop
	y
	Enter the wholesale cost
	26
	Enter the markup
	-1
	Enter a positive number for markup
	47
	The retail price is $38.22
	Would you like to do another markup? Please enter Y to continue or N to stop
	n

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 18\Debug\assignment 18.exe (process 11516) exited with code 0.
	Press any key to close this window . . .
*/