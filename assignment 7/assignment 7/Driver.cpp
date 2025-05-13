//*****************************************************************************************************
//
//		File:					Driver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #7
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					October 30th, 2023
//		
//*****************************************************************************************************

#include "PriorityQueue.h"
#include "Stock.h"
using namespace std;
#include <fstream>

//*****************************************************************************************************

int main()
{
    PriorityQueue<Stock> stockQueue;
    ifstream inputFile("Stock.txt");

    if (inputFile.is_open())
    {
        Stock tempStock;
        string tempName,
               tempSymbol;
        double tempPrice;

        while ((getline(inputFile, tempName)) && (getline(inputFile, tempSymbol) && (inputFile >> tempPrice)))
        {
            inputFile.ignore();
            tempStock = Stock(tempName, tempSymbol, tempPrice);
            stockQueue.enqueue(tempStock);
        }

        inputFile.close();
    }
    else
    {
        cout << "failed to open file" << endl;
    }

    stockQueue.display();
    cout << endl;

    Stock removed1,
          removed2, 
          removed3, 
          removed4,
          removed5;

    if (stockQueue.dequeue(removed1))
    {
        cout << removed1 << " removed" << endl;
    }

    if (stockQueue.dequeue(removed2))
    {
        cout << removed2 << " removed" << endl;
    }

    if (stockQueue.dequeue(removed3))
    {
        cout << removed3 << " removed" << endl;
    }

    if (stockQueue.dequeue(removed4))
    {
        cout << removed4 << " removed" << endl;
    }

    if (stockQueue.dequeue(removed5))
    {
        cout << removed5 << " removed" << endl;
    }

    cout << endl;

    cout << "stockQueue after removal:" << endl;
    cout << "-------------------------" << endl;
    stockQueue.display();

    return 0;
}

//*****************************************************************************************************

//Tesla | TSLA | 564.33
//Amazon Inc. | AMZN | 212.23
//NVIDIA | NVDA | 548.58
//Sony | SNE | 105.81
//Apple | AAPL | 121.73
//Avdo Corporation | AVDC | 357.89
//JPMorgan Chase & Co | JPM | 135.69
//Motorola Inc. | MOT | 17.49
//Google | GOOGL | 92.83
//Intel | INTC | 60.78
//Samsung Electronics | SSEL | 57.91
//Peloton Interactive | PTON | 10.11
//Microsoft Corp. | MSFT | 28.11
//Bank of America Corp | BAC | 25.17
//Advanced Micro Devices | AMD | 84.51
//
//Tesla | TSLA | 564.33 removed
//NVIDIA | NVDA | 548.58 removed
//Avdo Corporation | AVDC | 357.89 removed
//Amazon Inc. | AMZN | 212.23 removed
//JPMorgan Chase & Co | JPM | 135.69 removed
//
//stockQueue after removal:
//-------------------------
//Apple | AAPL | 121.73
//Sony | SNE | 105.81
//Advanced Micro Devices | AMD | 84.51
//Google | GOOGL | 92.83
//Intel | INTC | 60.78
//Peloton Interactive | PTON | 10.11
//Bank of America Corp | BAC | 25.17
//Motorola Inc. | MOT | 17.49
//Samsung Electronics | SSEL | 57.91
//Microsoft Corp. | MSFT | 28.11