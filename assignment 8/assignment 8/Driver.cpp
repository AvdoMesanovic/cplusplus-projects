//*****************************************************************************************************
//
//		File:					Driver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #8
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 6th, 2023
//		
//*****************************************************************************************************

#include "AVLTree.h"
#include "Stock.h"
using namespace std;
#include <fstream>  

//*****************************************************************************************************

int main()
{
    AVLTree<Stock> stockTree;
    char choice;
    Stock tempStock;
    string tempName,
        tempSymbol;
    double tempPrice;
    Stock* searchPtr;

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
            stockTree.insert(tempStock);
        }

        inputFile.close();
    }
    else
    {
        cout << "failed to open file" << endl;
    }

    ofstream outputFile("Stock.txt");
    
    do
    {
        cout << "stock tree menu:" << endl;
        cout << "a) display a stock's name given its symbol" << endl;
        cout << "b) display a stock's price given its symbol" << endl;
        cout << "c) insert a new stock" << endl;
        cout << "d) display all stocks" << endl;
        cout << "e) quit" << endl << endl;

        cout << "enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
        case 'A':
            cout << "please enter the symbol of the stock: ";
            cin >> tempSymbol;
            tempStock = Stock("", tempSymbol, 0);
            searchPtr = stockTree.search(tempStock);

            if (searchPtr != nullptr)
            {
                cout << "name of stock " << tempSymbol << " is " << searchPtr->getName() << endl << endl;
            }
            else
            {
                cout << "could not find a stock with that symbol" << endl << endl;
            }

            break;
        case 'b':
        case 'B':
            cout << "please enter the symbol of the stock: ";
            cin >> tempSymbol;

            tempStock = Stock("", tempSymbol, 0);
            searchPtr = stockTree.search(tempStock);

            if (searchPtr != nullptr)
            {
                cout << "price of stock " << tempSymbol << " is " << searchPtr->getPrice() << endl << endl;
            }
            else
            {
                cout << "could not find a stock with that symbol" << endl << endl;
            }

            break;
        case 'c':
        case 'C':
            cin.ignore();
            cout << "enter name of the stock: ";
            getline(cin, tempName);
            cout << "enter symbol of the stock: ";
            cin >> tempSymbol;
            cout << "enter price of the stock: ";
            cin >> tempPrice;
            tempStock = Stock(tempName, tempSymbol, tempPrice);
            stockTree.insert(tempStock);
            cout << "stock " << tempSymbol << " successfully added" << endl << endl;
            break;
        case 'd':
        case 'D':
            stockTree.inorder();
            cout << endl;
            break;
        case 'e':
        case 'E':
            stockTree.inorderWrite(outputFile);
            outputFile.close();
            cout << "quitting and updating contents..." << endl;
            break;
        default:
            cout << "invalid, please select one of the choices listed above" << endl << endl;
            break;
        }
    } while (choice != 'e' && choice != 'E');

    return 0;
}

//*****************************************************************************************************

//success testing
//------------------------------------------------
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: a
//please enter the symbol of the stock: SNE
//name of stock SNE is Sony
//
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: b
//please enter the symbol of the stock: SNE
//price of stock SNE is 105.81
//
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: c
//enter name of the stock: Avdo Corporation
//enter symbol of the stock: AVDC
//enter price of the stock: 222.56
//stock AVDC successfully added
//
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: d
//(balance factor is 0)
//Apple
//AAPL
//121.73
//(balance factor is 0)
//Advanced Micro Devices
//AMD
//84.51
//(balance factor is 0)
//Avdo Corporation
//AVDC
//222.56
//(balance factor is -1)
//Intel
//INTC
//60.78
//(balance factor is 0)
//Motorola Inc.
//MOT
//17.49
//(balance factor is -1)
//Microsoft Corp.
//MSFT
//28.11
//(balance factor is 0)
//NVIDIA
//NVDA
//548.58
//(balance factor is 0)
//Sony
//SNE
//105.81
//(balance factor is 0)
//Tesla
//TSLA
//564.33
//
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: e
//quitting and updating contents...

//fail testing
//------------------------------------------------
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: x
//invalid, please select one of the choices listed above
//
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: a
//please enter the symbol of the stock: QWERTY
//could not find a stock with that symbol
//
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: b
//please enter the symbol of the stock: QWERTY
//could not find a stock with that symbol
//
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: e
//quitting and updating contents...