//*****************************************************************************************************
//
//		File:					Driver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 29th, 2023
//		
//*****************************************************************************************************

#include "Stock.h"
#include "SortedList.h"
using namespace std;
#include <fstream>  

//*****************************************************************************************************

int main()
{
    SortedList<Stock> stockList;
    ifstream inputFile("Stock.txt");

    if (!inputFile.is_open())
    {
        cout << "error opening the file.\n";
        return 1;
    }

    if (inputFile.is_open())
    {
        string name,
            symbol;
        double price;

        while (getline(inputFile, name) && getline(inputFile, symbol) && inputFile >> price)
        {
            inputFile.ignore();
            Stock stock(name, symbol, price);
            stockList.insert(stock);
        }

        inputFile.close();
    }
    else
    {
        cout << "failed to open 'Stock.txt'" << endl;
    }

    Stock avdocorp("Avdo Corporation", "AVDC", 999.34);
    Stock lightinc("Light Incorporated", "LINC", 222.91);
    Stock darkholdings("Dark Holdings", "DHOL", 555.61);
    stockList.insert(avdocorp);
    stockList.insert(lightinc);
    stockList.insert(darkholdings);

    cout << "original list\n";
    cout << "--------------" << endl;
    stockList.display();

    stockList.randomise();
    cout << "\nafter randomization\n";
    cout << "--------------------" << endl;
    stockList.display();

    stockList.selectionSortA();
    cout << "\nafter ascending selection sort\n";
    cout << "---------------------------------" << endl;
    stockList.display();

    stockList.randomise();
    cout << "\nafter randomization:\n";
    cout << "--------------------" << endl;
    stockList.display();

    stockList.selectionSortD();
    cout << "\nafter descending selection sort\n";
    cout << "----------------------------------" << endl;
    stockList.display();

    stockList.randomise();
    cout << "\nafter randomization\n";
    cout << "--------------------" << endl;
    stockList.display();

    stockList.quickSortA();
    cout << "\nafter ascending quick sort\n";
    cout << "----------------------------" << endl;
    stockList.display();

    stockList.randomise();
    cout << "\nafter randomization\n";
    cout << "--------------------" << endl;
    stockList.display();

    stockList.quickSortD();
    cout << "\nafter descending quick sort\n";
    cout << "----------------------------------" << endl;
    stockList.display();

    stockList.randomise();
    cout << "\nafter randomization\n";
    cout << "--------------------" << endl;
    stockList.display();

    stockList.heapSortA();
    cout << "\nafter ascending heap sort\n";
    cout << "----------------------------------" << endl;
    stockList.display();

    stockList.randomise();
    cout << "\nafter randomization\n";
    cout << "--------------------" << endl;
    stockList.display();

    stockList.heapSortD();
    cout << "\nafter descending heap sort\n";
    cout << "----------------------------------" << endl;
    stockList.display();

    return 0;
}

//*****************************************************************************************************

//original list
//--------------
//Motorola Inc.
//MOT
//17.49
//Microsoft Corp.
//MSFT
//28.11
//Tesla
//TSLA
//564.33
//Intel
//INTC
//60.78
//Sony
//SNE
//105.81
//Advanced Micro Devices
//AMD
//84.51
//NVIDIA
//NVDA
//548.58
//Apple
//AAPL
//121.73
//Avdo Corporation
//AVDC
//999.34
//Light Incorporated
//LINC
//222.91
//Dark Holdings
//DHOL
//555.61
//
//after randomization
//--------------------
//Advanced Micro Devices
//AMD
//84.51
//Motorola Inc.
//MOT
//17.49
//Apple
//AAPL
//121.73
//Avdo Corporation
//AVDC
//999.34
//Intel
//INTC
//60.78
//NVIDIA
//NVDA
//548.58
//Sony
//SNE
//105.81
//Tesla
//TSLA
//564.33
//Light Incorporated
//LINC
//222.91
//Dark Holdings
//DHOL
//555.61
//Microsoft Corp.
//MSFT
//28.11
//
//after ascending selection sort
//---------------------------------
//Apple
//AAPL
//121.73
//Advanced Micro Devices
//AMD
//84.51
//Avdo Corporation
//AVDC
//999.34
//Dark Holdings
//DHOL
//555.61
//Intel
//INTC
//60.78
//Light Incorporated
//LINC
//222.91
//Motorola Inc.
//MOT
//17.49
//Microsoft Corp.
//MSFT
//28.11
//NVIDIA
//NVDA
//548.58
//Sony
//SNE
//105.81
//Tesla
//TSLA
//564.33
//
//after randomization:
//--------------------
//Light Incorporated
//LINC
//222.91
//Apple
//AAPL
//121.73
//Microsoft Corp.
//MSFT
//28.11
//NVIDIA
//NVDA
//548.58
//Dark Holdings
//DHOL
//555.61
//Motorola Inc.
//MOT
//17.49
//Intel
//INTC
//60.78
//Avdo Corporation
//AVDC
//999.34
//Sony
//SNE
//105.81
//Tesla
//TSLA
//564.33
//Advanced Micro Devices
//AMD
//84.51
//
//after descending selection sort
//----------------------------------
//Tesla
//TSLA
//564.33
//Sony
//SNE
//105.81
//NVIDIA
//NVDA
//548.58
//Microsoft Corp.
//MSFT
//28.11
//Motorola Inc.
//MOT
//17.49
//Light Incorporated
//LINC
//222.91
//Intel
//INTC
//60.78
//Dark Holdings
//DHOL
//555.61
//Avdo Corporation
//AVDC
//999.34
//Advanced Micro Devices
//AMD
//84.51
//Apple
//AAPL
//121.73
//
//after randomization
//--------------------
//Light Incorporated
//LINC
//222.91
//Tesla
//TSLA
//564.33
//Dark Holdings
//DHOL
//555.61
//Avdo Corporation
//AVDC
//999.34
//Microsoft Corp.
//MSFT
//28.11
//Intel
//INTC
//60.78
//Motorola Inc.
//MOT
//17.49
//NVIDIA
//NVDA
//548.58
//Advanced Micro Devices
//AMD
//84.51
//Apple
//AAPL
//121.73
//Sony
//SNE
//105.81
//
//after ascending quick sort
//----------------------------
//Apple
//AAPL
//121.73
//Advanced Micro Devices
//AMD
//84.51
//Avdo Corporation
//AVDC
//999.34
//Dark Holdings
//DHOL
//555.61
//Intel
//INTC
//60.78
//Light Incorporated
//LINC
//222.91
//Motorola Inc.
//MOT
//17.49
//Microsoft Corp.
//MSFT
//28.11
//NVIDIA
//NVDA
//548.58
//Sony
//SNE
//105.81
//Tesla
//TSLA
//564.33
//
//after randomization
//--------------------
//Light Incorporated
//LINC
//222.91
//Apple
//AAPL
//121.73
//Microsoft Corp.
//MSFT
//28.11
//NVIDIA
//NVDA
//548.58
//Dark Holdings
//DHOL
//555.61
//Motorola Inc.
//MOT
//17.49
//Intel
//INTC
//60.78
//Avdo Corporation
//AVDC
//999.34
//Sony
//SNE
//105.81
//Tesla
//TSLA
//564.33
//Advanced Micro Devices
//AMD
//84.51
//
//after descending quick sort
//----------------------------------
//Tesla
//TSLA
//564.33
//Sony
//SNE
//105.81
//NVIDIA
//NVDA
//548.58
//Microsoft Corp.
//MSFT
//28.11
//Motorola Inc.
//MOT
//17.49
//Light Incorporated
//LINC
//222.91
//Intel
//INTC
//60.78
//Dark Holdings
//DHOL
//555.61
//Avdo Corporation
//AVDC
//999.34
//Advanced Micro Devices
//AMD
//84.51
//Apple
//AAPL
//121.73
//
//after randomization
//--------------------
//Light Incorporated
//LINC
//222.91
//Tesla
//TSLA
//564.33
//Dark Holdings
//DHOL
//555.61
//Avdo Corporation
//AVDC
//999.34
//Microsoft Corp.
//MSFT
//28.11
//Intel
//INTC
//60.78
//Motorola Inc.
//MOT
//17.49
//NVIDIA
//NVDA
//548.58
//Advanced Micro Devices
//AMD
//84.51
//Apple
//AAPL
//121.73
//Sony
//SNE
//105.81
//
//after ascending heap sort
//----------------------------------
//Apple
//AAPL
//121.73
//Advanced Micro Devices
//AMD
//84.51
//Avdo Corporation
//AVDC
//999.34
//Dark Holdings
//DHOL
//555.61
//Intel
//INTC
//60.78
//Light Incorporated
//LINC
//222.91
//Motorola Inc.
//MOT
//17.49
//Microsoft Corp.
//MSFT
//28.11
//NVIDIA
//NVDA
//548.58
//Sony
//SNE
//105.81
//Tesla
//TSLA
//564.33
//
//after randomization
//--------------------
//Light Incorporated
//LINC
//222.91
//Apple
//AAPL
//121.73
//Microsoft Corp.
//MSFT
//28.11
//NVIDIA
//NVDA
//548.58
//Dark Holdings
//DHOL
//555.61
//Motorola Inc.
//MOT
//17.49
//Intel
//INTC
//60.78
//Avdo Corporation
//AVDC
//999.34
//Sony
//SNE
//105.81
//Tesla
//TSLA
//564.33
//Advanced Micro Devices
//AMD
//84.51
//
//after descending heap sort
//----------------------------------
//Tesla
//TSLA
//564.33
//Sony
//SNE
//105.81
//NVIDIA
//NVDA
//548.58
//Microsoft Corp.
//MSFT
//28.11
//Motorola Inc.
//MOT
//17.49
//Light Incorporated
//LINC
//222.91
//Intel
//INTC
//60.78
//Dark Holdings
//DHOL
//555.61
//Avdo Corporation
//AVDC
//999.34
//Advanced Micro Devices
//AMD
//84.51
//Apple
//AAPL
//121.73

