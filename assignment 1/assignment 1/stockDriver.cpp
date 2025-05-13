//*****************************************************************************************************
//
//		File:					stockDriver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #1
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 4th, 2023
//
//
//		This program uses default arguments to call a single function in various different
//		ways to display a message.
//	
//		Other files required:
//			1. stock.h - the class definition for a stock
//			
//*****************************************************************************************************

#include "stock.h"
using namespace std;

//*****************************************************************************************************

int main()
{
	Stock tesla("Tesla", "TSLA", 128.3);
	Stock microsoft("Microsoft", "MSFT", 89.1);
	Stock test("Test", "TSLA", 51.7);

	string testName;
	string testSymbol;
	double testPrice;

	cout << "Stock 1:" << endl;
	tesla.display();
	cout << endl;
	
	cout << "Stock 2:" << endl;
	microsoft.display();
	cout << endl;

	cout << "Stock 3:" << endl;
	testName = test.getName();
	testSymbol = test.getSymbol();
	testPrice = test.getPrice();
	cout << "Company name is " << testName << endl;
	cout << "Stock symbol is " << testSymbol << endl;
	cout << "Stock price is $" << testPrice << endl;
	cout << endl;

	if (tesla == microsoft)
	{
		cout << "Tesla and Microsoft have the same symbol" << endl;
	}
	else
	{
		cout << "Tesla and Microsoft do not have the same symbol" << endl;
	}

	if (tesla == test)
	{
		cout << "Tesla and Test have the same symbol" << endl;
	}
	else	
	{
		cout << "Tesla and Test do not have the same symbol" << endl;
	}

	return 0;
}

//*****************************************************************************************************



