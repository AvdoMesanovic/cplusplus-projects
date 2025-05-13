//*****************************************************************************************************
//
//		File:					LListStockDriver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #2
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 11th, 2023
//
//
//		This program uses default arguments to call a single function in various different
//		ways to display a message.
//	
//		Other files required:
//			1. stock.h - the class definition for a stock
//			2. LList.h - definition of the LList class
//			
//*****************************************************************************************************

using namespace std;
#include "LList.h"
#include "stock.h"

//*****************************************************************************************************

int main()
{
	LList<Stock> stockList;

	Stock tesla("Tesla", "TSLA", 128.3);
	Stock microsoft("Microsoft", "MSFT", 89.1);
	Stock apple("Apple", "APPL", 51.7);

	cout << "list content: " << endl;
	stockList.printList();
	cout << endl;

	stockList.insertDescendingOrder(tesla);
	stockList.insertDescendingOrder(microsoft);
	stockList.insertDescendingOrder(apple);

	cout << "list content: " << endl;
	stockList.printList();
	cout << endl;

	stockList.deleteNode(tesla);
	stockList.deleteNode(microsoft);
	stockList.deleteNode(apple);

	cout << "list content: " << endl;
	stockList.printList();
	cout << endl;

	return 0;
}

//*****************************************************************************************************

//list content:
//
//list content:
//Tesla | TSLA | 128.3
//Microsoft | MSFT | 89.1
//Apple | APPL | 51.7
//
//list content:
//