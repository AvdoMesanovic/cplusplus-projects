//*****************************************************************************************************
//
//		File:					stackDriver.cpp
//
//		Student:				Avdo Mesanovic
//
//		Assignment:				Program #7
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3050-01
//
//		Due:					March 31st, 2023
//
//
//		This program explores the Stack data structure and utilizes several functions to employ it.
//	
//		Other files required: 
//			1.	stack.h - definition of the Stack class
//			
//*****************************************************************************************************

#include <iostream>
using namespace std;
#include "stack.h"

//*****************************************************************************************************

int main()
{
	int popped,
		peeked;

	Stack<int> intStack(3);

	cout << "empty stack tests" << endl;
	cout << "--------------------" << endl;

	if (intStack.isEmpty())
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		cout << "stack is not empty" << endl;
	}

	if (intStack.isFull())
	{
		cout << "stack is full" << endl;
	}
	else
	{
		cout << "stack is not full" << endl;
	}

	cout << "numValues is " << intStack.getNumValues() << endl;

	if (intStack.pop(popped))
	{
		cout << "popped value is " << popped << " and numValues is " 
			 << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to pop the top value" << endl;
	}

	if (intStack.peek(peeked))
	{
		cout << "top value is " << peeked << " and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to peek at the top value" << endl;
	}

	cout << endl;

	cout << "push/peek tests" << endl;
	cout << "--------------------" << endl;

	if (intStack.push(5))
	{
		cout << "5 has been pushed and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to push the value 5" << endl;
	}

	if (intStack.peek(peeked))
	{
		cout << "top value is " << peeked << " and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to peek at the top value" << endl;
	}

	if (intStack.push(9))
	{
		cout << "9 has been pushed and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to push the value 9" << endl;
	}

	if (intStack.peek(peeked))
	{
		cout << "top value is " << peeked << " and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to peek at the top value" << endl;
	}

	if (intStack.push(20))
	{
		cout << "20 has been pushed and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to push the value 20" << endl;
	}

	if (intStack.peek(peeked))
	{
		cout << "top value is " << peeked << " and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to peek at the top value" << endl;
	}


	if (intStack.push(16))
	{
		cout << "16 has been pushed and numValues is " << intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to push the value 16" << endl;
	}
	
	cout << endl;

	cout << "full stack tests" << endl;
	cout << "--------------------" << endl;

	if (intStack.isEmpty())
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		cout << "stack is not empty" << endl;
	}

	if (intStack.isFull())
	{
		cout << "stack is full" << endl;
	}
	else
	{
		cout << "stack is not full" << endl;
	}

	cout << endl;

	cout << "pop tests" << endl;
	cout << "--------------------" << endl;

	if (intStack.pop(popped))
	{
		cout << "popped value is " << popped << " and numValues is "
			<< intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to pop the top value" << endl;
	}

	if (intStack.pop(popped))
	{
		cout << "popped value is " << popped << " and numValues is "
			<< intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to pop the top value" << endl;
	}

	if (intStack.pop(popped))
	{
		cout << "popped value is " << popped << " and numValues is "
			<< intStack.getNumValues() << endl;
	}
	else
	{
		cout << "unable to pop the top value" << endl;
	}

	return 0;
}

//*****************************************************************************************************

//empty stack tests
//--------------------
//stack is empty
//stack is not full
//numValues is 0
//unable to pop the top value
//unable to peek at the top value
//
//push/peek tests
//--------------------
//5 has been pushed and numValues is 1
//top value is 5 and numValues is 1
//9 has been pushed and numValues is 2
//top value is 9 and numValues is 2
//20 has been pushed and numValues is 3
//top value is 20 and numValues is 3
//unable to push the value 16
//
//full stack tests
//--------------------
//stack is not empty
//stack is full
//
//pop tests
//--------------------
//popped value is 20 and numValues is 2
//popped value is 9 and numValues is 1
//popped value is 5 and numValues is 0

