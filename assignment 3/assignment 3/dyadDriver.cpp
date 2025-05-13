//*****************************************************************************************************
//
//		File:					dyadDriver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #3
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					February 13th, 2023
//
//
//		This program uses a class template to hold two values of different data types. 
//	
//		Other files required: 
//			1.	dyad.h - definition of the Dyad class
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "dyad.h"

//*****************************************************************************************************

int main()
{
	int int1 = 5,
		int2 = 10;

	double double1 = 7.5,
		   double2 = 12.3;

	char char1 = 'z',
		 char2 = 'a';

	Dyad<int> intDyad(int1, int2);
	Dyad<double> doubleDyad(double1, double2);
	Dyad<char> charDyad(char1, char2);

	cout << "int dyad \n" << "---------------" << endl;
	cout << "values: " << intDyad.getFirst() << ", " << intDyad.getSecond() << endl;
	intDyad.swapValues();
	intDyad.get2Values(int1, int2);
	cout << "swapped: " << int1 << ", " << int2 << endl;

	cout << endl;

	cout << "double dyad \n" << "---------------" << endl;
	cout << "values: " << doubleDyad.getFirst() << ", " << doubleDyad.getSecond() << endl;
	doubleDyad.swapValues();
	doubleDyad.get2Values(double1, double2);
	cout << "swapped: " << double1 << ", " << double2 << endl;

	cout << endl;

	cout << "char dyad \n" << "---------------" << endl;
	cout << "values: " << charDyad.getFirst() << ", " << charDyad.getSecond() << endl;
	charDyad.swapValues();
	charDyad.get2Values(char1, char2);
	cout << "swapped: " << char1 << ", " << char2 << endl;

	return 0;
}

//*****************************************************************************************************

//int dyad
//---------------
//values: 5, 10
//swapped: 10, 5
//
//double dyad
//---------------
//values: 7.5, 12.3
//swapped: 12.3, 7.5
//
//char dyad
//---------------
//values: z, a
//swapped: a, z
//
//C:\Users\avdom\OneDrive\Documents\source\repos\data structures 1\assignment 3\x64\Debug\assignment 3.exe (process 3060) exited with code 0.
//Press any key to close this window . . .


