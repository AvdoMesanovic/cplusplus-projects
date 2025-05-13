//*****************************************************************************************************
//
//		File:					stock.h
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
//		Other files required: N/A
//			
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <iostream>
#include <string>
using namespace std;

//*****************************************************************************************************

class Stock
{
private:
	string companyName;
	string stockSymbol;
	double stockPrice;

public:
	Stock(const string& name = "", const string& symbol = "", double price = 0);
	Stock(const Stock& s);
	void display() const;
	string getName() const;
	string getSymbol() const;
	double getPrice() const;
	bool operator==(const Stock& rhs) const;
	bool operator!=(const Stock& rhs) const;
	bool operator<(const Stock& rhs) const;
	bool operator>(const Stock& rhs) const;
	friend ostream& operator<<(ostream& out, const Stock& data);
};

//*****************************************************************************************************

inline string Stock::getName() const
{
	return companyName;
}

//*****************************************************************************************************

inline string Stock::getSymbol() const
{
	return stockSymbol;
}

//*****************************************************************************************************

inline double Stock::getPrice() const
{
	return stockPrice;
}

//*****************************************************************************************************

inline bool Stock::operator==(const Stock& rhs) const
{
	return (this->stockSymbol == rhs.stockSymbol);
}

//*****************************************************************************************************

inline bool Stock::operator!=(const Stock& rhs) const
{
	return (this->stockSymbol != rhs.stockSymbol);
}

//*****************************************************************************************************

inline bool Stock::operator<(const Stock& rhs) const
{
	return (this->stockSymbol < rhs.stockSymbol);
}

//*****************************************************************************************************

inline bool Stock::operator>(const Stock& rhs) const
{
	return (this->stockSymbol > rhs.stockSymbol);
}

//*****************************************************************************************************

#endif