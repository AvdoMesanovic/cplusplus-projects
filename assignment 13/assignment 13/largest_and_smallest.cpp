// *************************************************
// 
//  Assignment:    #13
//  File:          largest_and_smallest.cpp
//
//  Due Date:      October 8, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program lets a user enter a series of numbers,
//				   then finds the largest and smallest numbers
//
// *************************************************

#include <iostream>
using namespace std;

int main()
{
	int number = 0,
		largest = 0,
		smallest = 0,
		count = 0;
	
	while (number != -99)
	{
		cout << "Enter a whole number (-99 to quit) \n";
		cin >> number;
		if (count == 0)
		{
			largest = number;
			smallest = number;
		}
		else
		{
			if (number > largest && number != -99)
			{
			largest = number;
			}
			else if (number < smallest && number != -99)
			{
				smallest = number;
			}
		}
		count++;
	}

	cout << "The largest number is " << largest << endl;
	cout << "The smallest number is " << smallest << endl;

	return 0;
}

/*
	Enter a whole number (-99 to quit)
	1
	Enter a whole number (-99 to quit)
	2
	Enter a whole number (-99 to quit)
	3
	Enter a whole number (-99 to quit)
	4
	Enter a whole number (-99 to quit)
	5
	Enter a whole number (-99 to quit)
	6
	Enter a whole number (-99 to quit)
	-99
	The largest number is 6
	The smallest number is 1

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 13\Debug\assignment 13.exe (process 11724) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Enter a whole number (-99 to quit)
	2
	Enter a whole number (-99 to quit)
	9
	Enter a whole number (-99 to quit)
	8
	Enter a whole number (-99 to quit)
	7
	Enter a whole number (-99 to quit)
	4
	Enter a whole number (-99 to quit)
	-99
	The largest number is 9
	The smallest number is 2

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 13\Debug\assignment 13.exe (process 6692) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	Enter a whole number (-99 to quit)
	100
	Enter a whole number (-99 to quit)
	99
	Enter a whole number (-99 to quit)
	98
	Enter a whole number (-99 to quit)
	97
	Enter a whole number (-99 to quit)
	96
	Enter a whole number (-99 to quit)
	-99
	The largest number is 100
	The smallest number is 96

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 13\Debug\assignment 13.exe (process 628) exited with code 0.
	Press any key to close this window . . .
*/