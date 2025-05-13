//*****************************************************************************************************
//
//		File:					driverLList.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #6
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					March 24th, 2023
//
//
//		This program explores the Linked List data structure and utilizes several functions 
//      to employ it.
//	
//		Other files required: 
//			1.	LList.h - definition of the LList class
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "LList.h"

//*****************************************************************************************************

int main()
{
	int retrieveFront,
		retrieveLast,
		retrieve7 = 7,
		retrieve0 = 0,
		retrieve22 = 22,
		retrieve8 = 8;

	int remove1 = 1,
		remove21 = 21,
		remove7 = 7,
		remove0 = 0,
		remove22 = 22,
		remove8 = 8;

	LList<int> intList;

	cout << "empty list tests" << endl;
	cout << "--------------------" << endl;

	if (intList.viewFront(retrieveFront))
	{
		cout << "the front value is " << retrieveFront << endl;
	}
	else
	{
		cout << "unable to retrieve the front value" << endl;
	}

	if (intList.viewRear(retrieveLast))
	{
		cout << "the last value is " << retrieveLast;
		cout << endl;
	}
	else
	{
		cout << "unable to retrieve the last value" << endl;
	}

	if (intList.retrieve(retrieve7))
	{
		cout << retrieve7 << endl;
	}
	else
	{
		cout << "unable to retrieve the value 7" << endl;
	}

	if (intList.remove(remove1))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to remove the value 1" << endl;
	}

	if (intList.isEmpty())
	{
		cout << "list is empty" << endl;
	}
	else
	{
		cout << "list is not empty" << endl;
	}

	if (intList.isFull())
	{
		cout << "list is full" << endl;
	}
	else
	{
		cout << "list is not full" << endl;
	}

	cout << endl;

	cout << "insert tests" << endl;
	cout << "--------------------" << endl;

	if (intList.insert(5))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to insert the value 5" << endl;
	}

	if (intList.insert(20))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to insert the value 20" << endl; 
	}


	if (intList.insert(1))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to insert the value 1" << endl;
	}

	if (intList.insert(7))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to insert the value 7" << endl;
	}

	if (intList.insert(6))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to insert the value 6" << endl;
	}

	if (intList.insert(21))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to insert the value 21" << endl;
	}

	if (intList.isEmpty())
	{
		cout << "list is empty" << endl;
	}
	else
	{
		cout << "list is not empty" << endl;
	}

	if (intList.isFull())
	{
		cout << "list is full" << endl;
	}
	else
	{
		cout << "list is not full" << endl;
	}

	cout << endl;

	cout << "retrieve tests" << endl;
	cout << "--------------------" << endl;

	if (intList.viewFront(retrieveFront))
	{
		cout << "the front value is " << retrieveFront;
		cout << endl;
	}
	else
	{
		cout << "unable to retrieve the front value" << endl;
	}

	if (intList.viewRear(retrieveLast))
	{
		cout << "the last value is " << retrieveLast;
		cout << endl;
	}
	else
	{
		cout << "unable to retrieve the last value" << endl;
	}

	if (intList.retrieve(retrieve7))
	{
		cout << retrieve7 << endl;
	}
	else
	{
		cout << "unable to retrieve the value 7" << endl;
	}

	if (intList.retrieve(retrieve0))
	{
		cout << retrieve0 << endl;
	}
	else
	{
		cout << "unable to retrieve the value 0" << endl;
	}

	if (intList.retrieve(retrieve22))
	{
		cout << retrieve22 << endl;
	}
	else
	{
		cout << "unable to retrieve the value 22" << endl;
	}

	if (intList.retrieve(retrieve8))
	{
		cout << retrieve8 << endl;
	}
	else
	{
		cout << "unable to retrieve the value 8" << endl;
	}

	cout << endl;

	cout << "remove tests" << endl;
	cout << "--------------------" << endl;

	if (intList.remove(remove0))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to remove the value 0" << endl;
	}

	if (intList.remove(remove22))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to remove the value 22" << endl;
	}

	if (intList.remove(remove8))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to remove the value 8" << endl;
	}

	if (intList.remove(remove1))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to remove the value 1" << endl;
	}

	if (intList.remove(remove21))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to remove the value 21" << endl;
	}
	
	if (intList.remove(remove7))
	{
		intList.display();
		cout << endl;
	}
	else
	{
		cout << "unable to remove the value 7" << endl;
	}

	return 0;
}

//*****************************************************************************************************

//empty list tests
//--------------------
//unable to retrieve the front value
//unable to retrieve the last value
//unable to retrieve the value 7
//unable to remove the value 1
//list is empty
//list is not full
//
//insert tests
//--------------------
//5
//5 20
//1 5 20
//1 5 7 20
//1 5 6 7 20
//1 5 6 7 20 21
//list is not empty
//list is not full
//
//retrieve tests
//--------------------
//the front value is 1
//the last value is 21
//7
//unable to retrieve the value 0
//unable to retrieve the value 22
//unable to retrieve the value 8
//
//remove tests
//--------------------
//unable to remove the value 0
//unable to remove the value 22
//unable to remove the value 8
//5 6 7 20 21
//5 6 7 20
//5 6 20



