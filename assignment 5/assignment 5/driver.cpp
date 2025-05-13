//*****************************************************************************************************
//
//		File:					driver.cpp
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

#include "AList.h"
#include "stock.h"
using namespace std;
#include <fstream>  

//*****************************************************************************************************

int main()
{
    AList<Stock> stockList(8);

    if (stockList.isEmpty())
    {
        cout << "Stock AList is empty" << endl;
    }
    else
    {
        cout << "Stock AList is not empty" << endl;
    }

    ifstream stockFile("Stock.txt");

    if (stockFile.is_open())
    {
        Stock tempStock;
        string tempName,
               tempSymbol;
        double tempPrice;

        while ((getline(stockFile, tempName)) && (getline(stockFile, tempSymbol) && (stockFile >> tempPrice)))
        {
            stockFile.ignore();
            tempStock = Stock(tempName, tempSymbol, tempPrice);
            stockList.insert(tempStock);
        }

        stockFile.close();
    }
    else
    {
        cout << "failed to open file" << endl;
    }

    if (stockList.isFull())
    {
        cout << "Stock AList is full" << endl;
    }
    else
    {
        cout << "Stock AList is not full" << endl;
    }

    cout << "size of Stock AList: " << stockList.listSize() << endl;

    cout << endl;
    cout << "current contents of Stock AList: " << endl;
    stockList.print(cout);
    cout << endl;

    cout << endl;
    int loc;

    if (stockList.binarySearch(Stock("Sony", "SNE", 105.81), loc))
    {
        cout << "found Sony at location " << loc << endl;
    }
    else
    {
        cout << "Sony not found" << endl;
    }

    if (stockList.remove(Stock("Sony", "SNE", 105.81)))
    {
        cout << "removed Sony" << endl;
    }
    else
    {
        cout << "Sony not found" << endl;
    }

    cout << endl;
    cout << "updated Stock List after removing Sony:" << endl;
    stockList.print(cout);
    cout << endl;

    if (stockList.removeRange(1, 3))
    {
        cout << endl << "removed elements 1, 2, and 3" << endl;
    }
    else
    {
        cout << endl << "unable to remove elements 1, 2, and 3" << endl;
    }

    cout << "updated Stock List after removing elements 1, 2, and 3:" << endl;
    stockList.print(cout);
    cout << endl;

    return 0;
}

//*****************************************************************************************************

//Stock AList is empty
//Stock AList is full
//size of Stock AList: 8
//
//current contents of Stock AList:
//[0]Tesla | TSLA | 564.33 [1]Sony | SNE | 105.81 [2]NVIDIA | NVDA | 548.58 [3]Microsoft Corp. | MSFT | 28.11 [4]Motorola Inc. | MOT | 17.49 [5]Intel | INTC | 60.78 [6]Advanced Micro Devices | AMD | 84.51 [7]Apple | AAPL | 121.73
//
//found Sony at location 1
//removed Sony
//
//updated Stock List after removing Sony:
//[0]Tesla | TSLA | 564.33 [1]NVIDIA | NVDA | 548.58 [2]Microsoft Corp. | MSFT | 28.11 [3]Motorola Inc. | MOT | 17.49 [4]Intel | INTC | 60.78 [5]Advanced Micro Devices | AMD | 84.51 [6]Apple | AAPL | 121.73
//
//removed elements 1, 2, and 3
//updated Stock List after removing elements 1, 2, and 3:
//[0]Tesla | TSLA | 564.33 [1]Intel | INTC | 60.78 [2]Advanced Micro Devices | AMD | 84.51 [3]Apple | AAPL | 121.73
//
//C:\Users\avdom\OneDrive\Documents\source\repos\data structures II\assignment 5\x64\Debug\assignment 5.exe (process 1908) exited with code 0.
//Press any key to close this window . . .