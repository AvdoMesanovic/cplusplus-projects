//*****************************************************************************************************
//
//		File:					max.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #2
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					February 3rd, 2023
//
//
//		This program uses function templates and overloaded functions to determine
//		the maximum of two entries.
//	
//		Other files required:
//		None
//			
//*****************************************************************************************************

#include <iostream>
#include <typeinfo>
using namespace std;

//*****************************************************************************************************

template <typename TYPE>
void getData(TYPE& val1, TYPE& val2);
void getData(char str1[], char str2[]);

template <typename TYPE>
TYPE findMax(TYPE aVal, TYPE bVal);
char* findMax(char str1[], char str2[]);

template <typename TYPE>
void displayMax(TYPE aVal, TYPE bVal, TYPE maxVal);

//*****************************************************************************************************

int main()
{
	int aInt,
		bInt,
		maxInt;

	double aDouble,
		   bDouble,
		   maxDouble;

	char aChar,
		 bChar,
		 maxChar;

	char aArray[81];
	char bArray[81];
	char* maxArray;

	getData(aInt, bInt);
	getData(aDouble, bDouble);
	getData(aChar, bChar);
	getData(aArray, bArray);

	maxInt = findMax(aInt, bInt);
	maxDouble = findMax(aDouble, bDouble);
	maxChar = findMax(aChar, bChar);
	maxArray = findMax(aArray, bArray);

	displayMax(aInt, bInt, maxInt);
	displayMax(aDouble, bDouble, maxDouble);
	displayMax(aChar, bChar, maxChar);
	displayMax(aArray, bArray, maxArray);

	return 0;
}

//*****************************************************************************************************

template <typename TYPE>
void getData(TYPE& val1, TYPE& val2)
{
	cout << "Enter 2 " << typeid(val1).name() << "s:" << endl;
	cin >> val1;
	cin >> val2;

	cout << endl;
}

//*****************************************************************************************************

void getData(char str1[], char str2[])
{
	cin.ignore();

	cout << "Enter 2 char strings:" << endl;
	cin.getline(str1, 81);
	cin.getline(str2, 81);

	cout << endl;
}

//*****************************************************************************************************

template <typename TYPE>
TYPE findMax(TYPE aVal, TYPE bVal)
{
	TYPE result = aVal;

	if (aVal < bVal)
	{
		result = bVal;
	}

	return result;
}

//*****************************************************************************************************

char* findMax(char str1[], char str2[])
{
	char* result = str1;

	if (strcmp(str1, str2) < 0)
	{
		result = str2;
	}

	return result;
}

//*****************************************************************************************************

template <typename TYPE>
void displayMax(TYPE aVal, TYPE bVal, TYPE maxVal)
{
	cout  << "The maximum value between " << aVal << " and " << bVal << " is: " << maxVal << endl;
}

//*****************************************************************************************************

//Enter 2 ints:
//75
//6
//
//Enter 2 doubles:
//89.36
//123.4
//
//Enter 2 chars:
//z
//a
//
//Enter 2 char strings:
//apple pie
//apple dumpling
//
//The maximum value between 75 and 6 is: 75
//The maximum value between 89.36 and 123.4 is: 123.4
//The maximum value between z and a is: z
//The maximum value between apple pie and apple dumpling is: apple pie
//
//C:\Users\avdom\OneDrive\Documents\source\repos\data structures 1\assignment 2\x64\Debug\assignment 2.exe (process 6976) exited with code 0.
//Press any key to close this window . . .


