//*****************************************************************************************************
//
//		File:					stock.cpp
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
//		This program implements a Stock class and utilizes several functions to employ it.
//	
//		Other files required:
//          1. stock.h
//			
//*****************************************************************************************************

#include "stock.h"

//*****************************************************************************************************

Stock::Stock(const string& name, const string& symbol, double price)
{
    companyName = name;
    stockSymbol = symbol;
    stockPrice = price;
}

//*****************************************************************************************************

Stock::Stock(const Stock& s)
{
    companyName = s.companyName;
    stockSymbol = s.stockSymbol;
    stockPrice = s.stockPrice;
}

//*****************************************************************************************************

void Stock::display() const
{
    cout << "Company name is " << companyName << endl;
    cout << "Stock symbol is " << stockSymbol << endl;
    cout << "Stock price is $" << stockPrice << endl;
}

//*****************************************************************************************************

ostream& operator<<(ostream& out, const Stock& data)
{
    out << data.companyName << " | " << data.stockSymbol << " | " << data.stockPrice;

    return out;
}

//*****************************************************************************************************
