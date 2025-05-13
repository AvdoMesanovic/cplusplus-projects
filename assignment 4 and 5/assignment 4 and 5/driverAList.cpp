//*****************************************************************************************************
//
//		File:					driverAList.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #5
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					March 2nd, 2023
//
//
//		This program explores the List ADT and utilizes several functions to employ it.
//	
//		Other files required:
//			1. Alist.h - definition of the AList class
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "AList.h"

//*****************************************************************************************************

int main()
{
	short min,
		  removed,
		  removed1 = 5,
		  retrieved,
		  retrieved1 = 7,
		  updated = 3;

	AList<short> shortList(3);

	if (shortList.insertFront(3))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 3";
	}

	cout << endl;

	if (shortList.insertAtIndex(5, 1))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 5 at index 1";
	}

	cout << endl;

	if (shortList.insertBack(7))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 7";
	}

	cout << endl;

	if (shortList.insertFront(1))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 1";
	}

	cout << endl;

	if (shortList.insertAtIndex(12, 2))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 12 at index 2";
	}

	cout << endl;
	
	if (shortList.insertAtIndex(4, 10))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 4 at index 10" << endl;
	}

	cout << endl;

	if (shortList.insertBack(8))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 8";
	}

	cout << endl;

	if (shortList.isEmpty())
	{
		cout << "list is empty" << endl;
	}
	else
	{
		cout << "list is not empty" << endl;
	}

	if (shortList.isFull())
	{
		cout << "list is full" << endl;
	}
	else
	{
		cout << "list is not full" << endl;
	}

	cout << endl;

	if (shortList.removeFront(removed))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t removed value is " << removed << endl;
	}
	else
	{
		cout << "unable to remove the first value" << endl;
	}

	cout << endl;

	if (shortList.removeBack(removed))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t removed value is " << removed << endl;
	}
	else
	{
		cout << "unable to remove the last value" << endl;
	}

	cout << endl;

	if (shortList.removeAtIndex(removed, 7))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t removed value is " << removed << endl;
	}
	else
	{
		cout << "unable to remove that value as it does not exist" << endl;
	}

	cout << endl;

	if (shortList.removeAtIndex(removed, 1))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t removed value is " << removed << endl;
	}
	else
	{
		cout << "unable to remove that value as it does not exist" << endl;
	}

	cout << endl;

	if (shortList.remove(removed1))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t removed value is " << removed1 << endl;
	}
	else
	{
		cout << "unable to remove the value 5" << endl;
	}

	cout << endl;

	if (shortList.insertFront(3))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 3";
	}

	cout << endl;

	if (shortList.insertAtIndex(5, 1))
	{
		shortList.display();
		shortList.getSmallest(min);
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t smallest value is " << min << endl;
	}
	else
	{
		cout << "unable to insert the value 5 at index 1";
	}

	cout << endl;

	if (shortList.retrieveFront(retrieved))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t retrieved value is " << retrieved << endl;
	}
	else
	{
		cout << "unable to retrieve the first value" << endl;
	}

	cout << endl;

	if (shortList.retrieveBack(retrieved))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t retrieved value is " << retrieved << endl;
	}
	else
	{
		cout << "unable to retrieve the last value" << endl;
	}

	cout << endl;

	if (shortList.retrieveAtIndex(retrieved, 7))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t retrieved value is " << retrieved << endl;
	}
	else
	{
		cout << "unable to retrieve that value as it does not exist" << endl;
	}

	cout << endl;

	if (shortList.retrieveAtIndex(retrieved, 1))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t retrieved value is " << retrieved << endl;
	}
	else
	{
		cout << "unable to retrieve that value as it does not exist" << endl;
	}

	cout << endl;

	if (shortList.retrieve(retrieved1))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t retrieved value is " << retrieved1 << endl;
	}
	else
	{
		cout << "unable to retrieve the value 7" << endl;
	}

	cout << endl;

	if (shortList.updateFront(20))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t updated value is 20" << endl;
	}
	else
	{
		cout << "unable to update the first value" << endl;
	}

	cout << endl;

	if (shortList.updateBack(14))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t updated value is 14" << endl;
	}
	else
	{
		cout << "unable to update the last value" << endl;
	}

	cout << endl;

	if (shortList.updateAtIndex(12, 7))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t updated value is 12" << endl;
	}
	else
	{
		cout << "unable to update that value as it does not exist" << endl;
	}

	cout << endl;

	if (shortList.updateAtIndex(12, 1))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t updated value is 12" << endl;
	}
	else
	{
		cout << "unable to update that value as it does not exist" << endl;
	}

	cout << endl;

	if (shortList.update(updated))
	{
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << "\t updated value is " << updated << endl;
	}
	else
	{
		cout << "unable to update the value 3" << endl;
	}

	cout << endl;

	if (shortList.clear())
	{
		cout << "list has been clear, no values to display:" << endl;
		shortList.display();
		cout << endl << "capacity is " << shortList.getCapacity() << "\t numValues is "
			<< shortList.getNumValues() << endl;
	}
	else
	{
		cout << "unable to clear the list" << endl;
	}

	return 0;
}

//*****************************************************************************************************

//[0]3
//capacity is 3    numValues is 1  smallest value is 3
//
//[0]3    [1]5
//capacity is 3    numValues is 2  smallest value is 3
//
//[0]3    [1]5    [2]7
//capacity is 3    numValues is 3  smallest value is 3
//
//[0]1    [1]3    [2]5    [3]7
//capacity is 4    numValues is 4  smallest value is 1
//
//[0]1    [1]3    [2]12   [3]5    [4]7
//capacity is 6    numValues is 5  smallest value is 1
//
//unable to insert the value 4 at index 10
//
//[0]1    [1]3    [2]12   [3]5    [4]7    [5]8
//capacity is 6    numValues is 6  smallest value is 1
//
//list is not empty
//list is full
//
//[0]3    [1]12   [2]5    [3]7    [4]8
//capacity is 6    numValues is 5  removed value is 1
//
//[0]3    [1]12   [2]5    [3]7
//capacity is 6    numValues is 4  removed value is 8
//
//unable to remove that value as it does not exist
//
//[0]3    [1]5    [2]7
//capacity is 6    numValues is 3  removed value is 12
//
//[0]3    [1]7
//capacity is 6    numValues is 2  removed value is 5
//
//[0]3    [1]3    [2]7
//capacity is 6    numValues is 3  smallest value is 3
//
//[0]3    [1]5    [2]3    [3]7
//capacity is 6    numValues is 4  smallest value is 3
//
//[0]3    [1]5    [2]3    [3]7
//capacity is 6    numValues is 4  retrieved value is 3
//
//[0]3    [1]5    [2]3    [3]7
//capacity is 6    numValues is 4  retrieved value is 7
//
//unable to retrieve that value as it does not exist
//
//[0]3    [1]5    [2]3    [3]7
//capacity is 6    numValues is 4  retrieved value is 5
//
//[0]3    [1]5    [2]3    [3]7
//capacity is 6    numValues is 4  retrieved value is 7
//
//[0]20   [1]5    [2]3    [3]7
//capacity is 6    numValues is 4  updated value is 20
//
//[0]20   [1]5    [2]3    [3]14
//capacity is 6    numValues is 4  updated value is 14
//
//unable to update that value as it does not exist
//
//[0]20   [1]12   [2]3    [3]14
//capacity is 6    numValues is 4  updated value is 12
//
//[0]20   [1]12   [2]3    [3]14
//capacity is 6    numValues is 4  updated value is 3
//
//list has been clear, no values to display:
//
//capacity is 6    numValues is 0
//
//C:\Users\avdom\OneDrive\Documents\source\repos\data structures 1\assignment 4 and 5\x64\Debug\assignment 4 and 5.exe (process 9988) exited with code 0.
//Press any key to close this window . . .