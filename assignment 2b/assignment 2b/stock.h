//*****************************************************************************************************
//
//		File:					stock.h
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

string Stock::getName() const
{
	return companyName;
}

//*****************************************************************************************************

string Stock::getSymbol() const
{
	return stockSymbol;
}

//*****************************************************************************************************
double Stock::getPrice() const
{
	return stockPrice;
}

//*****************************************************************************************************

bool Stock::operator==(const Stock& rhs) const
{
	return (this->stockSymbol == rhs.stockSymbol);
}

//*****************************************************************************************************

bool Stock::operator!=(const Stock& rhs) const
{
	return (this->stockSymbol != rhs.stockSymbol);
}

//*****************************************************************************************************

bool Stock::operator<(const Stock& rhs) const
{
	return (this->stockSymbol < rhs.stockSymbol);
}

//*****************************************************************************************************

bool Stock::operator>(const Stock& rhs) const
{
	return (this->stockSymbol > rhs.stockSymbol);
}

//*****************************************************************************************************

ostream& operator<<(ostream& out, const Stock& data)
{
	out << data.companyName << " | " << data.stockSymbol << " | " << data.stockPrice;

	return out;
}

//*****************************************************************************************************

#endif