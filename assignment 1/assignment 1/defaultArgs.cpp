//*****************************************************************************************************
//
//		File:					defaultArgs.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #1
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					January 30th, 2023
//
//
//		This program uses default arguments to call a single function in various different
//		ways to display a message.
//	
//		Other files required:
//		None
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

void displayMsg(const char message[51] = "Decide. Commit. Succeed.", char symbol = ' ', 
				int length = 10);

//*****************************************************************************************************

int main()
{
	displayMsg("I will decide.", '*', 15);
	displayMsg("I will commit.", '+');
	displayMsg("I will succeed.");

	displayMsg();

	return 0;
}

//*****************************************************************************************************

void displayMsg(const char message[51], char symbol, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << symbol;
	}

	cout << message;

	for (int i = 0; i < length; i++)
	{
		cout << symbol;
	}

	cout << endl;
}

//*****************************************************************************************************

//***************I will decide.***************
//++++++++++I will commit.++++++++++
//          I will succeed.
//          Decide. Commit. Succeed.
// 
//C:\Users\avdom\OneDrive\Documents\source\repos\data structures 1\assignment 1\x64\Debug\
//assignment 1.exe (process 11088) exited with code 0.
//Press any key to close this window . . .


