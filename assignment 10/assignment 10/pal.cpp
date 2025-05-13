//*****************************************************************************************************
//
//		File:					pal.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #10
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					April 19th, 2023
//
//
//		This program uses a templated Stack to reverse a character array string.
//	
//		Other files required: 
//			1. stack.h - definition of the Stack class
//			2. palindromes.txt - contains character array strings used for input
//			
//*****************************************************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

void fillStack3(Stack<char>& s2, Stack<char>& s3);
bool testNdisplayPal(Stack<char>& s1, Stack<char>& s3);
char getPalType(bool hasPunct, bool hasSpace);
void displayPalResult(bool isPal, char palType);

//*****************************************************************************************************

int main()
{
    Stack<char> palStack1;
    Stack<char> palStack2;
    Stack<char> palStack3;

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
                palStack1.push(pal[i]);
                palStack2.push(pal[i]);
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

        fillStack3(palStack2, palStack3);
        isPal = testNdisplayPal(palStack1, palStack3);
        palType = getPalType(hasPunct, hasSpace);
        displayPalResult(isPal, palType);
    }

    palFile.close();

    return 0;
}

//*****************************************************************************************************

void fillStack3(Stack<char>& s2, Stack<char>& s3)
{
    char temp;

    while (s2.pop(temp))
    {
        s3.push(temp);
    }
}

//*****************************************************************************************************

bool testNdisplayPal(Stack<char>& s1, Stack<char>& s3)
{
    char temp1,
         temp3;
    bool isPal = true;

    while (s1.pop(temp1) && s3.pop(temp3))
    {
        if (temp1 != temp3)
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
