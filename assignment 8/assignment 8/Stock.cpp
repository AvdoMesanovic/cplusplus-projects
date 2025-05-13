//*****************************************************************************************************
//
//		File:					Stock.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 4th, 2023
//		
//*****************************************************************************************************

#include "Stock.h"

//*****************************************************************************************************

Stock::Stock(const std::string& name, const std::string& symbol, double price)
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
    std::cout << "Company name is " << companyName << std::endl;
    std::cout << "Stock symbol is " << stockSymbol << std::endl;
    std::cout << "Stock price is $" << stockPrice << std::endl;
}

//*****************************************************************************************************

std::ostream& operator<<(std::ostream& out, const Stock& data)
{
    out << data.companyName << std::endl << data.stockSymbol << std::endl << data.stockPrice;

    return out;
}

//*****************************************************************************************************
