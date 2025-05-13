//*****************************************************************************************************
//
//		File:					pal.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					April 27th, 2023
//
//
//		This program uses a templated Stack and a templated Queue to determine if a character array
//      string is a valid palindrome.
//	
//		Other files required: 
//			1. stack.h - definition of the Stack class
//          2. queue.h - definition of the Queue class
//			3. palindromes.txt - contains character array strings used for input
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
#include "stack.h"
#include "queue.h"

//*****************************************************************************************************

bool testNdisplayPal(Stack<char>& palStack, Queue<char>& palQueue);
char getPalType(bool hasPunct, bool hasSpace);
void displayPalResult(bool isPal, char palType);

//*****************************************************************************************************

int main()
{
    Stack<char> palStack;
    Queue<char> palQueue;

    bool hasPunct;
    bool hasSpace;
    bool isPal;
    int len;
    char palType;
    char pal[81];
    ifstream palFile("palindromes.txt");

    while (palFile.getline(pal, 80, '#'))
    {
        len = int(strlen(pal));
        hasPunct = false;
        hasSpace = false;

        for (int i = 0; i < len; i++)
        {
            if (isalpha(pal[i]))
            {
                pal[i] = tolower(pal[i]);
                palStack.push(pal[i]);
                palQueue.enqueue(pal[i]);
            }
            else if (ispunct(pal[i]))
            {
                hasPunct = true;
            }
            else if (isspace(pal[i]))
            {
                hasSpace = true;
            }
        }

        isPal = testNdisplayPal(palStack, palQueue);
        palType = getPalType(hasPunct, hasSpace);
        displayPalResult(isPal, palType);
    }

    palFile.close();

    return 0;
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char>& palStack, Queue<char>& palQueue)
{
    char temp1,
         temp2;
    bool isPal = true;

    while (palStack.pop(temp1) && palQueue.dequeue(temp2))
    {
        if (temp1 != temp2)
        {
            isPal = false;
        }

        cout << temp1;
    }

    return isPal;
}

//*****************************************************************************************************

char getPalType(bool hasPunct, bool hasSpace)
{
    char palType = '1';

    if (hasPunct)
    {
        palType = '3';
    }
    else if (hasSpace)
    {
        palType = '2';
    }

    return palType;
}

//*****************************************************************************************************

void displayPalResult(bool isPal, char palType)
{
    if (isPal)
    {
        cout << "\t\t" << "type " << palType << endl;
    }
    else
    {
        cout << "\t\t" << "invalid" << endl;
    }
}

//*****************************************************************************************************
//aha             type 3
//isitiitisi              type 3
//deed            type 1
//srotor          invalid
//neveroddoreven          type 2
//nolemonsnomelon         type 3
//racecar         type 2
//cimoc           invalid
//wasitacaroracatisaw             type 3
//yddad           invalid

