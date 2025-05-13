// *************************************************
// 
//  Assignment:    #16
//  File:          occupancy_rate.cpp
//
//  Due Date:      November 8, 2021 
//
//  Author:        Avdo Mesanovic 
//
//  Course Name:   Programming I 
//
//  Course Number: COSC 1550 
//
//  Description:   This program calculates the occupancy rate for a hotel
//
// *************************************************

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numberOfFloors,
		floorNumber,
		rooms,
		occupiedRooms,
		totalOccupied = 0,
		totalUnoccupied = 0,
		totalRooms = 0;

	double occupanyRate;

	cout << "How many floors does the hotel have? \n";
	cin >> numberOfFloors;

	while (numberOfFloors < 1)
	{
		cout << "Please enter a number greater than 0 \n";
		cin >> numberOfFloors;
	}
	for (int count = 0; count < numberOfFloors; count++)
	{
		floorNumber = count + 1;
		cout << "How many rooms are in floor " << floorNumber << "?" << endl;
		cin >> rooms;
		totalRooms += rooms;
		cout << "How many of those rooms are occupied? \n";
		cin >> occupiedRooms;
		totalOccupied += occupiedRooms;
	}

	cout << "The hotel has a total of " << totalRooms << " rooms" << endl;
	cout << totalOccupied << " are occupied" << endl;
	totalUnoccupied = totalRooms - totalOccupied;
	cout << totalUnoccupied << " are unoccupied" << endl;
	cout << fixed << showpoint << setprecision(1);
	occupanyRate = static_cast<double> (totalOccupied) / totalRooms * 100;
	cout << "The occupany rate is " << occupanyRate << "%" << endl;

	return 0;
}

/*
	How many floors does the hotel have?
	3
	How many rooms are in floor 1?
	10
	How many of those rooms are occupied?
	5
	How many rooms are in floor 2?
	10
	How many of those rooms are occupied?
	5
	How many rooms are in floor 3?
	10
	How many of those rooms are occupied?
	5
	The hotel has a total of 30 rooms
	15 are occupied
	15 are unoccupied
	The occupany rate is 50.0%

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 16\Debug\assignment 16.exe (process 14332) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	How many floors does the hotel have?
	5
	How many rooms are in floor 1?
	10
	How many of those rooms are occupied?
	5
	How many rooms are in floor 2?
	20
	How many of those rooms are occupied?
	10
	How many rooms are in floor 3?
	30
	How many of those rooms are occupied?
	15
	How many rooms are in floor 4?
	40
	How many of those rooms are occupied?
	20
	How many rooms are in floor 5?
	50
	How many of those rooms are occupied?
	25
	The hotel has a total of 150 rooms
	75 are occupied
	75 are unoccupied
	The occupany rate is 50.0%

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 16\Debug\assignment 16.exe (process 12548) exited with code 0.
	Press any key to close this window . . .
----------------------------------------------------------------------------------------------------------------------------
	How many floors does the hotel have?
	-1
	Please enter a number greater than 0
	3
	How many rooms are in floor 1?
	8
	How many of those rooms are occupied?
	3
	How many rooms are in floor 2?
	6
	How many of those rooms are occupied?
	1
	How many rooms are in floor 3?
	6
	How many of those rooms are occupied?
	5
	The hotel has a total of 20 rooms
	9 are occupied
	11 are unoccupied
	The occupany rate is 45.0%

	C:\Users\avdom\OneDrive\Documents\source\repos\assignment 16\Debug\assignment 16.exe (process 2820) exited with code 0.
	Press any key to close this window . . .
*/