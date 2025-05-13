//*****************************************************************************************************
//
//		File:					Stock.h
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

#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <iostream>
#include <string>

//*****************************************************************************************************

class Stock
{
private:
	std::string companyName;
	std::string stockSymbol;
	double stockPrice;

public:
	Stock(const std::string& name = "", const std::string& symbol = "", double price = 0);
	Stock(const Stock& s);
	void display() const;
	std::string getName() const;
	std::string getSymbol() const;
	double getPrice() const;
	bool operator==(const Stock& rhs) const;
	bool operator!=(const Stock& rhs) const;
	bool operator<(const Stock& rhs) const;
	bool operator>(const Stock& rhs) const;
	friend std::ostream& operator<<(std::ostream& out, const Stock& data);
};

//*****************************************************************************************************

inline std::string Stock::getName() const
{
	return companyName;
}

//*****************************************************************************************************

inline std::string Stock::getSymbol() const
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