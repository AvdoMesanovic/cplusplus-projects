// *************************************************
// 
//  Assignment:    #3
//  File:          size_of.cpp
//
//  Due Date:      September 10, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program displays the memory bytes  
//				   for char, int, and double
//
// *************************************************

#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int number = 5;
	cout << "The size of an int is " << sizeof(number) << " bytes." << endl;

	char letter;
	cout << "The size of a char is " << sizeof(letter) << " bytes." << endl;

	cout << "The size of a double is " << sizeof(double) << " bytes." << endl;

	return 0;
}

/*
	The size of an int is 4 bytes.
	The size of a char is 1 bytes.
	The size of a double is 8 bytes.

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 3\Debug\assignment 3.exe (process 13600) exited with code 0.
	Press any key to close this window . . .
*/