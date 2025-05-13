//*****************************************************************************************************
//
//		File:					driver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #6
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					October 9th, 2023
//		
//*****************************************************************************************************

#include "BinarySearchTree.h"
#include "Stock.h"
using namespace std;
#include <fstream>  
#include <stdlib.h>
#include <time.h>

//*****************************************************************************************************

int main()
{
    BinarySearchTree<int> intTree;
    srand(time(0));
    int temp;

    for (int i = 0; i < 10; i++)
    {
        temp = 1 + (rand() % 5000);
        intTree.insert(temp);
    }

    cout << "int tree inorder:" << endl;
    intTree.inorder();
    cout << endl;

    cout << "int tree preorder:" << endl;
    intTree.preorder();
    cout << endl;

    cout << "int tree postorder:" << endl;
    intTree.postorder();
    cout << endl;

    int intHeight = intTree.height();
    cout << "height of the int tree: " << intHeight << endl;

    intTree.destroy();

    cout << "inorder after destroy:" << endl;
    intTree.inorder();

    BinarySearchTree<Stock> stockTree;
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
                cout << "name of stock " << tempSymbol << " is " << searchPtr->getName() << endl;
            }
            else
            {
                cout << "could not find a stock with that symbol" << endl;
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
                cout << "price of stock " << tempSymbol << " is " << searchPtr->getPrice() << endl;
            }
            else
            {
                cout << "could not find a stock with that symbol" << endl;
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
            cout << "stock " << tempSymbol << " added" << endl << endl;
            stockTree.inorder();
            break;
        case 'd':
        case 'D':
            stockTree.inorder();
            break;
        case 'e':
        case 'E':
            stockTree.inorder(outputFile);
            outputFile.close();
            cout << "contents updated" << endl;
            break;
        default:
            cout << "invalid, please select one of the choices listed above" << endl;
            break;
    }

    return 0;
}

//*****************************************************************************************************

//*choice a test*
//int tree inorder:
//328
//1388
//1945
//2014
//2478
//3278
//3362
//4349
//4694
//4850
//
//int tree preorder:
//2014
//328
//1945
//1388
//2478
//4850
//3362
//3278
//4694
//4349
//
//int tree postorder:
//1388
//1945
//328
//3278
//4349
//4694
//3362
//4850
//2478
//2014
//
//height of the int tree: 6
//inorder after destroy:
//
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
//*choice b test*
//int tree inorder:
//187
//395
//847
//1236
//1455
//2226
//2723
//2941
//3729
//4938
//
//int tree preorder:
//2226
//847
//395
//187
//1236
//1455
//3729
//2723
//2941
//4938
//
//int tree postorder:
//187
//395
//1455
//1236
//847
//2941
//2723
//4938
//3729
//2226
//
//height of the int tree: 4
//inorder after destroy:
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
//*choice c test*
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: c
//enter name of the stock: Avdo Corporation
//enter symbol of the stock: AVD
//enter price of the stock: 96.4
//stock AVD added
//
//Apple | AAPL | 121.73
//Advanced Micro Devices | AMD | 84.51
//Avdo Corporation | AVD | 96.4
//Intel | INTC | 60.78
//Motorola Inc. | MOT | 17.49
//Microsoft Corp. | MSFT | 28.11
//NVIDIA | NVDA | 548.58
//Sony | SNE | 105.81
//Tesla | TSLA | 564.33
// 
//*choice d test*
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: d
//Apple | AAPL | 121.73
//Advanced Micro Devices | AMD | 84.51
//Intel | INTC | 60.78
//Motorola Inc. | MOT | 17.49
//Microsoft Corp. | MSFT | 28.11
//NVIDIA | NVDA | 548.58
//Sony | SNE | 105.81
//Tesla | TSLA | 564.33
//
//*choice e test*
//Stock.txt:
//Apple | AAPL | 121.73
//Advanced Micro Devices | AMD | 84.51
//Intel | INTC | 60.78
//Motorola Inc. | MOT | 17.49
//Microsoft Corp. | MSFT | 28.11
//NVIDIA | NVDA | 548.58
//Sony | SNE | 105.81
//Tesla | TSLA | 564.33
// 
//*default test*
//stock tree menu:
//a) display a stock's name given its symbol
//b) display a stock's price given its symbol
//c) insert a new stock
//d) display all stocks
//e) quit
//
//enter your choice: f
//invalid, please select one of the choices listed above