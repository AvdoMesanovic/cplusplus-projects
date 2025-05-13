// *************************************************
// 
//  Assignment:    #5
//  File:          room_on_floor.cpp
//
//  Due Date:      September 10, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program determines where a
//				   room is on a certain floor
//
// *************************************************

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter a 3 or 4 digit number and I can tell you your floor number and room number" << endl;

	int number;
	cout << "Enter a number: " << endl;
	cin >> number;

	int floor, room;

	floor = number / 100;
	cout << "Your floor is: " << floor << endl;

	room = number % 100;
	cout << "Your room is: " << room << endl;

	return 0;
}

/*
	Enter a 3 or 4 digit number and I can tell you your floor number and room number
	Enter a number:
	312
	Your floor is: 3
	Your room is: 12

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 5\Debug\assignment 5.exe (process 9820) exited with code 0.
	Press any key to close this window . . .
-------------------------------------------------------------------------------------------------------------------------
	Enter a 3 or 4 digit number and I can tell you your floor number and room number
	Enter a number:
	1282
	Your floor is: 12
	Your room is: 82

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 5\Debug\assignment 5.exe (process 6028) exited with code 0.
	Press any key to close this window . . .
-------------------------------------------------------------------------------------------------------------------------
	Enter a 3 or 4 digit number and I can tell you your floor number and room number
	Enter a number:
	4021
	Your floor is: 40
	Your room is: 21

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 5\Debug\assignment 5.exe (process 1076) exited with code 0.
	Press any key to close this window . . .
*/