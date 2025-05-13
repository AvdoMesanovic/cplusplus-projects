//*****************************************************************************************************
//
//		File:					driver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #3
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 18th, 2023
//
//
//		This program explores the List ADT and utilizes several functions to employ it.
//	
//		Other files required:
//			1. AList.h
//          2. stock.cpp
//			
//*****************************************************************************************************

using namespace std;
#include "AList.h"
#include "stock.h"

//*****************************************************************************************************

int main()
{
    AList<int> intList(5);

    if (intList.isEmpty())
    {
        cout << "int AList is empty" << endl;
    }
    else
    {
        cout << "int AList is not empty" << endl;
    }

    intList.insert(5);
    intList.insert(4);
    intList.insert(3);
    intList.insert(2);
    intList.insert(1);

    if (intList.isFull())
    {
        cout << "int AList is full" << endl;
    }
    else
    {
        cout << "int AList is not full" << endl;
    }

    cout << "size of int AList: " << intList.listSize() << endl;

    cout << "contents of int AList: " << endl;
    intList.print();

    cout << endl;

    int intResult = intList.binarySearch(5);

    if (intResult != -1)
    {
        cout << "int " << 5 << " found at index " << intResult << endl;
    }
    else
    {
        cout << "int is not in the intList" << endl;
    }

    cout << endl;

    AList<Stock> stockList(5);

    if (stockList.isEmpty())
    {
        cout << "Stock AList is empty" << endl;
    }
    else
    {
        cout << "Stock AList is not empty" << endl;
    }

    stockList.insert(Stock("Google", "GOOGL", 87.5));
    stockList.insert(Stock("Tesla", "TSLA", 156.9));
    stockList.insert(Stock("Microsoft", "MSFT", 101.2));
    stockList.insert(Stock("Apple", "APPL", 300.6));
    stockList.insert(Stock("S&P500", "SPY", 467));

    if (stockList.isFull())
    {
        cout << "Stock AList is full" << endl;
    }
    else
    {
        cout << "Stock AList is not full" << endl;
    }

    cout << "size of Stock AList: " << stockList.listSize() << endl;

    cout << "contents of Stock AList: " << endl;
    stockList.print();

    cout << endl;

    int stockResult;
    stockResult = stockList.binarySearch(Stock("Tesla", "TSLA", 156.9));

    if (stockResult != -1)
    {
        cout << "stock found at index " << stockResult << endl;
    }
    else
    {
        cout << "stock not found in the stockList" << endl;
    }

	return 0;
}

//*****************************************************************************************************