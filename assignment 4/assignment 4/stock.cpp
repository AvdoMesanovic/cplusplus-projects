//*****************************************************************************************************
//
//		File:					stock.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #4
// 
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					September 21st, 2023
//			
//*****************************************************************************************************

#include "stock.h"

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
    out << data.companyName << " | " << data.stockSymbol << " | " << data.stockPrice;

    return out;
}

//******************************************************************************************************

int Stock::hash(int size) const
{
    int hashValue = 0;

    for (int i = 0; i < stockSymbol.size(); i++)
    {
        hashValue += stockSymbol[i];
    }

    return hashValue % size;
}

//******************************************************************************************************
