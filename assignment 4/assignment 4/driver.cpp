//*****************************************************************************************************
//
//		File:					driver.cpp
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
#include "hashTable.h"
using namespace std;

//*****************************************************************************************************

int main()
{
	HashTable<Stock> stockTable(5);
	Stock microsoft("Microsoft", "MSFT", 89.1);
	Stock tesla("Tesla", "TSLA", 128.3);
	Stock apple("Apple", "APPL", 51.7);

	stockTable.insert(microsoft);
	stockTable.insert(tesla);
	stockTable.insert(apple);
	stockTable.display();

	cout << endl;

	Stock* ptr = stockTable.search(microsoft);

	if (ptr != nullptr)
	{
		cout << "Stock found!" << endl;
	}
	else
	{
		cout << "Unable to find stock" << endl;
	}

	Stock facebook("Facebook", "FCBK", 202.3);
	Stock* ptr1 = stockTable.search(facebook);

	if (ptr1 != nullptr)
	{
		cout << "Stock found!" << endl;
	}
	else
	{
		cout << "Unable to find stock" << endl;
	}
	
	cout << endl;

	cout << "After removal:" << endl;
	cout << "___" << endl;
	stockTable.remove(tesla);
	stockTable.remove(apple);
	stockTable.display();

	return 0;
}

//*****************************************************************************************************

//Company name is
//Stock symbol is
//Stock price is $0
//___
//Company name is Apple
//Stock symbol is APPL
//Stock price is $51.7
//___
//Company name is
//Stock symbol is
//Stock price is $0
//___
//Company name is Tesla
//Stock symbol is TSLA
//Stock price is $128.3
//___
//Company name is Microsoft
//Stock symbol is MSFT
//Stock price is $89.1
//___
//
//Stock found!
//Unable to find stock
//
//After removal :
//___
//Company name is
//Stock symbol is
//Stock price is $0
//___
//Company name is
//Stock symbol is
//Stock price is $0
//___
//Company name is
//Stock symbol is
//Stock price is $0
//___
//Company name is
//Stock symbol is
//Stock price is $0
//___
//Company name is Microsoft
//Stock symbol is MSFT
//Stock price is $89.1
//___
//
//C : \Users\avdom\OneDrive\Documents\source\repos\data structures II\assignment 4\x64\Debug\assignment 4.exe(process 5372) exited with code 0.
//To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
//Press any key to close this window . . .
