//*****************************************************************************************************
//
//		File:					Driver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #9
//
//		Course Name:			Data Structures II
//
//		Course Number:			COSC 3100-01
//
//		Due:					November 13th, 2023
//		
//*****************************************************************************************************

#include "Node.h"
#include "Stock.h"
using namespace std;
#include <fstream>  

//*****************************************************************************************************

int readStocks(const string& fileName, Stock*& stocks, double*& freqs);
Node<Stock>* createHuffmanTree(Stock stocks[], double freqs[], int size);
void printArray(int path[], int pathLen, Node<char>* leaf);
void printPaths(Node<Stock>* r, int path[], int pathLen, int lr);
void displayStockList(Node<Stock>* rootPtr, const string& sentence);

//*****************************************************************************************************

int main()
{
    Stock* stocks;
    double* freqs;
    int size = readStocks("HuffmanStocks.txt", stocks, freqs);
    Node<Stock>* root = createHuffmanTree(stocks, freqs, size);

    int path[10];
    int pathLen = 0;

    cout << "huffman stock tree paths" << endl;
    printPaths(root, path, pathLen, -1);

    string sentence = "010011001";
    cout << "\nstocks in sentence:" << endl;
    displayStockList(root, sentence);

    delete[] stocks;
    delete[] freqs;

    return 0;
}

//*****************************************************************************************************

int readStocks(const string& fileName, Stock*& stocks, double*& freqs)
{
    int size = 0;
    ifstream inputFile(fileName);

    if (inputFile.is_open())
    {
        Stock tempStock;
        string tempName,
               tempSymbol;
        double tempPrice,
               tempFreq;

        inputFile >> size;
        stocks = new Stock[size];
        freqs = new double[size];
        int i = 0;

        while ((getline(inputFile, tempName)) && (getline(inputFile, tempSymbol) && (inputFile >> tempPrice)) && (inputFile >> tempFreq))
        {
            inputFile.ignore();
            tempStock = Stock(tempName, tempSymbol, tempPrice);
            stocks[i] = tempStock;
            freqs[i] = tempFreq;
            i++;
        }

        inputFile.close();
    }
    else
    {
        cout << "failed to open file" << endl;
    }

    return size;
}

//*****************************************************************************************************

Node<Stock>* createHuffmanTree(Stock stocks[], double freqs[], int size)
{
    Node<Stock>** elements = new Node<Stock>*[size];

    for (int i = 0; i < size; ++i)
    {
        elements[i] = new Node<Stock>;
        elements[i]->value = stocks[i];
        elements[i]->frequency = freqs[i];
        elements[i]->left = nullptr;
        elements[i]->right = nullptr;
    }

    int index1;
    int index2;
    double freq1;
    double freq2;

    while (size > 1) 
    {
        index1 = index2 = 0;
        freq1 = freq2 = numeric_limits<double>::max();
        
        for (int i = 0; i < size; ++i) 
        {
            if (elements[i]->frequency < freq1) 
            {
                freq2 = freq1;
                index2 = index1;
                freq1 = elements[i]->frequency;
                index1 = i;
            }
            else if ((elements[i]->frequency < freq2) && (i != index1)) 
            {
                freq2 = elements[i]->frequency;
                index2 = i;
            }
        }

        Node<Stock>* newNode;
        newNode = new Node<Stock>;
        newNode->left = elements[index1];
        newNode->right = elements[index2];
        newNode->frequency = freq1 + freq2;
        elements[min(index1, index2)] = newNode;

        for (int i = max(index1, index2); i < size - 1; ++i) 
        {
            elements[i] = elements[i + 1];
        }

        --size;
    }

    return elements[0];
}

//*****************************************************************************************************

void printArray(int path[], int pathLen, Node<Stock>* leaf)
{
    cout << leaf->value << " ";
    
    for (int i = 0; i < pathLen; i++) 
    {
        cout << path[i] << " ";
    }

    cout << endl;
}

//*****************************************************************************************************

void printPaths(Node<Stock>* node, int path[], int pathLen, int lr)
{
    if (node != nullptr) 
    {
        if (lr != -1) 
        {
            path[pathLen] = lr;
            ++pathLen;
        }
        if ((node->left == nullptr) && (node->right == nullptr)) 
        {
            printArray(path, pathLen, node);
        }
        else 
        {
            printPaths(node->left, path, pathLen, 0);
            printPaths(node->right, path, pathLen, 1);
        }
    }
}

//*****************************************************************************************************

void displayStockList(Node<Stock>* rootPtr, const string& sentence)
{
    Node<Stock>* current = rootPtr;

    for (char direction : sentence)
    {
        if (direction == '0')
        {
            current = current->left;
        }
        else if (direction == '1')
        {
            current = current->right;
        }
        else if (current == nullptr)
        {
            cerr << "sentence is empty" << endl;
            return;
        }

        if (current->left == nullptr && current->right == nullptr)
        {
            cout << "stock - " << current->value.getName() << endl;
            current = rootPtr;
        }
    }
}

//*****************************************************************************************************

//huffman stock tree paths
//
//
//0 0 0 0 0 0 0 0 0 0
//
//
//0 0 0 0 0 0 0 0 0 1
//
//
//0 0 0 0 0 0 0 0 1
//
//
//0 0 0 0 0 0 0 1
//
//
//0 0 0 0 0 0 1
//
//
//0 0 0 0 0 1
//
//
//0 0 0 0 1
//
//
//0 0 0 1
//
//
//0 0 1
//
//
//0 1
//
//stocks in sentence:
//stock -
//stock -
//stock -
//stock -