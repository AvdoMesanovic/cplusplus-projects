//*****************************************************************************************************
//
//		File:					Stock.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #5
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					October 2nd, 2023
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
